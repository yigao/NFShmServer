// -------------------------------------------------------------------------
//    @FileName         :    NFShmString.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFShmDefine.h"
#include "NFShmMgr.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
* 定长的字符串封装
*/
template<int SIZE = 1024>
class NFShmString //-V690
{
public:
    NFShmString()
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

    NFShmString(const std::string &str)
    {
        Copy(str);
    }

    NFShmString(const NFShmString &str)
    {
        Copy(str);
    }

    template<int SIZE2>
    NFShmString(const NFShmString<SIZE2> &str)
    {
        Copy(str);
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

    ~NFShmString()
    {
    }

    bool operator==(const char *pstr) const
    {
        return strcmp(Get(), pstr) == 0;
    }

    bool operator==(const std::string &str) const
    {
        return strcmp(Get(), str.c_str()) == 0;
    }

    bool operator==(const NFShmString &obj) const
    {
        return strcmp(Get(), obj.Get()) == 0;
    }

    NFShmString &operator=(const NFShmString &obj)
    {
        Copy(obj);
        return *this;
    }

    NFShmString &operator=(const std::string &obj)
    {
        Copy(obj);
        return *this;
    }

    template<int SIZE2>
    NFShmString &operator=(const NFShmString<SIZE2> &str)
    {
        Copy(str);
        return *this;
    }

    char *operator()() const
    {
        return Get();
    }

    const char &operator[](int i) const
    {
        return m_szBuf[i];
    }

    char &operator[](int i)
    {
        return m_szBuf[i];
    }

    const char *Data() const
    {
        return Get();
    }

    char *Data()
    {
        return Get();
    }

    const char *Get() const
    {
        return (const char *) m_szBuf;
    }

    char *Get()
    {
        return (char *) m_szBuf;
    }

    int Capacity() const
    {
        return MaxSize();
    }

    int MaxSize() const
    {
        return sizeof(m_szBuf);
    }

    int Length() const
    {
        return (int) strlen(Get());
    }

    void SetLength(int iLen)
    {
        m_szBuf[iLen] = '\0';
    }

    int Size() const
    {
        return (int) strlen(Get());
    }

    void SetSize(int iLen)
    {
        SetLength(iLen);
    }

    template<typename... ARGS>
    int Format(const char *my_fmt, const ARGS &... args)
    {
        try
        {
            std::string str = fmt::format(my_fmt, args...);
            return Copy(str);
        }
        catch (fmt::v5::format_error &error)
        {
            return Copy(my_fmt);
        }
    }

    int Set(const char *szFormat, ...)
    {
        va_list ap;
        va_start(ap, szFormat);
        int iRet = VSet(szFormat, ap);
        va_end(ap);
        return iRet;
    }

    int VSet(const char *szFormat, va_list ap)
    {
        if (!szFormat)
        {
            return -1;
        }

        int iRet = NFSafeVsnprintf(m_szBuf, MaxSize(), szFormat, ap);
        if (iRet < 0)
        {
            return -1;
        }

        m_szBuf[iRet] = 0;
        return iRet;
    }

    int Cat(const char *szFormat, ...)
    {
        va_list ap;
        va_start(ap, szFormat);
        int iRet = VCat(szFormat, ap);
        va_end(ap);
        return iRet;
    }

    int VCat(const char *szFormat, va_list ap)
    {
        if (!szFormat)
        {
            return -1;
        }

        int iLen = (int) strlen(m_szBuf);
        int iMaxLen = MaxSize() - iLen;
        if (iMaxLen <= 0)
        { //-V547
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

    int Copy(const NFShmString &stString)
    {
        strncpy(m_szBuf, stString.m_szBuf, SIZE - 1);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    template<int SIZE2>
    int Copy(const NFShmString<SIZE2> &stString)
    {
        int len = MaxSize() - 1 > stString.MaxSize() - 1 ? stString.MaxSize() - 1 : MaxSize() - 1;
        strncpy(m_szBuf, stString.Data(), len);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    int Copy(const std::string &stString)
    {
        strncpy(m_szBuf, stString.c_str(), SIZE - 1);
        m_szBuf[SIZE - 1] = '\0';
        return 0;
    }

    void Clear()
    {
        memset(m_szBuf, 0, SIZE);
    }

    std::string GetString() const
    {
        return std::string(m_szBuf);
    }

    std::string ToString() const
    {
        return GetString();
    }

private:
    char m_szBuf[SIZE];
};

/**
* 定长的字符串封装
*/
template<int SIZE = 1024>
class NFSizeBuffer
{ //-V690
public:
    NFSizeBuffer()
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
        m_iSize = 0;
        memset(m_szBuf, 0, SIZE);
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    ~NFSizeBuffer()
    {
    }

    NFSizeBuffer &operator=(const NFSizeBuffer &obj)
    {
        Copy(obj);
        return *this;
    }

    NFSizeBuffer &operator=(const std::string &obj)
    {
        Copy(obj);
        return *this;
    }

    const char &operator[](int i) const
    {
        return m_szBuf[i];
    }

    char &operator[](int i)
    {
        return m_szBuf[i];
    }

    char *GetBuffer() const
    {
        return Get();
    }

    int GetBufferLen() const
    {
        return Size();
    }

    char *Get() const
    {
        return (char *) m_szBuf;
    }

    int Size() const
    {
        return m_iSize;
    }

    int GetMaxSize() const
    {
        return SIZE;
    }

    int Copy(const NFSizeBuffer &stString)
    {
        if (this != &stString)
        {
            memcpy(m_szBuf, stString.GetBuffer(), stString.GetBufferLen());
            m_iSize = stString.GetBufferLen();
        }
        return 0;
    }

    template<int SIZE2>
    int Copy(const NFSizeBuffer<SIZE2> &stString)
    {
        int len = stString.Size() > SIZE ? SIZE : stString.Size();
        memcpy(m_szBuf, stString.Get(), len);
        m_iSize = len;
        return 0;
    }

    int Copy(const std::string &stString)
    {
        int len = stString.length() > SIZE ? SIZE : stString.length();
        memcpy(m_szBuf, stString.data(), len);
        m_iSize = len;
        return 0;
    }

private:
    int m_iSize;
    char m_szBuf[SIZE];
};

/**
*@brief 求hash值
*/
namespace std
{
    template<int SIZE>
    struct hash<NFShmString < SIZE>>
{
    size_t operator()(const NFShmString <SIZE> &eventKey) const
    {
        return std::hash<std::string>()(eventKey.ToString());
    }
};
}

