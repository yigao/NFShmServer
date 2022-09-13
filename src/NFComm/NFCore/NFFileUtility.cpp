// -------------------------------------------------------------------------
//    @FileName         :    NFFileUtility.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFFileUtility.h"

#include "NFStringUtility.h"
#include "NFDataStream.h"

#include <fstream>
#include "NFMD5.h"

// Query whether strFileName is a absolute path.
bool NFFileUtility::IsAbsolutePath(const std::string& path)
{
	if (path.size() == 0)
	{
		return false;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	if (isalpha(static_cast<unsigned char>(path[0])) && path[1] == ':')
	{
		return true;
	}
	else
	{
		return false;
	}

#else
	return path[0] == '/';
#endif
}

std::string NFFileUtility::GetAbsolutePathName(const std::string& strPathName)
{
	std::string strTmp = strPathName;

	if (!IsAbsolutePath(strTmp))
	{
		//
		char szDir[_MAX_PATH];
#if NF_PLATFORM == NF_PLATFORM_WIN
		if (_getcwd(szDir, _MAX_PATH))
		{
			strTmp = std::string(szDir) + ("/") + strTmp;
		}
#else
		getcwd(szDir, _MAX_PATH);
		strTmp = string(szDir) + ("/") + strTmp;
#endif
	}

	// convert file name here.
	NormalizePath(strTmp);

	return strTmp;
}

std::string NFFileUtility::GetFileName(const std::string& strFileName)
{
	// since '/' equal to L'/', we can cast to either one.
	std::string::size_type i = strFileName.find_last_of((std::string::value_type)'/');

	if (i == std::string::npos)
	{
		return strFileName;
	}

	return strFileName.substr(i + 1);
}

std::string NFFileUtility::GetFileNameWithoutExt(const std::string& strFileName)
{
	// since '/' equal to L'/', we can cast to either one.
	std::string::size_type iStart = strFileName.find_last_of((std::string::value_type)'/');

	if (iStart == std::string::npos)
	{
		iStart = 0;
	}
	else
	{
		// skip the '/'
		++iStart;
	}

	return strFileName.substr(iStart, strFileName.find_last_of((std::string::value_type)'.') - iStart);
}

std::string NFFileUtility::GetFileNameExtension(const std::string& strFileName)
{
	std::string::size_type endPos = strFileName.find_last_of((std::string::value_type)'.');

	if (endPos < strFileName.length() - 1)
	{
		return strFileName.substr(endPos + 1);
	}

	return std::string();
}

std::string NFFileUtility::GetFileDirName(const std::string& strFileName)
{
	// since '/' equal to L'/', we can cast to either one.
	std::string::size_type i = strFileName.find_last_of((std::string::value_type)'/');

	if (i == std::string::npos)
	{
		return std::string();
	}

	return strFileName.substr(0, i);
}

std::string NFFileUtility::GetExcludeFileExt(const std::string &sFullFileName)
{
	std::string::size_type pos;
	if ((pos = sFullFileName.rfind('.')) == std::string::npos)
	{
		return sFullFileName;
	}

	return sFullFileName.substr(0, pos);
}

bool NFFileUtility::IsDir(const char* szFileName)
{
	if (!szFileName)
	{
		return false;
	}

	const std::string strFileName(szFileName);

	return IsDir(strFileName);
}

bool NFFileUtility::IsDir(const std::string& strFileName)
{
	//for the 'stat' API, the parameter strFileName SHOULD not contain a trailing backslash
	std::string strStandardisePath = NormalizePath(strFileName, false);

	struct stat st;
	if (0 != stat(strStandardisePath.c_str(), &st))
	{
		return false;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	if ((st.st_mode & _S_IFDIR) == _S_IFDIR)
#else
	if (S_ISDIR(st.st_mode))
#endif
	{
		return true;
	}

	return false;
}

bool NFFileUtility::RemoveDirIfEmpty(const std::string& strDirName, bool bRecursivelyDeleteEmptyParentDir /*= true*/)
{
	if (!IsDir(strDirName))
	{
		return true;
	}

	bool retval = true;

	std::list<std::string> files;
	GetFiles(strDirName, files, true);

	if (files.size() == 0)
	{
		if (NFFileUtility::Rmdir(strDirName.c_str()) != 0)
		{
			retval = false;
		}
	}

	if (bRecursivelyDeleteEmptyParentDir)
	{
		std::string strParentDir = GetParentDir(strDirName);

		if (!RemoveDirIfEmpty(strParentDir, bRecursivelyDeleteEmptyParentDir))
		{
			retval = false;
		}
	}

	return retval;
}

bool NFFileUtility::IsValidDirName(const std::string& szName)
{
	size_t len = szName.length();
	return !((len >= 1 && szName[0] == ('.')) ||
		(len >= 2 && szName[1] == '.'));
}

std::string NFFileUtility::GetParentDir(const std::string& strFileName, bool with_trailing_slash /*= true*/)
{
	std::string path = NormalizePath(strFileName, false);

	if (!IsAbsolutePath(strFileName))
	{
		path = GetAbsolutePathName(path);
	}

	size_t pos = path.find_last_of('/');

	if (pos == 0 || pos == std::string::npos)
	{
		if (with_trailing_slash)
		{
			path += "/";
		}

		return path;
	}
	else
	{
		if (with_trailing_slash)
		{
			std::string retp = std::string(path.c_str(), pos) + "/";
			return retp;
		}
		else
		{
			return std::string(path.c_str(), pos);
		}
	}
}

bool NFFileUtility::Rmdir(const std::string& strDirName)
{
	return Rmdir(strDirName.c_str());
}

bool NFFileUtility::Rmdir(const char* strDirName)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	if (::_rmdir(strDirName) == 0)
#else
	if (::rmdir(strDirName) == 0)
#endif
	{
		return true;
	}

	return false;
}

std::string NFFileUtility::Clean(const std::string& path)
{
	// Not Tested yet.

	std::vector<std::string> v;
	NFStringUtility::Split(v, path, "/\\", 0);

	std::ostringstream newpath;

	// in case of root dir.
	if (path[0] == '/')
	{
		newpath << static_cast<char>('/');
	}

	// erase null.
	std::list<std::string> vv;
	for (auto it = v.rbegin(), ite = v.rend(); it != ite; ++it)
	{
		if (*it == ".")
		{
			continue;
		}
		else if (*it == "..")
		{
			// erase none '.' parent dir.
			while (++it != ite
				&& *it == ".")
			{
				// do nothing.
			}

			// if first of the path is "../" , should reserve it.
			if (it == ite)
			{
				vv.push_front("..");
				break;
			}
		}
		else
		{
			vv.push_front(*it);
		}
	}

	// build string
	for (auto it = vv.begin(), ite = vv.end(); it != ite;)
	{
		newpath << *it;
		if (++it == ite)
		{
			break;
		}
		newpath << static_cast<char>('/');
	}

	return newpath.str();
}

std::string NFFileUtility::Join(const std::string& prefix, const std::string& postfix)
{
	std::string pre = prefix;
	std::string post = postfix;
	pre = NormalizePath(pre, false);
	post = NormalizePath(post, false);
	NFStringUtility::Trim(post, "/", true, false);
	if (NFStringUtility::EndsWith(postfix, "/"))
	{
		post += "/";
	}
	return pre + "/" + post;
}

std::wstring NFFileUtility::Join(const std::wstring& prefix, const std::wstring& postfix)
{
	typedef std::wstring MyString;
	MyString pre = prefix;
	MyString post = postfix;
	pre = NormalizePath(pre, false);
	post = NormalizePath(post, false);
	NFStringUtility::Trim(post, L"/", true, false);
	if (NFStringUtility::EndsWith(postfix, L"/"))
	{
		post += L"/";
	}
	return pre + L"/" + post;
}

std::string NFFileUtility::NormalizePath(const std::string& init, bool with_trailing_slash /*= true*/)
{
	if (init.length() < 1)
	{
		return init;
	}

	std::string path = init;

	std::replace(path.begin(), path.end(), '\\', '/');

	if (path[path.length() - 1] != '/' && with_trailing_slash)
	{
		path += "/";
	}
	else if (path[path.length() - 1] == '/' && !with_trailing_slash)
	{
		NFStringUtility::Trim(path, "/", false, true);
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	NFStringUtility::ToLower(path);
#endif

	return path;
}

std::wstring NFFileUtility::NormalizePath(const std::wstring& init, bool with_trailing_slash /*= true*/)
{
	if (init.length() < 1)
	{
		return init;
	}

	std::wstring path = init;
	std::replace(path.begin(), path.end(), L'\\', L'/');
	if (path[path.length() - 1] != L'/' && with_trailing_slash)
	{
		path += L"/";
	}
	else if (path[path.length() - 1] == L'/' && !with_trailing_slash)
	{
		NFStringUtility::Trim(path, L"/", false, true);
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	NFStringUtility::ToLower(path);
#endif
	return path;
}

void NFFileUtility::SplitFileName(const std::string& filepath,
	std::string& base, std::string& dir_path, bool with_trailing_slash /*= false */)
{
	std::string path = filepath;
	// Replace \ to /
	std::replace(path.begin(), path.end(), '\\', '/');
	// split based on final /
	size_t i = path.find_last_of('/');
	if (i == std::string::npos)
	{
		//dir_path = "";
		dir_path.clear();
		base = filepath;
	}
	else
	{
		base = path.substr(i + 1, path.size() - i - 1);
		if (with_trailing_slash)
		{
			dir_path = path.substr(0, i + 1);
		}
		else
		{
			dir_path = path.substr(0, i);
		}
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	NFStringUtility::ToLower(base);
	NFStringUtility::ToLower(dir_path);
#endif
}

void NFFileUtility::SplitFileName(const std::wstring& filepath,
	std::wstring& base, std::wstring& dir_path, bool with_trailing_slash /*= false */)
{
	std::wstring path = filepath;
	// Replace \ with / first
	std::replace(path.begin(), path.end(), L'\\', L'/');
	// split based on final /
	size_t i = path.find_last_of(L'/');

	if (i == std::wstring::npos)
	{
		//dir_path = L"";
		dir_path.clear();
		base = filepath;
	}
	else
	{
		base = path.substr(i + 1, path.size() - i - 1);
		if (with_trailing_slash)
		{
			dir_path = path.substr(0, i + 1);
		}
		else
		{
			dir_path = path.substr(0, i);
		}
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	NFStringUtility::ToLower(base);
	NFStringUtility::ToLower(dir_path);
#endif
}

bool NFFileUtility::CreateLink(const std::string& oldpath, const std::string& newpath)
{
	if (IsFileExist(oldpath) == false)
	{
		return false;
	}

	if (IsFileExist(newpath))
	{
		Unlink(newpath);
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
#ifdef UNICODE
	//windows创建有问题...........
	//CreateSymbolicLink((LPCWSTR)newpath.c_str(), (LPCWSTR)oldpath.c_str(), 0x0);
#else
	//CreateSymbolicLink((LPCSTR)newpath.c_str(), (LPCSTR)oldpath.c_str(), 0x0);
#endif
#else
	symlink(oldpath.c_str(), newpath.c_str());
#endif
	return true;
}

bool NFFileUtility::Unlink(const std::string& filepath)
{
	bool is_dir = NFFileUtility::IsDir(filepath);

	if (is_dir)
	{
		assert(0 && "not supported");
		return false;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	return ::DeleteFileA(filepath.c_str()) ? true : false;
#else
	return remove(filepath.c_str()) == 0;
#endif
}

bool NFFileUtility::Mkdir(const std::string& dirpath)
{
	size_t nCurSplit;
	size_t nNextSplit = 0;

	do
	{
		// get current dir name.
		nCurSplit = dirpath.find_first_of(static_cast<std::string::value_type>('/'), nNextSplit);
		nNextSplit = dirpath.find_first_of(static_cast<std::string::value_type>('/'), nCurSplit + 1);

#if NF_PLATFORM == NF_PLATFORM_WIN
		// current dir
		::_mkdir(dirpath.substr(0, nNextSplit).c_str());
#else
		// current dir
		::mkdir(dirpath.substr(0, nNextSplit).c_str(), 0755);
#endif

		// next dir
		//nCurSplit = nNextSplit + 1;
	}
	while (nNextSplit != std::string::npos);

	return true;
}

#if NF_PLATFORM == NF_PLATFORM_WIN
// 00
// Existence only
//
// 02
// Write-only
//
// 04
// Read-only
//
// 06
// Read and write
#define F_OK  0
#define W_OK  2
#define R_OK  4
#define RW_OK 6
#define X_OK  1
#endif

uint64_t NFFileUtility::GetFileSize(const std::string& filename)
{
	struct stat buf;
	if (stat(filename.c_str(), &buf) < 0)
	{
		return 0;
	}
	return (uint64_t)buf.st_size;
}

bool NFFileUtility::IsFileExist(const std::string& strFileName)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	if (_access(strFileName.c_str(), F_OK) != 0)
	{
		return false;
	}
#else
	if (access(strFileName.c_str(), F_OK) != 0)
	{
		return false;
	}
#endif
	return true;
}

bool NFFileUtility::IsReadable(const std::string& strFileNmae)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	if (_access(strFileNmae.c_str(), R_OK) != 0)
	{
		return false;
	}
#else
	if (access(strFileNmae.c_str(), R_OK) != 0)
	{
		return false;
	}
#endif
	return true;
}

bool NFFileUtility::IsWriteable(const std::string& strFileNmae)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	if (_access(strFileNmae.c_str(), W_OK) != 0)
	{
		return false;
	}
#else
	if (access(strFileNmae.c_str(), W_OK) != 0)
	{
		return false;
	}
#endif
	return true;
}

bool NFFileUtility::IsExecutable(const std::string& strFileNmae)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	if (_access(strFileNmae.c_str(), X_OK) != 0)
	{
		return false;
	}
#else
	if (access(strFileNmae.c_str(), X_OK) != 0)
	{
		return false;
	}
#endif
	return true;
}

bool NFFileUtility::CopyFile(const std::string& strSrcFile, const std::string& strDestFile, bool bOverride/* = true */)
{
	if (IsDir(strSrcFile))
	{
		return false;
	}

	std::string strDestFilePath = strDestFile;

	if (IsDir(strDestFile))
	{
		strDestFilePath = Join(strDestFile, GetFileName(strSrcFile));
	}

	if (IsFileExist(strDestFilePath) && !bOverride)
	{
		return false;
	}

	NFDataStream databuf;
	databuf.ReadFile(strSrcFile);
	databuf.WriteFile(strDestFile);
	return true;
}

bool NFFileUtility::ReadFileContent(const std::string& strFileName, std::string& strContent)
{
	FILE* fp = fopen(strFileName.c_str(), "rb");
	if (!fp)
	{
		return false;
	}

	fseek(fp, 0, SEEK_END);
	const long filelength = ftell(fp);
	if (filelength < 0)
	{
		fclose(fp);
		return false;
	}
	fseek(fp, 0, SEEK_SET);
	strContent.resize(static_cast<size_t>(filelength));
	fread((void*)strContent.data(), static_cast<size_t>(filelength), 1, fp);
	fclose(fp);

	return true;
}

bool NFFileUtility::ReadFile(const std::string& filepath, std::vector<std::string>& lines)
{
    if (filepath.empty())
    {
        return false;
    }

    std::ifstream ifs(filepath.c_str(), std::ios::binary);
    if (!ifs)
    {
        return false;
    }

    std::string line;

    while (!ifs.eof()) //-V1024
    {
        getline(ifs, line);
        lines.push_back(line);
    }

    return true;
}

bool NFFileUtility::ReadFile(const char* szFileName, std::list<std::string>& lines)
{
	if (!szFileName)
	{
		return false;
	}

	std::ifstream ifs(szFileName, std::ios::binary);
	if (!ifs)
	{
		return false;
	}

	std::string line;

	while (!ifs.eof()) //-V1024
	{
		getline(ifs, line);
		lines.push_back(line);
	}

	return true;
}

bool NFFileUtility::ChmodFile(const char* filepath, int mode)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
#else
    std::string str = "chmod 777 " + std::string(filepath);
    system(str.c_str());
#endif
    return true;
}

bool NFFileUtility::ChmodFile(const std::string& filepath, int mode)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
#else
    std::string str = "chmod 777 " + filepath;
    system(str.c_str());
#endif
    return true;
}

bool NFFileUtility::WriteFile(const std::string& filepath, const void* content, const size_t len)
{
	return WriteFile(filepath.c_str(), content, len);
}

bool NFFileUtility::WriteFile(const std::string& filepath, const std::string& content)
{
    return WriteFile(filepath.c_str(), content.data(), content.length());
}

bool NFFileUtility::WriteFile(const char* filepath, const void* content, const size_t len)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	const char* mode = "wb+";
#else
	const char* mode = "w+";
#endif
	FILE* fp = ::fopen(filepath, mode);

	if (fp == nullptr)
	{
		fprintf(stderr, "%s : could not open file \"%s\" for write\n", __func__, filepath);
		return false;
	}

	::fwrite(content, sizeof(char), len, fp);
	::fflush(fp);
	::fclose(fp);

	return true;
}

bool NFFileUtility::AWriteFile(const char* filepath, const void* content, const size_t len)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    const char* mode = "ab+";
#else
    const char* mode = "a+";
#endif
    FILE* fp = ::fopen(filepath, mode);

    if (fp == nullptr)
    {
        fprintf(stderr, "%s : could not open file \"%s\" for write\n", __func__, filepath);
        return false;
    }

    ::fwrite(content, sizeof(char), len, fp);
    ::fflush(fp);
    ::fclose(fp);

    return true;
}

bool NFFileUtility::AWriteFile(const std::string& filepath, const void* content, const size_t len)
{
    return AWriteFile(filepath.c_str(), content, len);
}

bool NFFileUtility::AWriteFile(const std::string& filepath, const std::string& content)
{
    return AWriteFile(filepath.c_str(), content.data(), content.length());
}

void NFFileUtility::GetFiles(const std::string& strDirName, std::list<std::string>& files, bool recursively/* = true*/, const std::string& filter/* = "*.*"*/)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	struct _finddata_t finfo; //file info

	intptr_t hFile = _findfirst(NFFileUtility::Join(strDirName, "*").c_str(), &finfo);
	if (-1 == hFile)
	{
		return;
	}

	do
	{
		if ((finfo.attrib & _A_SUBDIR))
		{
			if (recursively && strcmp(finfo.name, ".") != 0 && strcmp(finfo.name, "..") != 0)
			{
				GetFiles(NFFileUtility::Join(strDirName, finfo.name), files, recursively, filter);
			}
		}
		else
		{
			std::string strFileName = NFFileUtility::Join(strDirName, finfo.name);
			if (NFStringUtility::Match(strFileName, filter))
			{
				files.push_back(strFileName);
			}
		}
	}
	while (_findnext(hFile, &finfo) == 0);

	_findclose(hFile);

#else
	struct dirent** namelist;
	int n = scandir(strDirName.c_str(), &namelist, 0, alphasort);

	if (n < 0) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (namelist[i]->d_type == DT_DIR) {
			if (recursively && strcmp(namelist[i]->d_name, ".") != 0 && strcmp(namelist[i]->d_name, "..") != 0) {
				GetFiles(NFFileUtility::Join(strDirName, namelist[i]->d_name), files, recursively, filter);
			}
		}
		else {
			string strFileName = NFFileUtility::Join(strDirName, namelist[i]->d_name);

			if (NFStringUtility::Match(strFileName, filter)) {
				files.push_back(strFileName);
			}
		}
		free(namelist[i]);
	}
	free(namelist);
#endif
}

void NFFileUtility::GetFiles(const std::string& strDirName, std::list<std::string>& files, int depth /*= 0*/, const std::string& filter/* = "*"*/)
{
	if (depth < 0)
	{
		return;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	struct _finddata_t finfo; //file info

	//if ( ( hFile = _findfirst( p.assign( strDirName ).append( "/*" ).append( "*" ).c_str(), &fileinfo ) ) != -1 )
	intptr_t hFile = _findfirst(NFFileUtility::Join(strDirName, "*").c_str(), &finfo);
	if (-1 == hFile)
	{
		return;
	}

	do
	{
		std::string strFileName = NFFileUtility::Join(strDirName, finfo.name);
		if ((finfo.attrib & _A_SUBDIR))
		{
			if (strcmp(finfo.name, ".") != 0 && strcmp(finfo.name, "..") != 0)
			{
				if (NFStringUtility::Match(strFileName, filter))
				{
					files.push_back(strFileName);
				}

				if (depth > 0)
				{
					GetFiles(strFileName, files, depth - 1, filter);
				}
			}
		}
		else
		{
			if (NFStringUtility::Match(strFileName, filter))
			{
				files.push_back(strFileName);
			}
		}
	}
	while (_findnext(hFile, &finfo) == 0);

	_findclose(hFile);

#else
	struct dirent** namelist = NULL;
	int n = scandir(strDirName.c_str(), &namelist, 0, alphasort);

	if (n < 0) {
		std::ostringstream log;
		log << "scandir failed. return value = -1, errno=" << errno;
	//H_LOG_NAME_DEBUG( "FileUtil", log.str() );
		return;
	}

	for (int i = 0; i < n; ++i) {
		string strFileName = NFFileUtility::Join(strDirName, namelist[i]->d_name);
		if (namelist[i]->d_type == DT_DIR) {
			if (strcmp(namelist[i]->d_name, ".") != 0 && strcmp(namelist[i]->d_name, "..") != 0) {
				if (NFStringUtility::Match(strFileName, filter)) {
					files.push_back(strFileName);
				}

				if (depth > 0) {
					GetFiles(strFileName, files, depth - 1, filter);
				}
			}
		}
		else {
			if (NFStringUtility::Match(strFileName, filter)) {
				files.push_back(strFileName);
			}
		}
		free(namelist[i]);
	}
	free(namelist);
#endif
}

#if NF_PLATFORM == NF_PLATFORM_WIN
/** Return the offset in 10th of micro sec between the windows base time (
 *	01-01-1601 0:0:0 UTC) and the unix base time (01-01-1970 0:0:0 UTC).
 *	This value is used to convert windows system and file time back and
 *	forth to unix time (aka epoch)
 */
uint64_t NFFileUtility::GetWindowsToUnixBaseTimeOffset()
{
	static bool init = false;

	static uint64_t offset = 0;

	if (!init)
	{
		// compute the offset to convert windows base time into unix time (aka epoch)
		// build a WIN32 system time for jan 1, 1970
		SYSTEMTIME baseTime;
		baseTime.wYear = 1970;
		baseTime.wMonth = 1;
		baseTime.wDayOfWeek = 0;
		baseTime.wDay = 1;
		baseTime.wHour = 0;
		baseTime.wMinute = 0;
		baseTime.wSecond = 0;
		baseTime.wMilliseconds = 0;

		FILETIME baseFileTime = { 0,0 };
		// convert it into a FILETIME value
		SystemTimeToFileTime(&baseTime, &baseFileTime);
		offset = baseFileTime.dwLowDateTime | (uint64_t(baseFileTime.dwHighDateTime) << 32);

		init = true;
	}

	return offset;
}
#endif

uint32_t NFFileUtility::GetFileModificationDate(const std::string &filename)
{
	std::string::size_type pos;
	std::string fn;
	if ((pos = filename.find("@@")) != std::string::npos)
	{
		fn = filename.substr(0, pos);
	}
	else if ((pos = filename.find('@')) != std::string::npos)
	{
		//fn = CPath::lookup(filename.substr(0, pos));
	}
	else
	{
		fn = filename;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	std::wstring wfn = NFStringUtility::s2ws(fn);
	//	struct _stat buf;
	//	int result = _stat (fn.c_str (), &buf);
		// Changed 06-06-2007 : boris : _stat have an incoherent and hard to reproduce
		// on windows : if the system clock is adjusted according to daylight saving
		// time, the file date reported by _stat may (not always!) be adjusted by 3600s
		// This is a bad behavior because file time should always be reported as UTC time value

		// Use the WIN32 API to read the file times in UTC

		// create a file handle (this does not open the file)
	HANDLE h = CreateFile(wfn.c_str(), 0, 0, NULL, OPEN_EXISTING, 0, 0);
	if (h == INVALID_HANDLE_VALUE)
	{
		//std::cout << "Can't get modification date on file :" << fn << std::endl;
		return 0;
	}
	FILETIME creationTime;
	FILETIME accesstime;
	FILETIME modTime;

	// get the files times
	BOOL res = GetFileTime(h, &creationTime, &accesstime, &modTime);
	if (res == 0)
	{
		//std::cout << "Can't get modification date on file :" << fn << std::endl;
		CloseHandle(h);
		return 0;
	}
	// close the handle
	CloseHandle(h);

	// win32 file times are in 10th of micro sec (100ns resolution), starting at jan 1, 1601
	// hey Mr Gates, why 1601 ?

	// first, convert it into second since jan1, 1601
	uint64_t t = modTime.dwLowDateTime | (uint64_t(modTime.dwHighDateTime) << 32);

	// adjust time base to unix epoch base
	t -= GetWindowsToUnixBaseTimeOffset();

	// convert the resulting time into seconds
	t /= 10;	// microsec
	t /= 1000;	// millisec
	t /= 1000;	// sec

	// return the resulting time
	return uint32_t(t);

#else
	struct stat buf;
	int result = stat(fn.c_str(), &buf);
	if (result != 0)
	{
		//std::cout << "Can't get modification date on file :" << fn << std::endl;
		return 0;
	}
	else
		return (uint32_t)buf.st_mtime;
#endif

}

int NFFileUtility::GetFileContainMD5(const std::string& strFileName, std::string& fileMd5) {
    bool exist = NFFileUtility::IsFileExist(strFileName);
    if (!exist) return -1;

    fileMd5 = NFMD5::md5file(strFileName);

    return 0;
}
