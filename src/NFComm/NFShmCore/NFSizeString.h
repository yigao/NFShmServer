// -------------------------------------------------------------------------
//    @FileName         :    NFSizeString.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFShmMgr.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
* 定长的字符串封装
*/
template<int SIZE = 1024>
class NFSizeString //-V690
{
public:
	NFSizeString()
	{
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
	}

    int CreateInit()
    {
        memset(m_szBuf, 0, SIZE);
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

	~NFSizeString()
	{
	}

	bool operator == (const char* pstr) const
	{
		return strcmp(Get(), pstr) == 0;
	}

	bool operator == (const std::string& str) const
	{
		return strcmp(Get(), str.c_str()) == 0;
	}

	bool operator == (const NFSizeString& obj) const
	{
		//CT_TRACE(("this:%s  obj:%s",Get(), obj.Get()));
		return strcmp(Get(), obj.Get()) == 0;
	}

	NFSizeString& operator = (const NFSizeString& obj)
	{
		Copy(obj);
		return *this;
	}

	NFSizeString& operator = (const std::string& obj)
	{
		Copy(obj);
		return *this;
	}

	char* operator ()() const
	{
		return Get();
	}

    const char &operator[](int i) const {
        return m_szBuf[i];
    }

    char &operator[](int i) {
        return m_szBuf[i];
    }

    const char *GetBuffer() const {
        return Get();
    }

    char *GetBuffer() {
        return Get();
    }

    int GetBufferLen() const {
        return Size();
    }

    int GetDataLen() const {
        return (int) strlen(Get());
    }

    void SetDataLen(int iLen) {
        m_szBuf[iLen] = '\0';
    }

    const char *Get() const {
        return (const char *) m_szBuf;
    }

    char *Get() {
        return (char *) m_szBuf;
    }

    int Size() const {
        return sizeof(m_szBuf);
    }

    int MaxSize() const {
        return sizeof(m_szBuf);
    }

    template<typename... ARGS>
    int Format(const char *my_fmt, const ARGS &... args) {
        try {
            std::string str = fmt::format(my_fmt, args...);
            return Copy(str);
        }
        catch(fmt::v5::format_error& error) {
            return Copy(my_fmt);
        }
    }

    int Set(const char *szFormat, ...) {
        va_list ap;
        va_start(ap, szFormat);
        int iRet = VSet(szFormat, ap);
        va_end(ap);
        return iRet;
    }

    int VSet(const char *szFormat, va_list ap) {
        if (!szFormat) {
            return -1;
        }

        int iRet = NFSafeVsnprintf(m_szBuf, Size(), szFormat, ap);
        if (iRet < 0) {
            return -1;
        }

        m_szBuf[iRet] = 0;
        return iRet;
    }

    int Cat(const char *szFormat, ...) {
        va_list ap;
        va_start(ap, szFormat);
        int iRet = VCat(szFormat, ap);
        va_end(ap);
        return iRet;
    }

    int VCat(const char *szFormat, va_list ap) {
        if (!szFormat) {
            return -1;
        }

        int iLen = (int) strlen(m_szBuf);
        int iMaxLen = Size() - iLen;
        if (iMaxLen <= 0) { //-V547
			return -1;
		}
		
		int iRet = NFSafeVsnprintf(m_szBuf + iLen, iMaxLen, szFormat, ap);
		if (iRet < 0)
		{
            return -1;
        }

        iRet += iLen;
        m_szBuf[iRet] = 0;
        return iRet;
    }

    int Copy(const NFSizeString &stString) {
        strncpy(m_szBuf, stString.m_szBuf, SIZE - 1);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    template<int SIZE2>
    int Copy(const NFSizeString<SIZE2> &stString) {
        int len = Size() - 1 > stString.Size() - 1 ? stString.Size() - 1 : Size() - 1;
        strncpy(m_szBuf, stString.GetBuffer(), len);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    int Copy(const std::string &stString) {
        strncpy(m_szBuf, stString.c_str(), SIZE - 1);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    void Clear()
    {
	    memset(m_szBuf, 0, SIZE);
    }

    std::string GetString() const {
	    return std::string(m_szBuf);
	}
private:
    char m_szBuf[SIZE];
};

/**
* 定长的字符串封装
*/
template<int SIZE = 1024>
class NFSizeBuffer { //-V690
public:
    NFSizeBuffer() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        m_iSize = 0;
        memset(m_szBuf, 0, SIZE);
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    ~NFSizeBuffer() {
    }

    NFSizeBuffer &operator=(const NFSizeBuffer &obj) {
        Copy(obj);
        return *this;
    }

    NFSizeBuffer &operator=(const std::string &obj) {
        Copy(obj);
        return *this;
    }

    const char &operator[](int i) const {
        return m_szBuf[i];
    }

    char &operator[](int i) {
        return m_szBuf[i];
    }

    char *GetBuffer() const {
        return Get();
    }

    int GetBufferLen() const {
        return Size();
    }

    char *Get() const {
        return (char *) m_szBuf;
    }

    int Size() const {
        return m_iSize;
    }

    int GetMaxSize() const {
        return SIZE;
    }

    int Copy(const NFSizeBuffer &stString) {
        if (this != &stString) {
            memcpy(m_szBuf, stString.GetBuffer(), stString.GetBufferLen());
            m_iSize = stString.GetBufferLen();
        }
        return 0;
    }

    template<int SIZE2>
    int Copy(const NFSizeBuffer<SIZE2> &stString) {
        int len = stString.Size() > SIZE ? SIZE : stString.Size();
        memcpy(m_szBuf, stString.Get(), len);
        m_iSize = len;
        return 0;
    }

    int Copy(const std::string &stString) {
        int len = stString.length() > SIZE ? SIZE : stString.length();
        memcpy(m_szBuf, stString.data(), len);
        m_iSize = len;
        return 0;
    }

private:
    int m_iSize;
    char m_szBuf[SIZE];
};

