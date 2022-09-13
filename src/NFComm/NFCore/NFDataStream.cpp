// -------------------------------------------------------------------------
//    @FileName         :    NFDataStream.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFDataStream.h"

#include <algorithm>
#include <iostream>

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

void NFDataStream::ToText()
{
	Write('\0');
	seekp(-1);
}

bool NFDataStream::ReadFile(/*const string& strFileName*/ const string& strPathName)
{
	// #if NF_PLATFORM == NF_PLATFORM_WIN
	//      string strPathName = StringUtil::utf8ToMbs(strFileName);
	//         std::replace( strPathName.begin(), strPathName.end(), '\\', '/' );
	// #else
	//         string strPathName = strFileName;
	// #endif
	// clear old data.
	if (self_created_ && buffer_)
	{
		free(buffer_);
		buffer_ = NULL;
		capacity_ = 0;
		self_created_ = true;
	}

	write_index_ = 0;
	read_index_ = 0;

	if (strPathName.size() < 1)
	{
		return false;
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	const char* mode = "rb";
#else
	const char* mode = "r";
#endif

	FILE* pf = fopen(strPathName.c_str(), mode);
	struct stat st;
	if (!pf || 0 != stat(strPathName.c_str(), &st))
	{
		if (pf)
		{
			fclose(pf);
		}

		return false;
	}

	// allocate memory.
	buffer_ = (uint8_t*)malloc(st.st_size);

	if (!buffer_)
	{ //st.st_size may be 0
		fclose(pf);
		return false;
	}

	self_created_ = true;
	capacity_ = st.st_size;

	size_t remain = capacity_;

	while (remain > 0 && !feof(pf))
	{
		size_t readn = fread(buffer_ + (capacity_ - remain),
		                     sizeof(char), remain, pf);

		remain -= readn;

		if (ferror(pf))
		{
			fclose(pf);
			return false;
		}
	}

	fclose(pf);

	assert(remain == 0);
	seekp((int32_t)capacity_);

	return true;
}

static void createDir(const string& strFileName)
{
	string strPathName = strFileName;

	std::replace(strPathName.begin(), strPathName.end(), '\\', '/');

	size_t nCurSplit = 0, nNextSplit = 0;

	do
	{
		//  "/abc/ab/abc",   "e:/abac/adc"   "abcc/abc/a",   "abc"
		// get current dir name.
		nCurSplit = strPathName.find_first_of((string::value_type)'/', nNextSplit);

		if (nCurSplit != 0 && nCurSplit != string::npos)
		{
			// current dir
#if NF_PLATFORM == NF_PLATFORM_WIN
			int ret = _mkdir(strPathName.substr(0, nCurSplit).c_str());
#else
			int ret = mkdir(strPathName.substr(0, nCurSplit).c_str(), 0777);
#endif
			if (ret < 0)
			{
				std::cout << "create dir:" << strFileName << " failed" << std::endl;
			}
		}

		nNextSplit = nCurSplit + 1;
	}
	while (nCurSplit != string::npos);
}

bool NFDataStream::WriteFile(const string& filepath)
{
	// create directory.
	createDir(filepath);

#if NF_PLATFORM == NF_PLATFORM_WIN
	const char* mode = "wb+";
#else
	const char* mode = "w+";
#endif

	// open file.
	FILE* fp = fopen(filepath.c_str(), (mode));
	if (!fp)
	{
		return false;
	}

	size_t writen = fwrite(buffer_, 1, write_index_, fp);
	fclose(fp);

	if (writen < (uint32_t)write_index_)
	{
		return false;
	}

	return true;
}

bool NFDataStream::IsContentEquals(const NFDataStream& first, const NFDataStream& second)
{
	size_t sz = first.size();
	if (sz != second.size())
	{
		return false;
	}

	for (size_t i = 0; i < sz; i++)
	{
		if (first.CharAt(i) != second.CharAt(i))
		{
			return false;
		}
	}

	return true;
}

