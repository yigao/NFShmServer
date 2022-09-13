// -------------------------------------------------------------------------
//    @FileName         :    NFSignalHandleMgr.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#include "NFSignalHandleMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFCPluginManager.h"
#include <signal.h>
#include <time.h>
#include <algorithm>
#include <string.h>

#include "demangle.h"

#if NF_PLATFORM != NF_PLATFORM_WIN

#include <ucontext.h>
#include <sys/ucontext.h>
#include <execinfo.h>
#include <error.h>
#include <dlfcn.h>
#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <limits>

#include <link.h>  // For ElfW() macro.

// We don't use assert() since it's not guaranteed to be
// async-signal-safe.  Instead we define a minimal assertion
// macro. So far, we don't need pretty printing for __FILE__, etc.

// A wrapper for abort() to make it callable in ? :.
static int AssertFail() {
  abort();
  return 0;  // Should not reach.
}

#define SAFE_ASSERT(expr) ((expr) ? 0 : AssertFail())

// Re-runs fn until it doesn't cause EINTR.
#define NO_INTR(fn)   do {} while ((fn) < 0 && errno == EINTR)

// Restrictions on the callbacks that follow:
//  - The callbacks must not use heaps but only use stacks.
//  - The callbacks must be async-signal-safe.

// Installs a callback function, which will be called right before a symbol name
// is printed. The callback is intended to be used for showing a file name and a
// line number preceding a symbol name.
// "fd" is a file descriptor of the object file containing the program
// counter "pc". The callback function should write output to "out"
// and return the size of the output written. On error, the callback
// function should return -1.
typedef int (*SymbolizeCallback)(int fd, void *pc, char *out, size_t out_size,
                                 uint64_t relocation);
void InstallSymbolizeCallback(SymbolizeCallback callback);

// Installs a callback function, which will be called instead of
// OpenObjectFileContainingPcAndGetStartAddress.  The callback is expected
// to searches for the object file (from /proc/self/maps) that contains
// the specified pc.  If found, sets |start_address| to the start address
// of where this object file is mapped in memory, sets the module base
// address into |base_address|, copies the object file name into
// |out_file_name|, and attempts to open the object file.  If the object
// file is opened successfully, returns the file descriptor.  Otherwise,
// returns -1.  |out_file_name_size| is the size of the file name buffer
// (including the null-terminator).
typedef int (*SymbolizeOpenObjectFileCallback)(uint64_t pc,
                                               uint64_t &start_address,
                                               uint64_t &base_address,
                                               char *out_file_name,
                                               int out_file_name_size);
void InstallSymbolizeOpenObjectFileCallback(
    SymbolizeOpenObjectFileCallback callback);

static SymbolizeCallback g_symbolize_callback = NULL;
void InstallSymbolizeCallback(SymbolizeCallback callback) {
  g_symbolize_callback = callback;
}

static SymbolizeOpenObjectFileCallback g_symbolize_open_object_file_callback =
    NULL;
void InstallSymbolizeOpenObjectFileCallback(
    SymbolizeOpenObjectFileCallback callback) {
  g_symbolize_open_object_file_callback = callback;
}

// This function wraps the Demangle function to provide an interface
// where the input symbol is demangled in-place.
// To keep stack consumption low, we would like this function to not
// get inlined.
static void DemangleInplace(char *out, int out_size) {
  char demangled[256];  // Big enough for sane demangled symbols.
  if (Demangle(out, demangled, sizeof(demangled))) {
    // Demangling succeeded. Copy to out if the space allows.
    size_t len = strlen(demangled);
    if (len + 1 <= (size_t)out_size) {  // +1 for '\0'.
      SAFE_ASSERT(len < sizeof(demangled));
      memmove(out, demangled, len + 1);
    }
  }
}

// Read up to "count" bytes from file descriptor "fd" into the buffer
// starting at "buf" while handling short reads and EINTR.  On
// success, return the number of bytes read.  Otherwise, return -1.
static ssize_t ReadPersistent(const int fd, void *buf, const size_t count) {
  SAFE_ASSERT(fd >= 0);
  SAFE_ASSERT(count <= std::numeric_limits<ssize_t>::max());
  char *buf0 = reinterpret_cast<char *>(buf);
  ssize_t num_bytes = 0;
  while (num_bytes < (ssize_t)count) {
    ssize_t len;
    NO_INTR(len = read(fd, buf0 + num_bytes, count - num_bytes));
    if (len < 0) {  // There was an error other than EINTR.
      return -1;
    }
    if (len == 0) {  // Reached EOF.
      break;
    }
    num_bytes += len;
  }
  SAFE_ASSERT(num_bytes <= (ssize_t)count);
  return num_bytes;
}

// Read up to "count" bytes from "offset" in the file pointed by file
// descriptor "fd" into the buffer starting at "buf".  On success,
// return the number of bytes read.  Otherwise, return -1.
static ssize_t ReadFromOffset(const int fd, void *buf,
                              const size_t count, const off_t offset) {
  off_t off = lseek(fd, offset, SEEK_SET);
  if (off == (off_t)-1) {
    return -1;
  }
  return ReadPersistent(fd, buf, count);
}

// Try reading exactly "count" bytes from "offset" bytes in a file
// pointed by "fd" into the buffer starting at "buf" while handling
// short reads and EINTR.  On success, return true. Otherwise, return
// false.
static bool ReadFromOffsetExact(const int fd, void *buf,
                                const size_t count, const off_t offset) {
  ssize_t len = ReadFromOffset(fd, buf, count, offset);
  return len == (ssize_t)count;
}

// Returns elf_header.e_type if the file pointed by fd is an ELF binary.
static int FileGetElfType(const int fd) {
  ElfW(Ehdr) elf_header;
  if (!ReadFromOffsetExact(fd, &elf_header, sizeof(elf_header), 0)) {
    return -1;
  }
  if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
    return -1;
  }
  return elf_header.e_type;
}

// Read the section headers in the given ELF binary, and if a section
// of the specified type is found, set the output to this section header
// and return true.  Otherwise, return false.
// To keep stack consumption low, we would like this function to not get
// inlined.
static bool
GetSectionHeaderByType(const int fd, ElfW(Half) sh_num, const off_t sh_offset,
                       ElfW(Word) type, ElfW(Shdr) *out) {
  // Read at most 16 section headers at a time to save read calls.
  ElfW(Shdr) buf[16];
  for (int i = 0; i < sh_num;) {
    const ssize_t num_bytes_left = (sh_num - i) * sizeof(buf[0]);
    const ssize_t num_bytes_to_read =
        ((ssize_t)sizeof(buf) > num_bytes_left) ? num_bytes_left : sizeof(buf);
    const ssize_t len = ReadFromOffset(fd, buf, num_bytes_to_read,
                                       sh_offset + i * sizeof(buf[0]));
    SAFE_ASSERT(len % sizeof(buf[0]) == 0);
    const ssize_t num_headers_in_buf = len / sizeof(buf[0]);
    SAFE_ASSERT(num_headers_in_buf <= (ssize_t)sizeof(buf) / (ssize_t)sizeof(buf[0]));
    for (int j = 0; j < num_headers_in_buf; ++j) {
      if (buf[j].sh_type == type) {
        *out = buf[j];
        return true;
      }
    }
    i += num_headers_in_buf;
  }
  return false;
}

// There is no particular reason to limit section name to 63 characters,
// but there has (as yet) been no need for anything longer either.
const int kMaxSectionNameLen = 64;

// name_len should include terminating '\0'.
bool GetSectionHeaderByName(int fd, const char *name, size_t name_len,
                            ElfW(Shdr) *out) {
  ElfW(Ehdr) elf_header;
  if (!ReadFromOffsetExact(fd, &elf_header, sizeof(elf_header), 0)) {
    return false;
  }

  ElfW(Shdr) shstrtab;
  off_t shstrtab_offset = (elf_header.e_shoff +
                           elf_header.e_shentsize * elf_header.e_shstrndx);
  if (!ReadFromOffsetExact(fd, &shstrtab, sizeof(shstrtab), shstrtab_offset)) {
    return false;
  }

  for (int i = 0; i < elf_header.e_shnum; ++i) {
    off_t section_header_offset = (elf_header.e_shoff +
                                   elf_header.e_shentsize * i);
    if (!ReadFromOffsetExact(fd, out, sizeof(*out), section_header_offset)) {
      return false;
    }
    char header_name[kMaxSectionNameLen];
    if (sizeof(header_name) < name_len) {
      //NFLogError(NF_LOG_SYSTEMLOG, 0, "Section name '%s' is too long (%" PRIuS "); "
      //        "section will not be found (even if present).", name, name_len);
      // No point in even trying.
      return false;
    }
    off_t name_offset = shstrtab.sh_offset + out->sh_name;
    ssize_t n_read = ReadFromOffset(fd, &header_name, name_len, name_offset);
    if (n_read == -1) {
      return false;
    } else if (n_read != (ssize_t)name_len) {
      // Short read -- name could be at end of file.
      continue;
    }
    if (memcmp(header_name, name, name_len) == 0) {
      return true;
    }
  }
  return false;
}

// Read a symbol table and look for the symbol containing the
// pc. Iterate over symbols in a symbol table and look for the symbol
// containing "pc".  On success, return true and write the symbol name
// to out.  Otherwise, return false.
// To keep stack consumption low, we would like this function to not get
// inlined.
static bool
FindSymbol(uint64_t pc, const int fd, char *out, int out_size,
           uint64_t symbol_offset, const ElfW(Shdr) *strtab,
           const ElfW(Shdr) *symtab) {
  if (symtab == NULL) {
    return false;
  }
  const int num_symbols = symtab->sh_size / symtab->sh_entsize;
  for (int i = 0; i < num_symbols;) {
    off_t offset = symtab->sh_offset + i * symtab->sh_entsize;

    // If we are reading Elf64_Sym's, we want to limit this array to
    // 32 elements (to keep stack consumption low), otherwise we can
    // have a 64 element Elf32_Sym array.
#if __WORDSIZE == 64
#define NUM_SYMBOLS 32
#else
#define NUM_SYMBOLS 64
#endif

    // Read at most NUM_SYMBOLS symbols at once to save read() calls.
    ElfW(Sym) buf[NUM_SYMBOLS];
    const ssize_t len = ReadFromOffset(fd, &buf, sizeof(buf), offset);
    SAFE_ASSERT(len % sizeof(buf[0]) == 0);
    const ssize_t num_symbols_in_buf = len / sizeof(buf[0]);
    SAFE_ASSERT(num_symbols_in_buf <= (ssize_t)sizeof(buf)/(ssize_t)sizeof(buf[0]));
    for (int j = 0; j < num_symbols_in_buf; ++j) {
      const ElfW(Sym)& symbol = buf[j];
      uint64_t start_address = symbol.st_value;
      start_address += symbol_offset;
      uint64_t end_address = start_address + symbol.st_size;
      if (symbol.st_value != 0 &&  // Skip null value symbols.
          symbol.st_shndx != 0 &&  // Skip undefined symbols.
          start_address <= pc && pc < end_address) {
        ssize_t len1 = ReadFromOffset(fd, out, out_size,
                                      strtab->sh_offset + symbol.st_name);
        if (len1 <= 0 || memchr(out, '\0', out_size) == NULL) {
          return false;
        }
        return true;  // Obtained the symbol name.
      }
    }
    i += num_symbols_in_buf;
  }
  return false;
}

// Get the symbol name of "pc" from the file pointed by "fd".  Process
// both regular and dynamic symbol tables if necessary.  On success,
// write the symbol name to "out" and return true.  Otherwise, return
// false.
static bool GetSymbolFromObjectFile(const int fd, uint64_t pc,
                                    char *out, int out_size,
                                    uint64_t map_base_address) {
  // Read the ELF header.
  ElfW(Ehdr) elf_header;
  if (!ReadFromOffsetExact(fd, &elf_header, sizeof(elf_header), 0)) {
    return false;
  }

  uint64_t symbol_offset = 0;
  if (elf_header.e_type == ET_DYN) {  // DSO needs offset adjustment.
    ElfW(Phdr) phdr;
    // We need to find the PT_LOAD segment corresponding to the read-execute
    // file mapping in order to correctly perform the offset adjustment.
    for (unsigned i = 0; i != elf_header.e_phnum; ++i) {
      if (!ReadFromOffsetExact(fd, &phdr, sizeof(phdr),
                               elf_header.e_phoff + i * sizeof(phdr)))
        return false;
      if (phdr.p_type == PT_LOAD &&
          (phdr.p_flags & (PF_R | PF_X)) == (PF_R | PF_X)) {
        // Find the mapped address corresponding to virtual address zero. We do
        // this by first adding p_offset. This gives us the mapped address of
        // the start of the segment, or in other words the mapped address
        // corresponding to the virtual address of the segment. (Note that this
        // is distinct from the start address, as p_offset is not guaranteed to
        // be page aligned.) We then subtract p_vaddr, which takes us to virtual
        // address zero.
        symbol_offset = map_base_address + phdr.p_offset - phdr.p_vaddr;
        break;
      }
    }
    if (symbol_offset == 0)
      return false;
  }

  ElfW(Shdr) symtab, strtab;

  // Consult a regular symbol table first.
  if (GetSectionHeaderByType(fd, elf_header.e_shnum, elf_header.e_shoff,
                             SHT_SYMTAB, &symtab)) {
    if (!ReadFromOffsetExact(fd, &strtab, sizeof(strtab), elf_header.e_shoff +
                             symtab.sh_link * sizeof(symtab))) {
      return false;
    }
    if (FindSymbol(pc, fd, out, out_size, symbol_offset,
                   &strtab, &symtab)) {
      return true;  // Found the symbol in a regular symbol table.
    }
  }

  // If the symbol is not found, then consult a dynamic symbol table.
  if (GetSectionHeaderByType(fd, elf_header.e_shnum, elf_header.e_shoff,
                             SHT_DYNSYM, &symtab)) {
    if (!ReadFromOffsetExact(fd, &strtab, sizeof(strtab), elf_header.e_shoff +
                             symtab.sh_link * sizeof(symtab))) {
      return false;
    }
    if (FindSymbol(pc, fd, out, out_size, symbol_offset,
                   &strtab, &symtab)) {
      return true;  // Found the symbol in a dynamic symbol table.
    }
  }

  return false;
}

namespace {
// Thin wrapper around a file descriptor so that the file descriptor
// gets closed for sure.
struct FileDescriptor {
  const int fd_;
  explicit FileDescriptor(int fd) : fd_(fd) {}
  ~FileDescriptor() {
    if (fd_ >= 0) {
      NO_INTR(close(fd_));
    }
  }
  int get() { return fd_; }

 private:
  explicit FileDescriptor(const FileDescriptor&);
  void operator=(const FileDescriptor&);
};

// Helper class for reading lines from file.
//
// Note: we don't use ProcMapsIterator since the object is big (it has
// a 5k array member) and uses async-unsafe functions such as sscanf()
// and snprintf().
class LineReader {
 public:
  explicit LineReader(int fd, char *buf, int buf_len) : fd_(fd),
    buf_(buf), buf_len_(buf_len), bol_(buf), eol_(buf), eod_(buf) {
  }

  // Read '\n'-terminated line from file.  On success, modify "bol"
  // and "eol", then return true.  Otherwise, return false.
  //
  // Note: if the last line doesn't end with '\n', the line will be
  // dropped.  It's an intentional behavior to make the code simple.
  bool ReadLine(const char **bol, const char **eol) {
    if (BufferIsEmpty()) {  // First time.
      const ssize_t num_bytes = ReadPersistent(fd_, buf_, buf_len_);
      if (num_bytes <= 0) {  // EOF or error.
        return false;
      }
      eod_ = buf_ + num_bytes;
      bol_ = buf_;
    } else {
      bol_ = eol_ + 1;  // Advance to the next line in the buffer.
      SAFE_ASSERT(bol_ <= eod_);  // "bol_" can point to "eod_".
      if (!HasCompleteLine()) {
        const int incomplete_line_length = eod_ - bol_;
        // Move the trailing incomplete line to the beginning.
        memmove(buf_, bol_, incomplete_line_length);
        // Read text from file and append it.
        char * const append_pos = buf_ + incomplete_line_length;
        const int capacity_left = buf_len_ - incomplete_line_length;
        const ssize_t num_bytes = ReadPersistent(fd_, append_pos,
                                                 capacity_left);
        if (num_bytes <= 0) {  // EOF or error.
          return false;
        }
        eod_ = append_pos + num_bytes;
        bol_ = buf_;
      }
    }
    eol_ = FindLineFeed();
    if (eol_ == NULL) {  // '\n' not found.  Malformed line.
      return false;
    }
    *eol_ = '\0';  // Replace '\n' with '\0'.

    *bol = bol_;
    *eol = eol_;
    return true;
  }

  // Beginning of line.
  const char *bol() {
    return bol_;
  }

  // End of line.
  const char *eol() {
    return eol_;
  }

 private:
  explicit LineReader(const LineReader&);
  void operator=(const LineReader&);

  char *FindLineFeed() {
    return reinterpret_cast<char *>(memchr(bol_, '\n', eod_ - bol_));
  }

  bool BufferIsEmpty() {
    return buf_ == eod_;
  }

  bool HasCompleteLine() {
    return !BufferIsEmpty() && FindLineFeed() != NULL;
  }

  const int fd_;
  char * const buf_;
  const int buf_len_;
  char *bol_;
  char *eol_;
  const char *eod_;  // End of data in "buf_".
};
}  // namespace

// Place the hex number read from "start" into "*hex".  The pointer to
// the first non-hex character or "end" is returned.
static char *GetHex(const char *start, const char *end, uint64_t *hex) {
  *hex = 0;
  const char *p;
  for (p = start; p < end; ++p) {
    int ch = *p;
    if ((ch >= '0' && ch <= '9') ||
        (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {
      *hex = (*hex << 4) | (ch < 'A' ? ch - '0' : (ch & 0xF) + 9);
    } else {  // Encountered the first non-hex character.
      break;
    }
  }
  NF_ASSERT(p <= end);
  return const_cast<char *>(p);
}

// Searches for the object file (from /proc/self/maps) that contains
// the specified pc.  If found, sets |start_address| to the start address
// of where this object file is mapped in memory, sets the module base
// address into |base_address|, copies the object file name into
// |out_file_name|, and attempts to open the object file.  If the object
// file is opened successfully, returns the file descriptor.  Otherwise,
// returns -1.  |out_file_name_size| is the size of the file name buffer
// (including the null-terminator).
static int
OpenObjectFileContainingPcAndGetStartAddress(uint64_t pc,
                                             uint64_t &start_address,
                                             uint64_t &base_address,
                                             char *out_file_name,
                                             int out_file_name_size) {
  int object_fd;

  // Open /proc/self/maps.
  int maps_fd;
  NO_INTR(maps_fd = open("/proc/self/maps", O_RDONLY));
  FileDescriptor wrapped_maps_fd(maps_fd);
  if (wrapped_maps_fd.get() < 0) {
    return -1;
  }

  // Iterate over maps and look for the map containing the pc.  Then
  // look into the symbol tables inside.
  char buf[1024];  // Big enough for line of sane /proc/self/maps
  int num_maps = 0;
  LineReader reader(wrapped_maps_fd.get(), buf, sizeof(buf));
  while (true) {
    num_maps++;
    const char *cursor;
    const char *eol;
    if (!reader.ReadLine(&cursor, &eol)) {  // EOF or malformed line.
      return -1;
    }

    // Start parsing line in /proc/self/maps.  Here is an example:
    //
    // 08048000-0804c000 r-xp 00000000 08:01 2142121    /bin/cat
    //
    // We want start address (08048000), end address (0804c000), flags
    // (r-xp) and file name (/bin/cat).

    // Read start address.
    cursor = GetHex(cursor, eol, &start_address);
    if (cursor == eol || *cursor != '-') {
      return -1;  // Malformed line.
    }
    ++cursor;  // Skip '-'.

    // Read end address.
    uint64_t end_address;
    cursor = GetHex(cursor, eol, &end_address);
    if (cursor == eol || *cursor != ' ') {
      return -1;  // Malformed line.
    }
    ++cursor;  // Skip ' '.

    // Check start and end addresses.
    if (!(start_address <= pc && pc < end_address)) {
      continue;  // We skip this map.  PC isn't in this map.
    }

    // Read flags.  Skip flags until we encounter a space or eol.
    const char * const flags_start = cursor;
    while (cursor < eol && *cursor != ' ') {
      ++cursor;
    }
    // We expect at least four letters for flags (ex. "r-xp").
    if (cursor == eol || cursor < flags_start + 4) {
      return -1;  // Malformed line.
    }

   // Check flags.  We are only interested in "r*x" maps.
    if (flags_start[0] != 'r' || flags_start[2] != 'x') {
      continue;  // We skip this map.
    }
    ++cursor;  // Skip ' '.

    // Read file offset.
    uint64_t file_offset;
    cursor = GetHex(cursor, eol, &file_offset);
    if (cursor == eol || *cursor != ' ') {
      return -1;  // Malformed line.
    }
    ++cursor;  // Skip ' '.

    // Don't subtract 'start_address' from the first entry:
    // * If a binary is compiled w/o -pie, then the first entry in
    //   process maps is likely the binary itself (all dynamic libs
    //   are mapped higher in address space). For such a binary,
    //   instruction offset in binary coincides with the actual
    //   instruction address in virtual memory (as code section
    //   is mapped to a fixed memory range).
    // * If a binary is compiled with -pie, all the modules are
    //   mapped high at address space (in particular, higher than
    //   shadow memory of the tool), so the module can't be the
    //   first entry.
    base_address = ((num_maps == 1) ? 0U : start_address) - file_offset;

    // Skip to file name.  "cursor" now points to dev.  We need to
    // skip at least two spaces for dev and inode.
    int num_spaces = 0;
    while (cursor < eol) {
      if (*cursor == ' ') {
        ++num_spaces;
      } else if (num_spaces >= 2) {
        // The first non-space character after skipping two spaces
        // is the beginning of the file name.
        break;
      }
      ++cursor;
    }
    if (cursor == eol) {
      return -1;  // Malformed line.
    }

    // Finally, "cursor" now points to file name of our interest.
    NO_INTR(object_fd = open(cursor, O_RDONLY));
    if (object_fd < 0) {
      // Failed to open object file.  Copy the object file name to
      // |out_file_name|.
      strncpy(out_file_name, cursor, out_file_name_size);
      // Making sure |out_file_name| is always null-terminated.
      out_file_name[out_file_name_size - 1] = '\0';
      return -1;
    }
    return object_fd;
  }
}

// POSIX doesn't define any async-signal safe function for converting
// an integer to ASCII. We'll have to define our own version.
// itoa_r() converts a (signed) integer to ASCII. It returns "buf", if the
// conversion was successful or NULL otherwise. It never writes more than "sz"
// bytes. Output will be truncated as needed, and a NUL character is always
// appended.
// NOTE: code from sandbox/linux/seccomp-bpf/demo.cc.
char *itoa_r(intptr_t i, char *buf, size_t sz, int base, size_t padding) {
  // Make sure we can write at least one NUL byte.
  size_t n = 1;
  if (n > sz)
    return NULL;

  if (base < 2 || base > 16) {
    buf[0] = '\000';
    return NULL;
  }

  char *start = buf;

  uintptr_t j = i;

  // Handle negative numbers (only for base 10).
  if (i < 0 && base == 10) {
    j = -i;

    // Make sure we can write the '-' character.
    if (++n > sz) {
      buf[0] = '\000';
      return NULL;
    }
    *start++ = '-';
  }

  // Loop until we have converted the entire number. Output at least one
  // character (i.e. '0').
  char *ptr = start;
  do {
    // Make sure there is still enough space left in our output buffer.
    if (++n > sz) {
      buf[0] = '\000';
      return NULL;
    }

    // Output the next digit.
    *ptr++ = "0123456789abcdef"[j % base];
    j /= base;

    if (padding > 0)
      padding--;
  } while (j > 0 || padding > 0);

  // Terminate the output with a NUL character.
  *ptr = '\000';

  // Conversion to ASCII actually resulted in the digits being in reverse
  // order. We can't easily generate them in forward order, as we can't tell
  // the number of characters needed until we are done converting.
  // So, now, we reverse the string (except for the possible "-" sign).
  while (--ptr > start) {
    char ch = *ptr;
    *ptr = *start;
    *start++ = ch;
  }
  return buf;
}

// Safely appends string |source| to string |dest|.  Never writes past the
// buffer size |dest_size| and guarantees that |dest| is null-terminated.
void SafeAppendString(const char* source, char* dest, int dest_size) {
  int dest_string_length = strlen(dest);
  NF_ASSERT(dest_string_length < dest_size);
  dest += dest_string_length;
  dest_size -= dest_string_length;
  strncpy(dest, source, dest_size);
  // Making sure |dest| is always null-terminated.
  dest[dest_size - 1] = '\0';
}

// Converts a 64-bit value into a hex string, and safely appends it to |dest|.
// Never writes past the buffer size |dest_size| and guarantees that |dest| is
// null-terminated.
void SafeAppendHexNumber(uint64_t value, char* dest, int dest_size) {
  // 64-bit numbers in hex can have up to 16 digits.
  char buf[17] = {'\0'};
  SafeAppendString(itoa_r(value, buf, sizeof(buf), 16, 0), dest, dest_size);
}

// The implementation of our symbolization routine.  If it
// successfully finds the symbol containing "pc" and obtains the
// symbol name, returns true and write the symbol name to "out".
// Otherwise, returns false. If Callback function is installed via
// InstallSymbolizeCallback(), the function is also called in this function,
// and "out" is used as its output.
// To keep stack consumption low, we would like this function to not
// get inlined.
static bool SymbolizeAndDemangle(void *pc, char *out,
                                                    int out_size) {
  uint64_t pc0 = reinterpret_cast<uintptr_t>(pc);
  uint64_t start_address = 0;
  uint64_t base_address = 0;
  int object_fd = -1;

  if (out_size < 1) {
    return false;
  }
  out[0] = '\0';
  SafeAppendString("(", out, out_size);

  if (g_symbolize_open_object_file_callback) {
    object_fd = g_symbolize_open_object_file_callback(pc0, start_address,
                                                      base_address, out + 1,
                                                      out_size - 1);
  } else {
    object_fd = OpenObjectFileContainingPcAndGetStartAddress(pc0, start_address,
                                                             base_address,
                                                             out + 1,
                                                             out_size - 1);
  }

  // Check whether a file name was returned.
  if (object_fd < 0) {
    if (out[1]) {
      // The object file containing PC was determined successfully however the
      // object file was not opened successfully.  This is still considered
      // success because the object file name and offset are known and tools
      // like asan_symbolize.py can be used for the symbolization.
      out[out_size - 1] = '\0';  // Making sure |out| is always null-terminated.
      SafeAppendString("+0x", out, out_size);
      SafeAppendHexNumber(pc0 - base_address, out, out_size);
      SafeAppendString(")", out, out_size);
      return true;
    }
    // Failed to determine the object file containing PC.  Bail out.
    return false;
  }
  FileDescriptor wrapped_object_fd(object_fd);
  int elf_type = FileGetElfType(wrapped_object_fd.get());
  if (elf_type == -1) {
    return false;
  }
  if (g_symbolize_callback) {
    // Run the call back if it's installed.
    // Note: relocation (and much of the rest of this code) will be
    // wrong for prelinked shared libraries and PIE executables.
    uint64_t relocation = (elf_type == ET_DYN) ? start_address : 0;
    int num_bytes_written = g_symbolize_callback(wrapped_object_fd.get(),
                                                 pc, out, out_size,
                                                 relocation);
    if (num_bytes_written > 0) {
      out += num_bytes_written;
      out_size -= num_bytes_written;
    }
  }
  if (!GetSymbolFromObjectFile(wrapped_object_fd.get(), pc0,
                               out, out_size, base_address)) {
    return false;
  }

  // Symbolization succeeded.  Now we try to demangle the symbol.
  DemangleInplace(out, out_size);
  return true;
}

bool Symbolize(void *pc, char *out, int out_size) {
  NF_ASSERT(out_size >= 0);
  return SymbolizeAndDemangle(pc, out, out_size);
}

const struct {
	int number;
	const char *name;
} kFailureSignals[] = {
	{ SIGSEGV, "SIGSEGV" },
	{ SIGILL, "SIGILL" },
	{ SIGFPE, "SIGFPE" },
	{ SIGABRT, "SIGABRT" },
	{ SIGBUS, "SIGBUS" },
	{ SIGTERM, "SIGTERM" },
	{ SIGUSR1, "SIGUSR1" },
	{ SIGUSR2, "SIGUSR2" },
	{ SIGKILL, "SIGKILL" },
	{ SIGINT, "SIGINT" },
	{ SIGQUIT, "SIGQUIT"},
	{ SIGHUP, "SIGHUP"},
	{ SIGUNUSED, "SIGUNUSED"},
};

// Returns the program counter from signal context, NULL if unknown.
void* GetPC(void* ucontext_in_void) {
  if (ucontext_in_void != NULL) {
    ucontext_t *context = reinterpret_cast<ucontext_t *>(ucontext_in_void);
    return (void*)context->uc_link;
  }
  return NULL;
}

// If you change this function, also change GetStackFrames below.
int GetStackTrace(void** result, int max_depth, int skip_count) {
	static const int kStackLength = 64;
	void * stack[kStackLength];
	int size;

	size = backtrace(stack, kStackLength);
	skip_count++;  // we want to skip the current frame as well
	int result_count = size - skip_count;
	if (result_count < 0)
		result_count = 0;
	if (result_count > max_depth)
		result_count = max_depth;
	for (int i = 0; i < result_count; i++)
		result[i] = stack[i + skip_count];

	return result_count;
}

// The class is used for formatting error messages.  We don't use printf()
// as it's not async signal safe.
class MinimalFormatter {
 public:
  MinimalFormatter(char *buffer, int size)
      : buffer_(buffer),
        cursor_(buffer),
        end_(buffer + size) {
  }

  // Returns the number of bytes written in the buffer.
  int num_bytes_written() const { return cursor_ - buffer_; }

  // Appends string from "str" and updates the internal cursor.
  void AppendString(const char* str) {
    int i = 0;
    while (str[i] != '\0' && cursor_ + i < end_) {
      cursor_[i] = str[i];
      ++i;
    }
    cursor_ += i;
  }

  // Formats "number" in "radix" and updates the internal cursor.
  // Lowercase letters are used for 'a' - 'z'.
  void AppendUint64(uint64_t number, int radix) {
    int i = 0;
    while (cursor_ + i < end_) {
      const int tmp = number % radix;
      number /= radix;
      cursor_[i] = (tmp < 10 ? '0' + tmp : 'a' + tmp - 10);
      ++i;
      if (number == 0) {
        break;
      }
    }
    // Reverse the bytes written.
    std::reverse(cursor_, cursor_ + i);
    cursor_ += i;
  }

  // Formats "number" as hexadecimal number, and updates the internal
  // cursor.  Padding will be added in front if needed.
  void AppendHexWithPadding(uint64_t number, int width) {
    char* start = cursor_;
    AppendString("0x");
    AppendUint64(number, 16);
    // Move to right and add padding in front if needed.
    if (cursor_ < start + width) {
      const int64_t delta = start + width - cursor_;
      std::copy(start, cursor_, start + delta);
      std::fill(start, start + delta, ' ');
      cursor_ = start + width;
    }
  }

 private:
  char *buffer_;
  char *cursor_;
  const char * const end_;
};

// Dumps time information.  We don't dump human-readable time information
// as localtime() is not guaranteed to be async signal safe.
std::string DumpTimeInfo() {
  time_t time_in_sec = time(NULL);
  char buf[256];  // Big enough for time info.
  MinimalFormatter formatter(buf, sizeof(buf));
  formatter.AppendString("*** Aborted at ");
  formatter.AppendUint64(time_in_sec, 10);
  formatter.AppendString(" (unix time)");
  formatter.AppendString(" try \"date -d @");
  formatter.AppendUint64(time_in_sec, 10);
  formatter.AppendString("\" if you are using GNU date ***\n");

  std::string str = std::string(buf, formatter.num_bytes_written());
  NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", str);
  return str;
}

// Dumps information about the signal to STDERR.
std::string DumpSignalInfo(int signal_number, siginfo_t *siginfo) {
  // Get the signal name.
  const char* signal_name = NULL;
  for (size_t i = 0; i < NF_ARRAYSIZE(kFailureSignals); ++i) {
    if (signal_number == kFailureSignals[i].number) {
      signal_name = kFailureSignals[i].name;
    }
  }

  char buf[256];  // Big enough for signal info.
  MinimalFormatter formatter(buf, sizeof(buf));

  formatter.AppendString("*** ");
  if (signal_name) {
    formatter.AppendString(signal_name);
  } else {
    // Use the signal number if the name is unknown.  The signal name
    // should be known, but just in case.
    formatter.AppendString("Signal ");
    formatter.AppendUint64(signal_number, 10);
  }
  formatter.AppendString(" (@0x");
  formatter.AppendUint64(reinterpret_cast<uintptr_t>(siginfo->si_addr), 16);
  formatter.AppendString(")");
  formatter.AppendString(" received by PID ");
  formatter.AppendUint64(getpid(), 10);
  formatter.AppendString(" (TID 0x");
  // We assume pthread_t is an integral number or a pointer, rather
  // than a complex struct.  In some environments, pthread_self()
  // returns an uint64 but in some other environments pthread_self()
  // returns a pointer.  Hence we use C-style cast here, rather than
  // reinterpret/static_cast, to support both types of environments.
  formatter.AppendUint64((uintptr_t)pthread_self(), 16);
  formatter.AppendString(") ");
  // Only linux has the PID of the signal sender in si_pid.
#ifdef OS_LINUX
  formatter.AppendString("from PID ");
  formatter.AppendUint64(siginfo->si_pid, 10);
  formatter.AppendString("; ");
#endif
  formatter.AppendString("stack trace: ***\n");

  std::string str = std::string(buf, formatter.num_bytes_written());
  NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", str);
  return str;
}

// Dumps information about the stack frame to STDERR.
std::string DumpStackFrameInfo(const char* prefix, void* pc) {
  // Get the symbol name.
  const char *symbol = "(unknown)";
  char symbolized[1024];  // Big enough for a sane symbol.
  // Symbolizes the previous address of pc because pc may be in the
  // next function.
  if (Symbolize(reinterpret_cast<char *>(pc) - 1,
                symbolized, sizeof(symbolized))) {
    symbol = symbolized;
  }

  char buf[1024];  // Big enough for stack frame info.
  MinimalFormatter formatter(buf, sizeof(buf));

  formatter.AppendString(prefix);
  formatter.AppendString("@ ");
  const int width = 2 * sizeof(void*) + 2;  // + 2  for "0x".
  formatter.AppendHexWithPadding(reinterpret_cast<uintptr_t>(pc), width);
  formatter.AppendString(" ");
  formatter.AppendString(symbol);
  formatter.AppendString("\n");

  std::string str = std::string(buf, formatter.num_bytes_written());
  NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", str);
  return str;
}

// Invoke the default signal handler.
void InvokeDefaultSignalHandler(int signal_number) {
  struct sigaction sig_action;
  memset(&sig_action, 0, sizeof(sig_action));
  sigemptyset(&sig_action.sa_mask);
  sig_action.sa_handler = SIG_DFL;
  sigaction(signal_number, &sig_action, NULL);
  kill(getpid(), signal_number);
}

// This variable is used for protecting FailureSignalHandler() from
// dumping stuff while another thread is doing it.  Our policy is to let
// the first thread dump stuff and let other threads wait.
// See also comments in FailureSignalHandler().
static pthread_t* g_entered_thread_id_pointer = NULL;

// Wrapper of __sync_val_compare_and_swap. If the GCC extension isn't
// defined, we try the CPU specific logics (we only support x86 and
// x86_64 for now) first, then use a naive implementation, which has a
// race condition.
template<typename T>
inline T sync_val_compare_and_swap(T* ptr, T oldval, T newval) {
#if defined(HAVE___SYNC_VAL_COMPARE_AND_SWAP)
  return __sync_val_compare_and_swap(ptr, oldval, newval);
#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
  T ret;
  __asm__ __volatile__("lock; cmpxchg %1, (%2);"
                       :"=a"(ret)
                        // GCC may produces %sil or %dil for
                        // constraint "r", but some of apple's gas
                        // dosn't know the 8 bit registers.
                        // We use "q" to avoid these registers.
                       :"q"(newval), "q"(ptr), "a"(oldval)
                       :"memory", "cc");
  return ret;
#else
  T ret = *ptr;
  if (ret == oldval) {
    *ptr = newval;
  }
  return ret;
#endif
}

// Dumps signal and stack frame information, and invokes the default
// signal handler once our job is done.
void FailureSignalHandler(int signal_number,
	siginfo_t *signal_info,
	void *ucontext) {
    //before every thing
    NFIPluginManager::Instance()->ShutDownApp();

	// First check if we've already entered the function.  We use an atomic
	// compare and swap operation for platforms that support it.  For other
	// platforms, we use a naive method that could lead to a subtle race.

	// We assume pthread_self() is async signal safe, though it's not
	// officially guaranteed.
	pthread_t my_thread_id = pthread_self();
	// NOTE: We could simply use pthread_t rather than pthread_t* for this,
	// if pthread_self() is guaranteed to return non-zero value for thread
	// ids, but there is no such guarantee.  We need to distinguish if the
	// old value (value returned from __sync_val_compare_and_swap) is
	// different from the original value (in this case NULL).
	pthread_t* old_thread_id_pointer =
		sync_val_compare_and_swap(
			&g_entered_thread_id_pointer,
			static_cast<pthread_t*>(NULL),
			&my_thread_id);
	if (old_thread_id_pointer != NULL) {
		// We've already entered the signal handler.  What should we do?
		if (pthread_equal(my_thread_id, *g_entered_thread_id_pointer)) {
			// It looks the current thread is reentering the signal handler.
			// Something must be going wrong (maybe we are reentering by another
			// type of signal?).  Kill ourself by the default signal handler.
			InvokeDefaultSignalHandler(signal_number);
		}
		// Another thread is dumping stuff.  Let's wait until that thread
		// finishes the job and kills the process.
		while (true) {
			sleep(1);
		}
	}
	// This is the first time we enter the signal handler.  We are going to
	// do some interesting stuff from here.
	// TODO(satorux): We might want to set timeout here using alarm(), but
	// mixing alarm() and sleep() can be a bad idea.

	std::string dumpInfo;
	// First dump time info.
	dumpInfo += DumpTimeInfo();
	dumpInfo += "\n";

	// Get the program counter from ucontext.
	void *pc = GetPC(ucontext);
	dumpInfo += DumpStackFrameInfo("PC: ", pc);
    dumpInfo += "\n";

	// Get the stack traces.
	void *stack[32];
	// +1 to exclude this function.
	const int depth = GetStackTrace(stack, NF_ARRAYSIZE(stack), 1);
	dumpInfo += DumpSignalInfo(signal_number, signal_info);
	dumpInfo += "\n";
	// Dump the stack traces.
	for (int i = 0; i < depth; ++i) {
		dumpInfo += DumpStackFrameInfo("    ", stack[i]);
        dumpInfo += "\n";
	}

    NFFileUtility::WriteFile(NFIPluginManager::Instance()->GetAppName()+"_"+NFIPluginManager::Instance()->GetBusName()+"_dump.log", dumpInfo.data(), dumpInfo.length());

	NFIPluginManager::Instance()->SendDumpInfo(dumpInfo);

	NFSLEEP(1000000);

	// Kill ourself by the default signal handler.
	InvokeDefaultSignalHandler(signal_number);
}

void CloseServerSignalHandler(int signal_number,
	siginfo_t *signal_info,
	void *ucontext)
{
	HandleSignal(signal_number);
}

#endif

void  HandleSignal(int signo)
{
#if NF_PLATFORM != NF_PLATFORM_WIN
	switch (signo)
	{
	case SIGUSR1:
		NFCPluginManager::GetSingletonPtr()->SetExitApp(true);
		break;
	case SIGUSR2:
		NFCPluginManager::GetSingletonPtr()->SetReloadApp(true);
		break;
	case SIGUNUSED:
	case SIGTERM:
	{
		NFCPluginManager::GetSingletonPtr()->SetShutDownApp(true);
	}
	break;
	default:
		break;
	}
#endif
}

void InitSignal()
{
#if NF_PLATFORM != NF_PLATFORM_WIN
    signal(SIGINT,  SIG_IGN);
    signal(SIGHUP,  SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);

	// Build the sigaction struct.
	struct sigaction sig_action;
	memset(&sig_action, 0, sizeof(sig_action));
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags |= SA_SIGINFO;

	for (size_t i = 0; i < NF_ARRAYSIZE(kFailureSignals); ++i) {
		if (kFailureSignals[i].number == SIGUSR1 || kFailureSignals[i].number == SIGUSR2 || kFailureSignals[i].number == 	SIGUNUSED || kFailureSignals[i].number == SIGTERM)
		{
			//需要特殊处理
			sig_action.sa_sigaction = &CloseServerSignalHandler;
			sigaction(kFailureSignals[i].number, &sig_action, NULL);
		}
		else
		{
			sig_action.sa_sigaction = &FailureSignalHandler;
			sigaction(kFailureSignals[i].number, &sig_action, NULL);
		}
	}
#endif
}

