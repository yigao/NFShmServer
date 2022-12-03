// -------------------------------------------------------------------------
//    @FileName         :    NFCommonApi.h
//    @Author           :    gaoyi
//    @Date             :    22-12-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommonApi
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"

#include <stdint.h>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <utility>
#include <functional>
#include <cctype>
#include <stdio.h>
#include <assert.h>
#ifdef _MSC_VER
#pragma warning(disable:4127)
#endif


#ifndef  ALIGN
#define  ALIGN(SIZE, BOUNDARE)   (((SIZE) + ((BOUNDARE) -1)) &~((BOUNDARE) - 1))
#endif  // ALIGN

// Rotation
#define ROL8(n, r)  (((n) << (r)) | ((n) >> (8 - (r))))   // only works for u8
#define ROR8(n, r)  (((n) >> (r)) | ((n) << (8 - (r))))   // only works for u8
#define ROL16(n, r) (((n) << (r)) | ((n) >> (16 - (r))))  // only works for u16
#define ROR16(n, r) (((n) >> (r)) | ((n) << (16 - (r))))  // only works for u16
#define ROL32(n, r) (((n) << (r)) | ((n) >> (32 - (r))))  // only works for u32
#define ROR32(n, r) (((n) >> (r)) | ((n) << (32 - (r))))  // only works for u32

template<typename TYPE>
TYPE TMIN(TYPE a, TYPE b)
{
    return (a < b ? a : b);
}

template<typename TYPE>
TYPE TMAX(TYPE a, TYPE b)
{
    return (a > b ? a : b);
}

template<bool tagBool>
struct Bool2Type
{
    enum {Value = tagBool};
};

class NFCommonApi
{
public:
    static uint32_t UpToPower2(uint32_t x)
    {
        x = x - 1;
        x = x | (x >> 1);
        x = x | (x >> 2);
        x = x | (x >> 4);
        x = x | (x >> 8);
        x = x | (x >> 16);
        return x + 1;
    }

    static int SplitStr(const std::string& str,
                        const std::string& delimiter,
                        std::vector<std::string>* result)
    {
        result->clear();
        if(str.empty()) return 0;

        size_t iIndex=0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex    = str.find(delimiter, iOldIndex+1);
            if (iOldIndex == 0)
            {
                result->push_back(str.substr(0, iIndex));
                continue;
            }

            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->push_back(str.substr(iOldIndex));
                continue;
            }
            result->push_back(str.substr(iOldIndex, iIndex - iOldIndex));
        }
        return static_cast<int>(result->size());
    }

    static int SplitStrToVecInt(const std::string& str,
                                const std::string& delimiter,
                                std::vector<int32_t>* result)
    {
        result->clear();
        if (str.empty()) return 0;

        size_t iIndex = 0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex = str.find(delimiter, iOldIndex + 1);
            if (iOldIndex == 0)
            {
                result->push_back(StrToInt(str.substr(0, iIndex)));
                continue;
            }

            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->push_back(StrToInt(str.substr(iOldIndex)));
                continue;
            }
            result->push_back(StrToInt(str.substr(iOldIndex, iIndex - iOldIndex)));
        }
        return static_cast<int>(result->size());
    }
    static int SplitStrToSetInt(const std::string& str,
                                const std::string& delimiter,
                                std::unordered_set<int32_t>* result)
    {
        result->clear();
        if (str.empty()) return 0;

        size_t iIndex = 0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex = str.find(delimiter, iOldIndex + 1);
            if (iOldIndex == 0)
            {
                result->insert(StrToInt(str.substr(0, iIndex)));
                continue;
            }

            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->insert(StrToInt(str.substr(iOldIndex)));
                continue;
            }
            result->insert(StrToInt(str.substr(iOldIndex, iIndex - iOldIndex)));
        }
        return static_cast<int>(result->size());
    }

    static int SplitStrToSetInt(const std::string& str,
                                const std::string& delimiter,
                                std::unordered_set<int64_t>* result)
    {
        result->clear();
        if (str.empty()) return 0;

        size_t iIndex = 0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex = str.find(delimiter, iOldIndex + 1);
            if (iOldIndex == 0)
            {
                result->insert(StrToInt64(str.substr(0, iIndex)));
                continue;
            }

            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->insert(StrToInt64(str.substr(iOldIndex)));
                continue;
            }
            result->insert(StrToInt64(str.substr(iOldIndex, iIndex - iOldIndex)));
        }
        return static_cast<int>(result->size());
    }

    static int SplitStrToVecInt(const std::string& str,
                                const std::string& delimiter,
                                std::vector<int64_t>* result)
    {
        result->clear();
        if (str.empty()) return 0;

        size_t iIndex = 0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex = str.find(delimiter, iOldIndex + 1);
            if (iOldIndex == 0)
            {
                result->push_back(StrToInt64(str.substr(0, iIndex)));
                continue;
            }

            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->push_back(StrToInt64(str.substr(iOldIndex)));
                continue;
            }
            result->push_back(StrToInt64(str.substr(iOldIndex, iIndex - iOldIndex)));
        }
        return static_cast<int>(result->size());
    }

    static int SplitStrToVecFloat(const std::string& str,
                                  const std::string& delimiter,
                                  std::vector<float>* result)
    {
        result->clear();
        if (str.empty()) return 0;

        size_t iIndex = 0, iOldIndex;
        while (iIndex != std::string::npos && iIndex != (size_t)-1)
        {
            iOldIndex = iIndex;
            iIndex = str.find(delimiter, iOldIndex + 1);
            if (iOldIndex == 0 && iIndex == std::string::npos)
            {
                result->push_back((float)atof(str.c_str()));
                break;
            }
            else if (iOldIndex == 0)
            {
                result->push_back((float)atof(str.substr(0, iIndex).c_str()));
                continue;
            }


            iOldIndex += delimiter.length();
            if (iIndex == std::string::npos || iIndex == (size_t)-1)
            {
                result->push_back((float)atof(str.substr(iOldIndex).c_str()));
                continue;
            }
            result->push_back((float)atof(str.substr(iOldIndex, iIndex - iOldIndex).c_str()));
        }
        return static_cast<int>(result->size());
    }

    static std::vector< std::string > SplitStr(const std::string& s, const std::string& delim, const bool keep_empty)
    {
        std::vector< std::string > result;

        if (delim.empty()) {
            result.push_back(s);
            return result;
        }

        std::string::const_iterator substart = s.begin();
        std::string::const_iterator subend;

        while (true) {
            subend = std::search(substart, s.end(), delim.begin(), delim.end());
            std::string temp(substart, subend);
            if (keep_empty || !temp.empty()) {
                result.push_back(temp);
            }
            if (subend == s.end()) {
                break;
            }
            substart = subend + delim.size();
        }

        return result;
    }

    /*
    ת��Ϊ��д
    */
    static char* StrToUpper(char* s)
    {
        assert(s != NULL);

        while (*s)
        {
            *s = (char)toupper((unsigned char)*s);
            s++;
        };

        return s;
    }

    /*
    ת��ΪСд
    */
    static char* StrToLower(char* s)
    {
        assert(s != NULL);

        while (*s)
        {
            *s = (char)tolower((unsigned char)*s);
            s++;
        };

        return s;
    }

    static int Byte2String(unsigned char *src, int srcsize, unsigned char *dst, int dstsize)
    {
        if (dst != NULL)
        {
            *dst = 0;
        }

        if (src == NULL || srcsize <= 0 || dst == NULL || dstsize <= srcsize * 2)
        {
            return 0;
        }

        const char szTable[] = "0123456789ABCDEF";

        for (int i = 0; i < srcsize; ++i)
        {
            *dst++ = szTable[src[i] >> 4];
            *dst++ = szTable[src[i] & 0x0f];
        }

        *dst = 0;
        return  srcsize * 2;
    }

    static int String2Byte(unsigned char* src, unsigned char* dst, int dstsize)
    {
        if (src == NULL)
            return 0;

        int iLen = (int)strlen((char *)src);
        if (iLen <= 0 || iLen % 2 != 0 || dst == NULL || dstsize < iLen / 2)
        {
            return 0;
        }

        iLen /= 2;
        StrToUpper((char *)src);
        for (int i = 0; i < iLen; ++i)
        {
            int iVal = 0;
            unsigned char *pSrcTemp = src + i * 2;

            int ret = sscanf((char *)pSrcTemp, "%02x", &iVal);



            if (ret < 0)
            {
                return 0;
            }
            dst[i] = (unsigned char)iVal;
        }

        return iLen;
    }

    static std::string ToLower(const std::string& str) {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        return t;
    }

    static std::string ToUpper(const std::string& str) {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), ::toupper);
        return t;
    }

    static std::string &StrLTrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    static std::string &StrRTrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }


    static std::string &StrTrim(std::string& s)
    {
        return StrLTrim(StrRTrim(s));
    }

    // �ַ����滻
    static int StrReplace(std::string& str, const std::string& pattern, const std::string& newpat)
    {
        int count = 0;
        const size_t nsize = newpat.size();
        const size_t psize = pattern.size();

        for (size_t pos = str.find(pattern, 0);
             pos != std::string::npos;
             pos = str.find(pattern, pos + nsize))
        {
            str.replace(pos, psize, newpat);
            count++;
        }

        return count;
    }

    static int StrReplace(std::wstring& str, const std::wstring& pattern, const std::wstring& newpat)
    {
        int count = 0;
        const size_t nsize = newpat.size();
        const size_t psize = pattern.size();

        for (size_t pos = str.find(pattern, 0);
             pos != std::wstring::npos;
             pos = str.find(pattern, pos + nsize))
        {
            str.replace(pos, psize, newpat);
            count++;
        }

        return count;
    }
    static float StrToFloat(const std::string& str)
    {
        return (float)atof(str.c_str());

    }
    static int StrToInt(const std::string& str)
    {
        return atoi(str.c_str());
    }
    static int64_t StrToInt64(const std::string& str)
    {
        return atoll(str.c_str());
    }

    static char* WChar2Char(const wchar_t* ts, size_t* outlen)
    {
        int len = (int)((wcslen(ts) + 1) * sizeof(wchar_t));
        char* ccattr = (char *)malloc(len);
        if (ccattr == nullptr)
        {
            return nullptr;
        }
        memset(ccattr, 0, len);

        size_t slen = wcstombs(ccattr, ts, len);

        if (outlen)
        {
            if ((size_t)-1 != slen)
                *outlen = slen;
            else
                *outlen = 0;
        }

        return ccattr;
    };
};