// -------------------------------------------------------------------------
//    @FileName         :    NFDataStream.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>

#include "NFPlatform.h"

// The class encapsulates data stream in memory.
class _NFExport NFDataStream
{
public:
	enum Status
	{
		kGood = 0,
		kReadBad = 1 << 1,
		kWriteBad = 1 << 2,
	};

public:
	NFDataStream();

	// Construct with memory size.
	explicit NFDataStream(size_t buf_size);

	// Construct with outside memory and size.
	// @note if need_free is true, the memory pointed by d will be released by calling free(...)
	//       when this instance is released, so d MUST be allocated by call to malloc(...)
	explicit NFDataStream(void* d, size_t len, bool need_free);

	~NFDataStream();

	uint32_t Capacity() const
	{
		return capacity_;
	}

	// Assure convert to text.
	// @note Add ending null to the stream, but do not change the data size.
	void ToText();

	// Query whether the read operation is bad.
	bool IsReadBad() const;

	// Query whether the write operation is bad.
	bool IsWriteBad() const;

	// Sets stats of the file.
	// @param bits - kWriteBad or kReadBad or 0 or kWriteBad|kReadBad
	void SetStatus(uint32_t bits);

	// Open the raw file and read all the file data to this memory data stream
	// @note It is only a helper method.
	bool ReadFile(const string& filename);

	// @brief: Helper method to save data to a disk file.
	// @param[in]: const string& filename, the path name of the file, it can include dir path
	// @return: bool
	bool WriteFile(const string& filename);

	// Read data form data stream, the result is stored in buf
	// @remark The read count is in len,it may be lesser than the buf_len,
	//         the len will be zero if read nothing or there is an error occurred
	// @param  buf: the buffer which the result will be stored
	// @param  buf_len: the buf length in byte
	// @return the return value is true if read succeed, else false
	bool Read(void* buf, size_t buf_len);

	// Write a value to data stream
	// @param  v: the value which will be written
	// @note   the return value is true if write succeed, else false
	bool Write(int8_t ch);

	// Read 4 bytes from this data stream, the data in this stream is Little Endian
	//  In little endian CPU system:
	//      char* pc = pU32;
	//      buffer_[0] -> pc[0]
	//      buffer_[1] -> pc[1]
	//      buffer_[2] -> pc[2]
	//      buffer_[3] -> pc[3]
	//  In big endian CPU system:
	//      char* pc = pint;
	//      buffer_[0] -> pc[3]
	//      buffer_[1] -> pc[2]
	//      buffer_[2] -> pc[1]
	//      buffer_[3] -> pc[0]
	// @param  pint : the value will stored there
	// @return the return value is true if read succeed, else false
	bool ReadLE(uint32_t* pU32);

	// Write 4 bytes int data to this data stream, the data in this stream is Little Endian
	//  In little endian CPU system:
	//      char* pc = &i;
	//      pc[0] -> buffer_[0]
	//      pc[1] -> buffer_[1]
	//      pc[2] -> buffer_[2]
	//      pc[3] -> buffer_[3]
	//  In big endian CPU system:
	//      char* pc = &i;
	//      pc[3] -> buffer_[0]
	//      pc[2] -> buffer_[1]
	//      pc[1] -> buffer_[2]
	//      pc[0] -> buffer_[3]
	// @param  i : the int which will be written
	// @return true if write successfully, else false
	bool WriteLE(uint32_t i);

	// Write data to data stream
	// @param buf: the buffer where stored the data to be written to the stream
	// @param buf_len: the buf length in byte
	// @return true if write successfully, else false
	bool Write(const void* buf, size_t buf_len);

	// Sets the capacity of the stream to at least size,
	//  the stream's data buffer maybe extend.
	// @note It will not change any flag of the stream if successfully
	// @return false if failed to allocate enough memory
	//   and set the reading and writing flag as kReadBad and kWriteBad
	bool Reserve(size_t size);

	size_t Size() const
	{
		return GetWriteIndex();
	}

	const char* Data() const
	{
		return reinterpret_cast<const char*>(GetCache());
	}

	NFDataStream& SeekWriteIndex(int32_t offset);

	NFDataStream& SeekReadIndex(int32_t offset);

	uint32_t GetWriteIndex() const
	{
		return write_index_;
	}

	uint32_t GetReadIndex() const
	{
		return read_index_;
	}

	void ResetMemory();

	// get the buffer base address pointer, don't delete the returned pointer
	void* GetCache() const;

	// return the char at the index of the data stream
	uint8_t CharAt(size_t index) const;

	// Returns the number of bytes of the unread portion of the buffer
	uint32_t GetReadableSize() const;
	uint32_t GetWriteableSize() const;

	// Gets buffer pointer to the current read position.
	void* GetCurrentReadBuffer() const;
	void* GetCurrentWriteBuffer() const;

	// Reset the data stream
	void Reset();

	void Swap(NFDataStream& r);

	bool Resize(size_t len);

	// Expand size of memory to the current stack.
	// if it failed we SetStatus(kReadBad | kWriteBad) and return false.
	bool Expand(uint32_t nSizeToAdd);

	static bool IsContentEquals(const NFDataStream& first, const NFDataStream& second);

	// The same interfaces for std::ostream/istream
public:
	// Get the total length of data in byte which has been written into this stream
	size_t size() const
	{
		return tellp();
	}

	const char* data() const
	{
		return reinterpret_cast<const char*>(GetCache());
	}

	NFDataStream& put(char ch);

	NFDataStream& write(const void* buf, size_t buf_len);

	// Move the stream pointer for read
	// @remark   after seek, the read pointer' position is at the stream buffer' base address + start + offset,
	// or at the stream buffer' base address if the result is lesser than the base address
	// or at the end of stream buffer if the result exceeded the end
	//
	// @param  offset: the offset to move
	NFDataStream& seekg(int32_t offset);

	// get current read position
	uint32_t tellg() const;

	// Move the stream pointer for write
	// @remark   after seek, the write pointer' position is at the stream buffer' base address + start + offset,
	// or at the stream buffer' base address if the result is lesser than the base address
	// or at the end of stream buffer if the result exceeded the end
	//
	// @param  offset: the offset to move
	//      if offset < 0, this function doesn't case about write_index_
	NFDataStream& seekp(int32_t offset);

	// get current write position
	uint32_t tellp() const;

	bool reserve(size_t size);

private:
	template <typename T>
	NFDataStream& InternalWriteType(const T& val, std::true_type);

	template <typename T>
	NFDataStream& InternalReadType(T& val, std::true_type);

	template <typename _Kt>
	NFDataStream& InternalWriteVector(const std::vector<_Kt>& val, std::true_type);

	template <typename _Kt>
	NFDataStream& InternalReadVector(std::vector<_Kt>& val, std::true_type);

private:

	template <typename T>
	NFDataStream& InternalWriteType(const T& val, std::false_type);
	template <typename T>
	NFDataStream& InternalReadType(T& val, std::false_type);

public:
	template <typename T>
	NFDataStream& operator<<(const T& val);
	template <typename T>
	NFDataStream& operator >>(T& val);

	NFDataStream& operator<<(const string& val);
	NFDataStream& operator >>(string& val);

	NFDataStream& operator<<(const char* szVal);

	NFDataStream& operator<<(const NFDataStream& val);
	NFDataStream& operator >>(NFDataStream& val);

	template <typename _Kt, typename _Val>
	NFDataStream& operator >>(std::pair<_Kt, _Val>& val);
	template <typename _Kt, typename _Val>
	NFDataStream& operator<<(const std::pair<_Kt, _Val>& val);

	template <typename _Kt>
	NFDataStream& operator<<(const std::vector<_Kt>& val);
	template <typename _Kt>
	NFDataStream& operator >>(std::vector<_Kt>& val);

	template <typename _Kt>
	NFDataStream& operator<<(const std::list<_Kt>& val);
	template <typename _Kt>
	NFDataStream& operator >>(std::list<_Kt>& val);

	// 	template< typename _Kt >
	// 	DataStream& operator<<(const std::list< _Kt>& val);
	// 	template< typename _Kt >
	// 	DataStream& operator >> (std::list< _Kt>& val);

	template <typename _Kt, typename _Val>
	NFDataStream& operator<<(const std::map<_Kt, _Val>& val);
	template <typename _Kt, typename _Val>
	NFDataStream& operator >>(std::map<_Kt, _Val>& val);

	template <class T>
	NFDataStream& operator<<(const std::set<T>& val);
	template <class T>
	NFDataStream& operator >>(std::set<T>& val);

	template <typename _Kt, typename _Val>
	NFDataStream& operator<<(const std::unordered_map<_Kt, _Val>& val);
	template <typename _Kt, typename _Val>
	NFDataStream& operator >>(std::unordered_map<_Kt, _Val>& val);
private:
	uint8_t* buffer_; // Buffer to hold all the data. It can expand when it is wrote and is not large enough to hold more data.
	bool self_created_; // Whether the buffer is created by this instance itself.
	uint32_t capacity_; // Size of buffer_.
	uint32_t write_index_; // Current write data cursor in the buffer.
	uint32_t read_index_; // Current read data cursor in the buffer.
	uint32_t status_; // status of the file.

private:
	// Hide copy constructor
	NFDataStream(const NFDataStream&);
	NFDataStream& operator=(const NFDataStream&);
};

inline void NFDataStream::Swap(NFDataStream& r)
{
	std::swap(buffer_, r.buffer_);
	std::swap(self_created_, r.self_created_);
	std::swap(capacity_, r.capacity_);
	std::swap(write_index_, r.write_index_);
	std::swap(read_index_, r.read_index_);
	std::swap(status_, r.status_);
}

#pragma pack(push,1)
template <typename TE1, typename TE2>
struct Struct2Element
{
	TE1 v1;
	TE2 v2;
};

template <typename TE1, typename TE2, typename TE3>
struct Struct3Element
{
	TE1 v1;
	TE2 v2;
	TE3 v3;
};

template <typename TE1, typename TE2, typename TE3, typename TE4>
struct Struct4Element
{
	TE1 v1;
	TE2 v2;
	TE3 v3;
	TE4 v4;
};
#pragma pack(pop)

// Serialize Struct2Element
template <typename TE1, typename TE2>
inline NFDataStream& operator<<(NFDataStream& file, const Struct2Element<TE1, TE2>& val)
{
	file << static_cast<const TE1&>(val.v1)
		<< static_cast<const TE2&>(val.v2);

	return file;
}

// Serialize Struct2Element
template <typename TE1, typename TE2>
inline NFDataStream& operator >>(NFDataStream& file, Struct2Element<TE1, TE2>& val)
{
	file >> static_cast<TE1&>(val.v1)
		>> static_cast<TE2&>(val.v2);

	return file;
}

// Serialize Struct2Element
template <typename TE1, typename TE2, typename TE3>
inline NFDataStream& operator<<(NFDataStream& file, const Struct3Element<TE1, TE2, TE3>& val)
{
	file << static_cast<const TE1&>(val.v1)
		<< static_cast<const TE2&>(val.v2)
		<< static_cast<const TE3&>(val.v3);
	return file;
}

// Serialize Struct2Element
template <typename TE1, typename TE2, typename TE3>
inline NFDataStream& operator >>(NFDataStream& file, Struct3Element<TE1, TE2, TE3>& val)
{
	file >> static_cast<TE1&>(val.v1)
		>> static_cast<TE2&>(val.v2)
		>> static_cast<TE3&>(val.v3);
	return file;
}

template <typename TE1, typename TE2, typename TE3, typename TE4>
inline NFDataStream& operator<<(NFDataStream& file, const Struct4Element<TE1, TE2, TE3, TE4>& val)
{
	file << static_cast<const TE1&>(val.v1)
		<< static_cast<const TE2&>(val.v2)
		<< static_cast<const TE3&>(val.v3)
		<< static_cast<const TE4&>(val.v4);
	return file;
}

template <typename TE1, typename TE2, typename TE3, typename TE4>
inline NFDataStream& operator >>(NFDataStream& file, Struct4Element<TE1, TE2, TE3, TE4>& val)
{
	file >> static_cast<TE1&>(val.v1)
		>> static_cast<TE2&>(val.v2)
		>> static_cast<TE3&>(val.v3)
		>> static_cast<TE4&>(val.v4);
	return file;
}

// DataStream Implementation

inline NFDataStream::NFDataStream()
	: buffer_(nullptr)
	  , self_created_(false)
	  , capacity_(0)
	  , write_index_(0)
	  , read_index_(0)
	  , status_(0)
{
}

inline NFDataStream::NFDataStream(size_t nBufferSize)
	: self_created_(true)
	  , capacity_(static_cast<uint32_t>(nBufferSize))
	  , write_index_(0)
	  , read_index_(0)
	  , status_(0)
{
	buffer_ = static_cast<uint8_t*>(malloc(capacity_));

	if (!buffer_)
	{
		capacity_ = 0;
	}
}

inline NFDataStream::NFDataStream(void* pData, size_t nBufferSize, bool bDestroy)
	: buffer_(static_cast<uint8_t*>(pData))
	  , self_created_(bDestroy)
	  , capacity_(static_cast<uint32_t>(nBufferSize))
	  , write_index_(0)
	  , read_index_(0)
	  , status_(0)
{
}

inline NFDataStream::~NFDataStream()
{
	if (buffer_ && self_created_)
	{
		free(buffer_);
	}
}

inline bool NFDataStream::IsReadBad() const
{
	return (status_ & kReadBad) == 0 ? false : true;
}

inline bool NFDataStream::IsWriteBad() const
{
	return (status_ & kWriteBad) == 0 ? false : true;
}

inline void NFDataStream::SetStatus(uint32_t nBits)
{
	status_ |= nBits;
}

inline bool NFDataStream::Read(void* buf, size_t buf_len)
{
	// check whether the file is bad.
	assert(buf && buffer_);

	if (IsReadBad())
	{
		return false;
	}

	uint32_t nNewPos = read_index_ + static_cast<uint32_t>(buf_len);

	if (nNewPos > static_cast<uint32_t>(write_index_))
	{
		SetStatus(kReadBad);
		return false;
	}

	memcpy(buf, buffer_ + read_index_, buf_len);

	read_index_ = nNewPos;

	return true;
}

inline bool NFDataStream::Write(int8_t v)
{
	return Write(&v, sizeof(v));
}

inline bool NFDataStream::ReadLE(uint32_t* pu32)
{
	if (this->GetReadableSize() < 4)
	{
		return false;
	}

#ifdef H_LITTLE_ENDIAN
	*this >> *pu32;
#else
	uint8_t* pc = reinterpret_cast<uint8_t*>(pu32);
	*this >> pc[3];
	*this >> pc[2];
	*this >> pc[1];
	*this >> pc[0];
#endif

	return true;
}

inline bool NFDataStream::WriteLE(uint32_t i)
{
#ifdef H_LITTLE_ENDIAN
	*this << i;
#else
	*this << static_cast<char>((i & 0xff000000) >> 24);
	*this << static_cast<char>((i & 0x00ff0000) >> 16);
	*this << static_cast<char>((i & 0x0000ff00) >> 8);
	*this << static_cast<char>((i & 0x000000ff));
#endif
	return true;
}

inline bool NFDataStream::Write(const void* buf, size_t buf_len)
{
	assert(buf);

	if (!Expand(static_cast<uint32_t>(buf_len)))
	{
		return false;
	}

	memcpy(buffer_ + write_index_, buf, buf_len);
	write_index_ += static_cast<uint32_t>(buf_len);
	return true;
}

inline NFDataStream& NFDataStream::SeekWriteIndex(int32_t offset)
{
	int64_t new_pos = static_cast<int32_t>(write_index_) + offset;

	if (new_pos < 0)
	{
		write_index_ = 0;
	}
	else
	{
		// pre-allocate size.
		if (new_pos > static_cast<int64_t>(write_index_))
		{
			if (!Expand(static_cast<uint32_t>(new_pos) - write_index_))
			{
				return *this;
			}
		}

		// finished check, set the new size.
		write_index_ = static_cast<uint32_t>(new_pos);
	}

	return *this;
}

inline NFDataStream& NFDataStream::SeekReadIndex(int32_t offset)
{
	int32_t nNewPos = read_index_ + offset;

	if (nNewPos > static_cast<int32_t>(write_index_))
	{
		read_index_ = write_index_;
		SetStatus(kReadBad);
	}
	else if (nNewPos < 0)
	{
		read_index_ = 0;
		SetStatus(kReadBad);
	}
	else
	{
		read_index_ = static_cast<uint32_t>(nNewPos);
	}

	return *this;
}

inline NFDataStream& NFDataStream::seekg(int32_t offset)
{
	return SeekReadIndex(offset);
}

inline uint32_t NFDataStream::tellg() const
{
	return read_index_;
}

inline NFDataStream& NFDataStream::seekp(int32_t offset)
{
	return SeekWriteIndex(offset);
}

inline uint32_t NFDataStream::tellp() const
{
	return write_index_;
}

inline bool NFDataStream::reserve(size_t sz)
{
	return Reserve(sz);
}

inline NFDataStream& NFDataStream::put(char ch)
{
	Write(ch);
	return *this;
}

inline NFDataStream& NFDataStream::write(const void* buf, size_t buf_len)
{
	Write(buf, buf_len);
	return *this;
}

inline void* NFDataStream::GetCache() const
{
	assert(buffer_);
	return buffer_;
}

inline uint8_t NFDataStream::CharAt(size_t index) const
{
	assert(index < size());
	return *(static_cast<int8_t*>(GetCache()) + index);
}

inline uint32_t NFDataStream::GetReadableSize() const
{
	return write_index_ - read_index_;
}

inline uint32_t NFDataStream::GetWriteableSize() const
{
	if (write_index_ >= capacity_) return 0;
	return capacity_ - write_index_;
}

inline void* NFDataStream::GetCurrentReadBuffer() const
{
	return static_cast<char*>(GetCache()) + read_index_;
}

inline void* NFDataStream::GetCurrentWriteBuffer() const
{
	return static_cast<char*>(GetCache()) + write_index_;
}

inline void NFDataStream::Reset()
{
	write_index_ = 0;
	read_index_ = 0;
	status_ = kGood;
}

inline void NFDataStream::ResetMemory()
{
	assert(buffer_);
	assert(write_index_ >= read_index_);
	uint32_t readSize = write_index_ - read_index_;
	memmove(buffer_, buffer_ + read_index_, readSize);
	read_index_ = 0;
	write_index_ = readSize;
	status_ = kGood;
}

inline bool NFDataStream::Resize(size_t nSize)
{
	// check size and assure enough buffer.
	if (static_cast<uint32_t>(nSize) > capacity_)
	{
		if (!Expand(static_cast<uint32_t>(nSize) + capacity_))
		{
			return false;
		}
	}
	else if (nSize == 0)
	{
		if (!Expand(sizeof(long)))
		{
			return false;
		}
	}

	write_index_ = static_cast<uint32_t>(nSize);

	return true;
}

inline bool NFDataStream::Expand(uint32_t delta)
{
	uint32_t new_size = write_index_ + delta + 1;

	// only if buffer is no sufficient, we reallocate it.
	if (new_size > static_cast<uint32_t>(capacity_))
	{
		new_size = new_size + (new_size >> 1);

		uint8_t* new_buffer = static_cast<uint8_t*>(malloc(new_size));

		if (!new_buffer)
		{
			SetStatus(kReadBad | kWriteBad);
			return false;
		}

		if (buffer_)
		{
			memcpy(new_buffer, buffer_, capacity_);
		}

		if (self_created_)
		{
			free(buffer_);
		}

		buffer_ = new_buffer;
		capacity_ = new_size;
		self_created_ = true;
	}

	return true;
}

inline bool NFDataStream::Reserve(size_t new_size)
{
	if (new_size > capacity_)
	{
		uint8_t* new_buf = static_cast<uint8_t*>(malloc(new_size));

		if (!new_buf)
		{
			SetStatus(kReadBad | kWriteBad);
			return false;
		}

		capacity_ = static_cast<uint32_t>(new_size);

		if (buffer_)
		{
			memcpy(new_buf, buffer_, write_index_);
		}

		if (self_created_)
		{
			// the old buffer is created by myself, so free it
			free(buffer_);
		}

		buffer_ = new_buf;
		self_created_ = true;
	}

	return true;
}

template <typename T>
NFDataStream& NFDataStream::InternalWriteType(const T& val, std::true_type)
{
	Write(&val, sizeof(T));
	return (*this);
}

template <typename T>
NFDataStream& NFDataStream::InternalReadType(T& val, std::true_type)
{
	Read(&val, sizeof(T));
	return (*this);
}

template <typename _Kt>
NFDataStream& NFDataStream::InternalWriteVector(const std::vector<_Kt>& val, std::true_type)
{
	// 1. write length
	*this << uint32(val.size());

	// 2. memory
	if (!val.empty())
	{
		this->write(&(val[0]), uint32(sizeof(_Kt) * val.size()));
	}
	return *this;
}

template <typename _Kt>
NFDataStream& NFDataStream::InternalReadVector(std::vector<_Kt>& val, std::true_type)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	// 1. write length
	uint32_t nSize = 0;
	*this >> nSize;

	if (GetReadableSize() < nSize)
	{
		SetStatus(kReadBad);
		return *this;
	}

	val.resize(nSize);

	// 2. memory
	if (nSize)
	{
		Read(&(val[0]), sizeof(_Kt) * nSize);
	}
	return *this;
}

template <typename T>
NFDataStream& NFDataStream::operator<<(const T& val)
{
	typedef typename std::is_pod<T>::type T_type;
	return InternalWriteType(val, T_type());
	//return *this;
}

template <typename T>
NFDataStream& NFDataStream::operator >>(T& val)
{
	typedef typename std::is_pod<T>::type T_type;
	return InternalReadType(val, T_type());
	//return *this;
}

inline NFDataStream& NFDataStream::operator<<(const string& val)
{
	uint32_t nStrLen = static_cast<uint32_t>(val.length());

	// 1. write string length
	*this << nStrLen;

	// 2. write string
	Write(val.c_str(), static_cast<uint32_t>(nStrLen));

	return *this;
}

inline NFDataStream& NFDataStream::operator<<(const char* szVal)
{
	if (NULL == szVal)
	{
		return *this;
	}

	uint32_t nStrLen = static_cast<uint32_t>(strlen(szVal));

	// 1. write string length
	*this << static_cast<uint32_t&>(nStrLen);

	// 2. write string
	Write(szVal, nStrLen);

	return *this;
}

inline NFDataStream& NFDataStream::operator >>(string& val)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	// 1. get length
	uint32_t nSize = 0;
	*this >> static_cast<uint32_t&>(nSize);

	// 2. get file
	if (nSize <= static_cast<uint32_t>(GetReadableSize()))
	{
		val.resize(nSize);

		if (nSize)
		{
			Read(&val[0], nSize);

			// assure last character is null
			val[nSize] = static_cast<char>(0);
		}
	}
	else
	{
		SetStatus(kReadBad);
	}

	return *this;
}

inline NFDataStream& NFDataStream::operator<<(const NFDataStream& val)
{
	// 1. write string length
	*this << static_cast<uint32_t>(val.size());

	// 2. write string
	if (val.size() > 0)
	{
		Write(static_cast<char*>(val.GetCache()), val.size());
	}

	return *this;
}

inline NFDataStream& NFDataStream::operator >>(NFDataStream& val)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	val.Reset();

	// 1. read length
	uint32_t nSize = 0;
	*this >> nSize;
	if (nSize == 0)
	{
		return *this;
	}

	if (nSize <= static_cast<uint32_t>(GetReadableSize()))
	{
		// 2. read string
		val.Write((static_cast<char*>(GetCache()) + tellg()), nSize);

		// skip
		seekg(nSize);
	}
	else
	{
		SetStatus(kReadBad);
	}

	return *this;
}

template <typename _Kt, typename _Val>
NFDataStream& NFDataStream::operator >>(std::pair<_Kt, _Val>& val)
{
	(*this) >> val.first >> val.second;
	return *this;
}

template <typename _Kt>
inline NFDataStream& NFDataStream::operator<<(const std::vector<_Kt>& val)
{
	typedef typename std::is_pod<_Kt>::type _Kt_type;
	return InternalWriteVector(val, _Kt_type());
}

template <typename _Kt>
inline NFDataStream& NFDataStream::operator<<(const std::list<_Kt>& val)
{
	*this << static_cast<uint32_t>(val.size());

	auto it(val.begin()), ite(val.end());
	for (; it != ite; ++it)
	{
		*this << static_cast<const _Kt&>(*it);
	}

	return *this;
}

template <typename _Kt, typename _Val>
inline NFDataStream& NFDataStream::operator<<(const std::pair<_Kt, _Val>& val)
{
	(*this) << val.first << val.second;
	return *this;
}

template <typename _Kt, typename _Val>
inline NFDataStream& NFDataStream::operator<<(const std::map<_Kt, _Val>& val)
{
	// 1. write length
	*this << static_cast<uint32_t>(val.size());

	// 2. elements.
	auto it(val.begin()), ite(val.end());
	for (; it != ite; ++it)
	{
		*this << static_cast<const _Kt&>(it->first);
		*this << static_cast<const _Val&>(it->second);
	}

	return *this;
}

template <typename _Kt, typename _Val>
inline NFDataStream& NFDataStream::operator >>(std::map<_Kt, _Val>& val)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	// 1. read length
	uint32_t nSize = 0;
	*this >> static_cast<uint32_t&>(nSize);

	if (GetReadableSize() < nSize)
	{
		SetStatus(kReadBad);
		return *this;
	}

	val.clear();

	for (uint32_t i = 0; i < nSize; ++i)
	{
		if (GetReadableSize() == 0)
		{
			SetStatus(kReadBad);
			break;
		}

		_Kt key;
		*this >> static_cast<_Kt&>(key);
		*this >> static_cast<_Val&>(val[key]);
	}

	return *this;
}

template <typename _Kt>
inline NFDataStream& NFDataStream::operator >>(std::list<_Kt>& val)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	// 1. read length
	uint32_t nSize = 0;
	*this >> static_cast<uint32_t&>(nSize);

	if (GetReadableSize() < nSize)
	{
		SetStatus(kReadBad);
		return *this;
	}

	val.clear();

	for (uint32_t i = 0; i < nSize; ++i)
	{
		if (GetReadableSize() == 0)
		{
			SetStatus(kReadBad);
			break;
		}

		val.push_back(_Kt());
		*this >> static_cast<_Kt&>(val.back());
	}

	return *this;
}

// template< typename _Kt >
// inline DataStream& DataStream::operator<<(const list< _Kt>& val) {
// 	*this << (uint32_t)val.size();
//
// 	auto it(val.begin()), ite(val.end());
// 	for (; it != ite; ++it) {
// 		*this << (const _Kt&)*it;
// 	}
//
// 	return *this;
// }
//
//
// template< typename _Kt >
// inline DataStream& DataStream::operator >> (list< _Kt>& val) {
// 	// check whether the file is bad.
// 	if (IsReadBad()) {
// 		return *this;
// 	}
//
// 	// 1. read length
// 	uint32_t nSize = 0;
// 	*this >> (uint32_t&)nSize;
//
// 	if (GetReadableSize() < nSize) {
// 		SetStatus(kReadBad);
// 		return *this;
// 	}
//
// 	val.clear();
//
// 	for (uint32_t i = 0; i < nSize; ++i) {
// 		if (GetReadableSize() == 0) {
// 			SetStatus(kReadBad);
// 			break;
// 		}
//
// 		val.push_back(_Kt());
// 		*this >> (_Kt&)val.back();
// 	}
//
// 	return *this;
// }

template <typename _Kt>
inline NFDataStream& NFDataStream::operator >>(std::vector<_Kt>& val)
{
	typedef typename std::is_pod<_Kt>::type _Kt_type;
	return InternalReadVector(val, _Kt_type());
}

template <class T>
inline NFDataStream& NFDataStream::operator<<(const std::set<T>& val)
{
	(*this) << static_cast<uint32_t>(val.size());

	typedef typename std::set<T>::const_iterator Iterator;
	Iterator end = val.end();

	for (Iterator i = val.begin(); i != end; ++i)
	{
		(*this) << (*i);
	}

	return (*this);
}

template <class T>
inline NFDataStream& NFDataStream::operator >>(std::set<T>& val)
{
	uint32_t nSize;
	(*this) >> nSize;

	if ((*this).GetReadableSize() < nSize)
	{
		(*this).SetStatus(NFDataStream::kReadBad);
		return (*this);
	}

	for (size_t i = 0; i < nSize; ++i)
	{
		if ((*this).GetReadableSize() == 0)
		{
			(*this).SetStatus(NFDataStream::kReadBad);
			val.clear();
			break;
		}

		T element = T();
		(*this) >> element;
		val.insert(element);
	}

	return (*this);
}

template <typename _Kt, typename _Val>
NFDataStream& NFDataStream::operator<<(const std::unordered_map<_Kt, _Val>& val)
{
	// 1. write length
	*this << static_cast<uint32_t>(val.size());

	// 2. elements.
	auto it(val.begin()), ite(val.end());

	for (; it != ite; ++it)
	{
		*this << static_cast<const _Kt&>(it->first);
		*this << static_cast<const _Val&>(it->second);
	}

	return *this;
}

template <typename _Kt, typename _Val>
NFDataStream& NFDataStream::operator >>(std::unordered_map<_Kt, _Val>& val)
{
	// check whether the file is bad.
	if (IsReadBad())
	{
		return *this;
	}

	// 1. read length
	uint32_t nSize = 0;
	*this >> static_cast<uint32_t&>(nSize);

	if (GetReadableSize() < nSize)
	{
		SetStatus(kReadBad);
		return *this;
	}

	val.clear();

	for (uint32_t i = 0; i < nSize; ++i)
	{
		if (GetReadableSize() == 0)
		{
			SetStatus(kReadBad);
			break;
		}

		_Kt key;
		*this >> static_cast<_Kt&>(key);
		*this >> static_cast<_Val&>(val[key]);
	}

	return *this;
}

