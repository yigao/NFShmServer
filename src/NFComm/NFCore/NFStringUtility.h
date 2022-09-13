// -------------------------------------------------------------------------
//    @FileName         :    NFStringUtility.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <cstring>
#include <ctype.h>
#include <wctype.h>
#include <iostream>
#include "NFSlice.hpp"
#include "NFPlatform.h"
#if NF_PLATFORM == NF_PLATFORM_WIN
#else
#include <iconv.h>
#endif


class _NFExport NFStringUtility
{
public:
	static const std::string kEmpty;
public:
	//  @brief Removes any whitespace characters, which are one of them
	//       " " (ASCII 32 (0x20)) SPACE
	//       "\t" (ASCII 9 (0x09)) tab
	//       "\n" (ASCII 10 (0x0A)) new line
	//       "\r" (ASCII 13 (0x0D)) carriage ret
	//       "\0" (ASCII 0 (0x00)) NUL
	//       "\v" (ASCII 11 (0x0B)) vertical tab
	//     The user may specify whether they want to trim only the
	//    beginning or the end of the String ( the default action is
	//    to trim both).
	//  @param str[in,out], the source string, and the result will stored in it.
	//  @param cutset[in], all leading and trailing characters contained in cutset will be removed.
	//  @param left, trim the beginning of the string
	//  @param right, trim the end of the string
    static void Trim(std::vector<std::string>& vecStr);
	static void Trim(std::string& str, bool left = true, bool right = true);
	static void Trim(std::wstring& str, bool left = true, bool right = true);
	static void Trim(std::string& str, const std::string& cutset, bool left = true, bool right = true);
	static void Trim(std::wstring& str, const std::wstring& cutset, bool left = true, bool right = true);
	static void Trim(std::string& str, const char* cutset, bool left = true, bool right = true);
	static void Trim(std::wstring& str, const wchar_t* cutset, bool left = true, bool right = true);

	static void TrimLeft(std::string& str)
	{
		Trim(str, true, false);
	}

	static void TrimLeft(std::wstring& str)
	{
		Trim(str, true, false);
	}

	static void TrimLeft(std::string& str, const std::string& delims)
	{
		Trim(str, delims, true, false);
	}

	static void TrimLeft(std::wstring& str, const std::wstring& delims)
	{
		Trim(str, delims, true, false);
	}

	static void TrimLeft(std::string& str, const char* delims)
	{
		Trim(str, delims, true, false);
	}

	static void TrimLeft(std::wstring& str, const wchar_t* delims)
	{
		Trim(str, delims, true, false);
	}

	static void TrimRight(std::string& str)
	{
		Trim(str, false, true);
	}

	static void TrimRight(std::wstring& str)
	{
		Trim(str, false, true);
	}

	static void TrimRight(std::string& str, const std::string& delims)
	{
		Trim(str, delims, false, true);
	}

	static void TrimRight(std::wstring& str, const std::wstring& delims)
	{
		Trim(str, delims, false, true);
	}

	static void TrimRight(std::string& str, const char* delims)
	{
		Trim(str, delims, false, true);
	}

	static void TrimRight(std::wstring& str, const wchar_t* delims)
	{
		Trim(str, delims, false, true);
	}

	// @brief trim a char
	template <class _StringType>
	static void Trim(_StringType& str, char c, bool left = true, bool right = true);

	template <class _StringType>
	static void TrimLeft(_StringType& str, char c)
	{
		Trim(str, c, true, false);
	}

	template <class _StringType>
	static void TrimRight(_StringType& str, char c)
	{
		Trim(str, c, false, true);
	}

	// @brief Replaces a section equaling to <code>needle</code> of the current string with the new substring <code>new_value</code>
	// @param string & str [in,out], -
	// @param const string & needle -
	// @param const string & new_value -
	// @param string::size_type start_pos -
	// @param int replace_count - If it is -1, replaces all the <code>needle</code> by <code>new_value</code>
	// @return void -
	static void Replace(std::string& str, const std::string& needle, const std::string& new_value, size_t start_pos = 0, int replace_count = -1);
	static void Replace(std::wstring& str, const std::wstring& needle, const std::wstring& new_value, size_t start_pos = 0, int replace_count = -1);

	// Returns a StringVector that contains all the substrings delimited
	// by any of the characters in the passed <code>delims</code> argument.
	// @param vec[out], the result substrings are stored here.
	// @param delims A list of delimiter characters to split by
	// @param max_splits The maximum number of splits to perform (0 for unlimited splits). If this
	//     parameters is > 0, the splitting process will stop after this many splits, left to right.
	static void Split(std::vector<std::string>& vec, const std::string& str, const std::string& cutset = "\t\n ", unsigned int max_splits = 0);
	static void Split(std::vector<std::wstring>& vec, const std::wstring& str, const std::wstring& cutset = L"\t\n ", unsigned int max_splits = 0);

	static void Split(std::vector<std::string>& vec, const std::string& str, const std::string::value_type& cutset, unsigned int max_splits = 0);
	static void Split(std::vector<std::wstring>& vec, const std::wstring& str, const std::wstring::value_type& cutset, unsigned int max_splits = 0);

	static void Split(std::vector<NFSlice>& vec, const std::string& str, int cutset, unsigned int max_splits = 0);
	static void Split(std::vector<NFSlice>& vec, const std::string& str, const std::string& cutset = "\t\n ", unsigned int max_splits = 0);

	// @brief
	//   <code>
	//     string s = "a|b|c|d|e";
	//     Slice v[2];
	//     Split(s, '|', v, 2);  //after Split, v[0]=="a", v[1] == "b|c|d|e", vc == 2
	//   </code>
	//
	//   <code>
	//     string s = "a|b|c";
	//     Slice v[8];
	//     Split(s, '|', v, 8);  //after Split, v[0]=="a", v[1] == "b", v[2] == "c", vc == 3
	//   </code>
	// @param const string & str -
	// @param int delims -
	// @param[out] Slice slices[] -
	// @param[in,out] size_t & slice_count -
	// @return void -
	static void Split(const std::string& str, int cutset, NFSlice slices[], size_t& slice_count);
	static void Split(const std::string& str, const string& cutset, NFSlice slices[], size_t& slice_count);
	static void Split(const NFSlice& str, int cutset, NFSlice slices[], size_t& slice_count);
	static void Split(const NFSlice& str, int cutset, std::vector<NFSlice>& slices, unsigned int max_splits = 0);

	/**
	* Split a string into tow strings using the special characters .
	* e.g. src="abc, hello world "  if cutset="," then left="abc", right=" hello world "
	* @warning If any of delimiters was found, we just return, left string and right string will not be changed.
	* @param src The source string
	* @param left The left string separated by cutset
	* @param left The right string separated by cutset
	* @param cutset A list of delimiter characters to split by. We only use the first one when come up against a delimiter
	*/
	static void Split(const std::string& src, std::string& left, std::string& right, const std::string& cutset = "\t\n ");
	static void Split(const std::wstring& src, std::wstring& left, std::wstring& right, const std::wstring& cutset = L"\t\n ");
	static void Split(const std::string& src, std::string& left, std::string& right, const char* cutset = "\t\n ");
	static void Split(const std::wstring& src, std::wstring& left, std::wstring& right, const wchar_t* cutset = L"\t\n ");

	template <class _SourceStringType, class _SubStringType>
	static void Explode(const _SourceStringType& source, const _SourceStringType& cutset, std::vector<_SubStringType>& return_value, int limit = -1);

	static void ToLower(std::string& str);
	static void ToLower(std::wstring& str);
	static void ToUpper(std::string& str);
	static void ToUpper(std::wstring& str);

	// string compare
	// @param case_sensitive true If we compare the string with case sensitively
	static bool Equals(const std::string& str1, const std::string& str2, bool case_sensitive = true);

	// @brief string compare ignoring case sensitively
	static bool EqualsIgnoreCase(const std::string& str1, const std::string& str2);

	static std::string Rot13(const std::string& val);
	static std::string Rot13(const char* str, size_t len);

	// @brief     Returns whether the string begins with the pattern passed in.
	// @param[in] pattern The pattern to compare with.
	// @param[in] case_sensitive true case sensitive, false ignore the case
	static bool StartsWith(const std::string& str, const std::string& pattern, bool case_sensitive = true);
	static bool StartsWith(const std::wstring& str, const std::wstring& pattern, bool case_sensitive = true);

	// @brief     Returns whether the string ends with the pattern passed in.
	// @param[in] pattern The pattern to compare with.
	// @param[in] case_sensitive true case sensitive, false ignore the case
	static bool EndsWith(const std::string& str, const std::string& pattern, bool case_sensitive = true);
	static bool EndsWith(const std::wstring& str, const std::wstring& pattern, bool case_sensitive = true);

	// Simple pattern-matching routine allowing a wild card pattern.
	// @param str String to test
	// @param pattern Pattern to match against; which can include simple '*' wildcards
	// @param case_sensitive Whether the match is case sensitive or not
	static bool Match(const std::string& str, const std::string& pattern, bool case_sensitive = true);
	static bool Match(const std::wstring& str, const std::wstring& pattern, bool case_sensitive = true);

	// @brief Reports whether a char or a substr is within mother
	// @param mother, the mother string to test
	// @param pattern, the pattern string or char to find
	// @param[in] case_sensitive true case sensitive, false ignore the case
	// @return bool, return true if the occurrence of pattern within the motherStr or false
	static bool Contains(const std::string& mother, char pattern, bool case_sensitive = true);
	static bool Contains(const std::wstring& mother, wchar_t pattern, bool case_sensitive = true);
	static bool Contains(const std::string& mother, const std::string& pattern, bool case_sensitive = true);
	static bool Contains(const std::wstring& mother, const std::wstring& pattern, bool case_sensitive = true);

	// @brief This function is convenient when encoding a string
	//     to be used in a query part of a URL, as a convenient way
	//     to pass variables to the next page
	// @param const char * url -
	// @param size_t url_len -
	// @param[in] char * edcoded_url -
	// @param[in,out] size_t & edcoded_url_len -
	// @return bool -
	static bool URLEncode(const char* url, size_t url_len, char* edcoded_url, size_t& edcoded_url_len);

	static std::string URLEncode(const std::string& str)
	{
		std::string out;
		URLEncode(str, out);
		return out;
	}

	static void URLEncode(const std::string& str, std::string& out)
	{
		URLEncode(str.data(), str.size(), out);
	}

	static void URLEncode(const char* url, size_t url_len, std::string& out);

	static string URLDecode(const std::string& str)
	{
		std::string out;
		URLDecode(str, out);
		return out;
	}

	static void URLDecode(const std::string& str, std::string& out);
	static void URLDecode(const char* encoded_url, size_t encoded_url_len, std::string& out);
	static void URLDecode(const char* encoded_url, size_t encoded_url_len, char* decoded_url, size_t& decoded_url_len);

	static void URLDecode(std::string& str)
	{
		URLDecode(str, str);
	}

	// query whether parameter string is a float number string or not.
	static bool IsFloatNumber(std::string& s);

	static void Split(const std::string& str,
	                  const std::string& delim,
	                  std::vector<std::string>* result);

	static std::string& Ltrim(std::string& str); // NOLINT

	static std::string& Rtrim(std::string& str); // NOLINT

	static std::string& LRTrim(std::string& str); // NOLINT

	static void LRTrim(std::vector<std::string>* str_list);

	// 子串替换
	static void StringReplace(const std::string& sub_str1,
	                          const std::string& sub_str2, std::string* str);

	static void UrlEncode(const std::string& src_str, std::string* dst_str);

	static void UrlDecode(const std::string& src_str, std::string* dst_str);

	// 大小写转换
	static void ToUpper(std::string* str);

	static void ToLower(std::string* str);

	static std::string ToLower(const std::string& str);

	// 去头去尾
	static bool StripSuffix(std::string* str, const std::string& suffix);

	static bool StripPrefix(std::string* str, const std::string& prefix);

	// bin和hex转换
	static bool Hex2Bin(const char* hex_str, std::string* bin_str);

	static bool Bin2Hex(const char* bin_str, std::string* hex_str);

	static std::string Format(std::string sz, ...);

	// Return a C++ string
	static std::string StringPrintf(const char* format, ...);

	// Store result into a supplied string and return it
	static const std::string& SStringPrintf(std::string* dst, const char* format, ...);

	// Append result to a supplied string
	static void StringAppendF(std::string* dst, const char* format, ...);

	// Lower-level routine that takes a va_list and appends to a specified
	// string.  All other routines are just convenience wrappers around it.
	static void StringAppendV(std::string* dst, const char* format, va_list ap);

	/**
	 * @brief 获得typeinfo.name(T)的类型名字
	 *
	 * @param name  对类型T,获得typeinfo<T>.name()的名字
	 * @return      获得typeinfo.name(T)的类型名字
	 */
	static std::string Demangle(const std::string& name);

	/*
	*/
	static bool IsUTF8String(const std::string& str);

	/**
	 * @brief 获得类型T的类型名字
	 *
	 * @return      获得typeinfo.name(T)的类型名字
	 */
	template <class T>
	static std::string GetTypeName()
	{
		return Demangle(typeid(T).name());
	}

#if NF_PLATFORM == NF_PLATFORM_WIN
	static std::string ws2s(const std::wstring &ws)
	{
		size_t i;
		std::string curLocale = setlocale(LC_ALL, NULL);
		setlocale(LC_ALL, "chs");
		const wchar_t* _source = ws.c_str();
		size_t _dsize = 2 * ws.size() + 1;
		char* _dest = new char[_dsize];
		memset(_dest, 0x0, _dsize);
		wcstombs_s(&i, _dest, _dsize, _source, _dsize);
		std::string result = _dest;
		delete[] _dest;
		setlocale(LC_ALL, curLocale.c_str());
		return result;
	}

	static std::wstring s2ws(const std::string &s)
	{
		size_t i;
		std::string curLocale = setlocale(LC_ALL, NULL);
		setlocale(LC_ALL, "chs");
		const char* _source = s.c_str();
		size_t _dsize = s.size() + 1;
		wchar_t* _dest = new wchar_t[_dsize];
		wmemset(_dest, 0x0, _dsize);
		mbstowcs_s(&i, _dest, _dsize, _source, _dsize);
		std::wstring result = _dest;
		delete[] _dest;
		setlocale(LC_ALL, curLocale.c_str());
		return result;
	}
#endif

	static char* wchar2char(const wchar_t* ts, size_t* outlen)
	{
		int len = (int)((wcslen(ts) + 1) * sizeof(wchar_t));
		char* ccattr = (char *)malloc(len);
		if (ccattr == NULL) return NULL;
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

	static wchar_t* char2wchar(const char* cs, size_t* outlen)
	{
		int len = (int)((strlen(cs) + 1) * sizeof(wchar_t));
		wchar_t* ccattr = (wchar_t *)malloc(len);
		if (ccattr == NULL) return NULL;
		memset(ccattr, 0, len);

		size_t slen = mbstowcs(ccattr, cs, len);

		if (outlen)
		{
			if ((size_t)-1 != slen)
				*outlen = slen;
			else
				*outlen = 0;
		}

		return ccattr;
	};

	//字符集转换
	static string GBKToUTF8(const std::string& strGBK)
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		wchar_t* str1;
		int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
		str1 = new wchar_t[n];
		MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
		n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
		char * str2 = new char[n];
		WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
		string strOutUTF8(str2);
		delete[]str1;
		str1 = NULL;
		delete[]str2;
		str2 = NULL;
		return strOutUTF8;
#else

		if (strGBK.empty())
		{
			return "";
		}
		iconv_t cd = iconv_open("UTF-8", "GB18030");
		size_t inlen = strGBK.length();
		char *outbuf = (char *)malloc(inlen * 4);
		bzero(outbuf, inlen * 4);
		const char *in = strGBK.c_str();
		char *out = outbuf;
		size_t outlen = inlen * 4;
		if (iconv(cd, (char**)&in, (size_t *)&inlen, &out, &outlen) == (size_t)-1)
		{
			int nErr = errno;
			switch (nErr)
			{
			case E2BIG:
			{
				printf("errno:E2BGI（OutBuf空间不够）\n");
				break;
			}
			case EILSEQ:
			{
				printf("errno:EILSEQ（InBuf多字节序无效）\n");
				break;
			}
			case EINVAL:
			{
				printf("errno:EINVAL（有残留的字节未转换）\n");
				break;
			}
			default:
				break;
			}
			free(outbuf);
			iconv_close(cd);
			return "";
		}
		else
		{
			outlen = strlen(outbuf);
			string strOutUTF8(outbuf);
			free(outbuf);
			iconv_close(cd);
			return strOutUTF8;
		}

		return std::string();
#endif
	}

	//utf-8 转 gbk
	static string UTF8ToGBK(const std::string& strUTF8)
	{
#if NF_PLATFORM == NF_PLATFORM_WIN
		int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
		unsigned short * wszGBK = new unsigned short[len + 1];
		//wchar_t * wszGBK = new wchar_t[len+1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, (const char*)strUTF8.c_str(), -1, (LPWSTR)wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
		char *szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, szGBK, len, NULL, NULL);
		string strTemp(szGBK);
		delete[]szGBK;
		delete[]wszGBK;
		return strTemp;
#else
		iconv_t cd = iconv_open("gb18030", "utf-8");
		size_t inlen = strUTF8.length();
		char *outbuf = (char *)malloc(inlen * 4);
		bzero(outbuf, inlen * 4);
		const char *in = strUTF8.c_str();
		char *out = outbuf;
		size_t outlen = inlen * 4;
		if (iconv(cd, (char**)&in, (size_t *)&inlen, &out, &outlen) == (size_t)-1)
		{
			int nErr = errno;
			switch (nErr)
			{
			case E2BIG:
			{
				printf("errno:E2BGI（OutBuf空间不够）\n");
				break;
			}
			case EILSEQ:
			{
				printf("errno:EILSEQ（InBuf多字节序无效）\n");
				break;
			}
			case EINVAL:
			{
				printf("errno:EINVAL（有残留的字节未转换）\n");
				break;
			}
			default:
				break;
			}
			free(outbuf);
			iconv_close(cd);
			return "";
		}
		else
		{
			outlen = strlen(outbuf);
			string strOutGBK(outbuf);
			free(outbuf);
			iconv_close(cd);
			return strOutGBK;
		}
		return std::string();
#endif
	}

	static bool IsDigital(const std::string &s)
	{
		size_t len = s.length();
		size_t i = 0;
		for (; i < len; ++i)
		{
			if (s[i] < '0' || s[i] > '9')
			{
				return false;
			}
		}

		return i ? true : false;
	}

	static bool IsDigital_2(const std::string &s)
	{
		size_t len = s.length();
		size_t i = 0;
		for (; i < len; ++i)
		{
			if (i == 0 && s[0] == '-')
			{
				continue;
			}
			if (s[i] < '0' || s[i] > '9')
			{
				return false;
			}
		}

		return i ? true : false;
	}

	static time_t StringToUnixTime(const char *str)
	{
		tm tm_;
		int year = 1900, month = 1, day = 0, hour = 0, minute = 0, second = 0;
		sscanf(str, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
		tm_.tm_year = year - 1900;
		tm_.tm_mon = month - 1;
		tm_.tm_mday = day;
		tm_.tm_hour = hour;
		tm_.tm_min = minute;
		tm_.tm_sec = second;
		tm_.tm_isdst = 0;

		return mktime(&tm_); //已经减了8个时区  
	}

	static bool CheckIsDigit(const std::string& str)
	{
		size_t nCount = str.length(); // 获得字符个数
		for (size_t i = 0; i < nCount; i++)
		{
			if (0 == isdigit(str.at(i))) // 不是数字就置标志位
			{
				return false;
			}
		}
		return true;
	}

	static std::string RemoveSpace(const std::string & str)
	{
		std::string sNew;

		for (size_t i = 0; i < str.size(); ++i)
		{
			if (/*str[i] == ' ' || */str[i] == '\n' || str[i] == '\r')
			{
				continue;
			}

			sNew.push_back(str[i]);
		}

		return sNew;
	}

	static time_t GetTimeStamp(uint32_t uiYear, uint32_t uiMon, uint32_t uiDay, uint32_t uiHour = 0, uint32_t uiMin = 0, uint32_t uiSec = 0)
	{
		tm tm_;
		tm_.tm_year = uiYear - 1900;
		tm_.tm_mon = uiMon - 1;
		tm_.tm_mday = uiDay;
		tm_.tm_hour = uiHour;
		tm_.tm_min = uiMin;
		tm_.tm_sec = uiSec;
		tm_.tm_isdst = 0;
		return  mktime(&tm_);
	}

	//获得今天或明天几点几分钟的时间
	static time_t GetDesignatedTime(uint32_t hour, uint32_t min, time_t Destime, bool isCurrDay)
	{
		hour = hour > 0 ? hour : 0;
		min = min > 0 ? min : 0;
		uint32_t sec = 0;
		hour = hour < 24 ? hour : (hour % 24);
		min = min < 60 ? min : (min % 60);

		time_t tmpTime = Destime > 0 ? Destime : time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		tmpTime += hour * 3600 + min * 60 + sec;

		if (isCurrDay)
		{
			return tmpTime;
		}
		else
			return tmpTime + 24 * 3600;
	}

	//获得今天或明天几点几分钟的时间
	//参数 intraday 判断是不是只计算当天的 某时刻
	static time_t GetNextTime(int32_t hour, int32_t min, int32_t sec, time_t Destime = 0)
	{
		hour = hour > 0 ? hour : 0;
		min = min > 0 ? min : 0;
		sec = sec > 0 ? sec : 0;
		hour = hour < 24 ? hour : (hour % 24);
		min = min < 60 ? min : (min % 60);
		sec = sec < 60 ? sec : (sec % 60);
		time_t tmpTime = Destime > 0 ? Destime : time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		tmpTime += hour * 3600 + min * 60 + sec;

		if (tmpTime > time(NULL))
		{
			return tmpTime;
		}
		return tmpTime + 24 * 3600;
	}

	// 获取整点
	static time_t GetIntPoint()
	{
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		return 3600 - tmp_tm->tm_min * 60 - tmp_tm->tm_sec;
	}

	// 获取0点
	static time_t GetZeroPoint()
	{
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		return 24 * 3600 - tmp_tm->tm_hour * 3600 - tmp_tm->tm_min * 60 - tmp_tm->tm_sec;
	}

	// 获取某个时间戳的当日零点
	static time_t GetOneDayZero(time_t stamp)
	{
		time_t tmpTime = stamp;
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		return tmpTime;
	}

	// 获取今日0点
	static time_t GetTodayZero()
	{
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		return tmpTime;
	}

	// 获取下一个间隔时间距当前时间 还剩多少秒 参数 秒
	// 从0点开始算，除不尽 算0点  比如参数是 600秒 当前是0点59分， 就会返回60秒
	// 参数必须大于0 小于86400否则致命错误
	static time_t GetNextCheckPointTime(uint32_t checkSec)
	{
		if (checkSec <= 0 || checkSec >= 86400) {
			std::cout << "dead error int CommFun.h:429 ";

			return 86400;
		}
		time_t nowTime = time(NULL) - GetTodayZero();
		time_t temTime = checkSec;
		while (temTime < nowTime) {
			temTime += checkSec;
			if (temTime >= 86400) {
				return 86400 - nowTime;
			}
		}
		if (temTime - nowTime <= 1) {
			temTime += checkSec;
		}
		return temTime - nowTime;
	}

	// 获取下一个时间点到当前还剩多少秒， 参数 星期 时分秒
	static time_t GetNextPointGapTick(int weekday, int hour, int min, int sec, time_t basetime = 0)
	{
		weekday -= 1;
		weekday = weekday > 0 ? weekday : 0;
		hour = hour > 0 ? hour : 0;
		min = min > 0 ? min : 0;
		sec = sec > 0 ? sec : 0;
		weekday = weekday < 7 ? weekday : (weekday % 7);
		hour = hour < 24 ? hour : (hour % 24);
		min = min < 60 ? min : (min % 60);
		sec = sec < 60 ? sec : (sec % 60);

		time_t tmpTime = basetime;

		if (tmpTime <= 0)
		{
			tmpTime = time(NULL);
		}

		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		tmpTime += hour * 3600 + min * 60 + sec;

		if (tmp_tm->tm_wday == weekday) {
			if (tmpTime > time(NULL))
			{
				// 同一天 直接减
				return tmpTime - time(NULL);
			}
			else {
				// 目标时间小于当前时间 + 7天
				return tmpTime + 7 * 24 * 3600 - time(NULL);
			}
		}
		else if (tmp_tm->tm_wday < weekday) {
			// 同一个星期， + 间隔天数
			return tmpTime + (weekday - tmp_tm->tm_wday) * 24 * 3600 - time(NULL);
		}
		// 下个星期 +7天 再减天数 再减
		return  tmpTime + (weekday + 7 - tmp_tm->tm_wday) * 24 * 3600 - time(NULL);
	}

	// 获取明日凌晨的时间(今晚24点)
	static time_t GetNextDateTime()
	{
		static time_t nextTime = 0;

		if (nextTime <= time(NULL))
		{
			nextTime = GetNextTime(0, 0, 0);
		}

		return nextTime;
	}

	static bool IsDiffDay(int32_t nTime, int32_t base = 0)
	{
		if (nTime == 0) return true;
		time_t todayTime = base == 0 ? time(NULL) : base;
		time_t targetTime = nTime;
		tm Today, TargetDay;

#ifdef _WIN32
		localtime_s(&Today, &todayTime);
		localtime_s(&TargetDay, &targetTime);
#else
		localtime_r(&todayTime, &Today);
		localtime_r(&targetTime, &TargetDay);
#endif

		if ((Today.tm_yday != TargetDay.tm_yday) || (Today.tm_year != TargetDay.tm_year))
		{
			return true;
		}
		return false;
	}

	// 获取星期
	static int32_t GetWeek()
	{
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		return tmp_tm->tm_wday;
	}

	// 获取这周一0点
	static time_t GetWeekZero()
	{
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		if (tmp_tm->tm_wday == 0)  //周日
		{
			return tmpTime - (6) * 24 * 3600;
		}
		return tmpTime - (tmp_tm->tm_wday - 1) * 24 * 3600;
	}

	static time_t GetWeekendZero()
	{
		return GetWeekZero() + 7 * 24 * 3600;
	}

	// 根据对应时间戳获取周一0点
	static time_t GetWeekZeroByTimeStamp(time_t tmpTime)
	{
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tmpTime -= tmp_tm->tm_hour * 3600 + tmp_tm->tm_min * 60 + tmp_tm->tm_sec;
		return tmpTime - (tmp_tm->tm_wday - 1) * 24 * 3600;
	}

	// 获取本月0点
	static time_t GetMonthZero()
	{
		tm tm_;
		time_t tmpTime = time(NULL);
		tm* tmp_tm = localtime(&tmpTime);
		if (tmp_tm == NULL)
		{
			return 0;
		}
		tm_.tm_year = tmp_tm->tm_year;
		tm_.tm_mon = tmp_tm->tm_mon;
		tm_.tm_mday = 1;
		tm_.tm_hour = 0;
		tm_.tm_min = 0;
		tm_.tm_sec = 0;
		tm_.tm_isdst = 0;

		return mktime(&tm_); //已经减了8个时区  

	}

	static bool IsDiffWeek(time_t nTime)
	{
		time_t monday = GetWeekZero();
		time_t  nextmonday = monday + 7 * 24 * 3600;
		if (nTime >= monday && nTime < nextmonday)
		{
			return false;
		}
		return true;
	}

	//检测字符串中是否含有标点或者特殊字符（不包含中文标点）
	static bool CheckContextHasPunct(const string str)
	{
		size_t size = str.length();
		//if (size < 0) return false;
		const char* pStr = str.c_str();
		for (size_t x = 0; x < size; ++x)
		{
			//如果是中文则跳过
			//if (!((pStr[x] >= 0) && (pStr[x] <= 127)))
            if (!(pStr[x] >= 0))
			{
				continue;
			}
			//是否为英文 标点或者特殊字符
			if (ispunct(pStr[x]) || pStr[x] == 32)
			{
				return true;
			}
		}
		return false;
	}

	//字符串分割
	static void SplitString(const std::string& sSrc, std::string sDelimit, std::vector<std::string>& vResult, std::string sNull_subst = "");
	static void SplitStringToUint32(const std::string& strSrc, const std::string& strToken, std::vector<uint32_t>& vecResult, int nBase = 10);
	static bool SplitStringToUint32Ex(const std::string& strSrc, std::vector<std::pair<uint32_t, uint32_t> >& vecResult);
	static bool SplitStringToInt32(const std::string& strSrc, std::vector<std::pair<int32_t, int32_t> >& vecResult);

	template<typename T1>
	static void SplitStringToVector(const std::string& strSrc, const std::string& strToken, std::vector<T1>& vecResult)
	{
		vecResult.clear();
		std::string::size_type nBegin = 0;
		std::string::size_type nEnd = 0;
		std::stringstream ss;
		while ((nBegin = strSrc.find_first_not_of(strToken, nEnd)) != std::string::npos)
		{
			ss.clear();
			nEnd = strSrc.find_first_of(strToken, nBegin);
			ss << strSrc.substr(nBegin, nEnd - nBegin).c_str();
			T1 firstTemp;
			ss >> firstTemp;
			vecResult.push_back(firstTemp);
		}
	}

    template <typename T1>
    static void SplitStringToVectorInt(const std::string& strSrc, const std::string& strToken, std::vector<T1>& vecResult, int nBase = 10) {
        vecResult.clear();
        std::string::size_type nBegin = 0;
        std::string::size_type nEnd = 0;
        std::stringstream ss;
        while ((nBegin = strSrc.find_first_not_of(strToken, nEnd)) != std::string::npos) {
            ss.clear();
            nEnd = strSrc.find_first_of(strToken, nBegin);
            T1 firstTemp = (T1)stol(strSrc.substr(nBegin, nEnd - nBegin).c_str(), NULL, nBase);
            vecResult.push_back(firstTemp);
        }
    }

        template<typename T1>
	static bool SplitStringToVectorVec(const std::string& strSrc, vector<vector<T1> >& vecResult)
	{
		vector<string> vStrData;
		SplitString(strSrc, "$", vStrData);
		for (size_t i = 0; i < vStrData.size(); ++i)
		{
			vector<string> vSubData;
			vector<T1> vIntData;
			SplitString(vStrData[i], "~", vSubData);
			for (size_t j = 0; j < vSubData.size(); ++j)
			{
				vIntData.push_back(atoi(vSubData[j].c_str()));
			}

			vecResult.push_back(vIntData);
		}

		return true;
	}

	// 支持0或多个$字段(1005~3或1002~3$1003~3.0)，支持单字段(1005)，T1、T2不支持字符类型
	template<typename T1, typename T2>
	static bool SplitStringToVectorPair(const std::string& strSrc, vector<pair<T1, T2> >& vecResult, const string  subdelimiter = "~")
	{
		std::string strTemp = strSrc;
		vecResult.clear();
		std::string::size_type nBegin = 0;
		std::string::size_type nEnd = 0;
		std::string::size_type nSubBegin = 0;
		std::string::size_type nSubEnd = 0;

		std::stringstream ss;
		while ((nBegin = strTemp.find_first_not_of('$', nEnd)) != std::string::npos)
		{
			ss.clear();
			nSubBegin = 0;
			nSubEnd = 0;
			nEnd = strTemp.find_first_of('$', nBegin);
			if (nEnd == std::string::npos)
			{
				if ((nSubBegin = strTemp.find_first_not_of('~', nSubEnd)) != std::string::npos)
				{
					if ((nSubEnd = strTemp.find_first_of('~', nSubBegin)) == std::string::npos)
					{
						T1 firstTemp;
						ss << strTemp.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
						ss >> firstTemp;
						vecResult.push_back(make_pair(firstTemp, 0));
					}
					else
					{
						if (nSubEnd != strTemp.length() - 1)
						{
							T1 firstTemp;
							T2 secondTemp;
							ss << strTemp.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
							ss >> firstTemp;
							ss.clear();
							ss << strTemp.substr(nSubEnd + 1, strTemp.length() - 1).c_str();
							ss >> secondTemp;
							vecResult.push_back(make_pair(firstTemp, secondTemp));
						}
					}
				}
				return true;
			}

			string strSubSrc = strTemp.substr(nBegin, nEnd - nBegin);
			strTemp = strTemp.substr(nEnd + 1, strTemp.length() - nEnd + 1);
			nEnd = 0;
			if ((nSubBegin = strSubSrc.find_first_not_of('~', nSubEnd)) != std::string::npos)
			{
				if ((nSubEnd = strSubSrc.find_first_of('~', nSubBegin)) == std::string::npos)
				{
					ss << strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
					T1 firstTemp;
					ss >> firstTemp;
					vecResult.push_back(make_pair(firstTemp, 0));
				}
				else
				{
					if (nSubEnd != strSubSrc.length() - 1)
					{
						T1 firstTemp;
						T2 secondTemp;
						ss << strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
						ss >> firstTemp;
						ss.clear();
						ss << strSubSrc.substr(nSubEnd + 1, strSubSrc.length() - 1).c_str();
						ss >> secondTemp;
						vecResult.push_back(make_pair(firstTemp, secondTemp));
					}
				}
			}
		}
		return true;
	}

	//支持单字段(1005)，T1、T2不支持字符类型
	template<typename T1, typename T2>
	static bool SplitStringToPair(const std::string& strSrc, pair<T1, T2>& pairResult)
	{
		std::string strSubSrc = strSrc;
		std::string::size_type nSubBegin = 0;
		std::string::size_type nSubEnd = 0;
		std::stringstream ss;
		if ((nSubBegin = strSubSrc.find_first_not_of('~', nSubEnd)) != std::string::npos)
		{
			if ((nSubEnd = strSubSrc.find_first_of('~', nSubBegin)) == std::string::npos)
			{
				ss << strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
				T1 firstTemp;
				ss >> firstTemp;
				pairResult = make_pair(firstTemp, 0);
			}
			else
			{
				if (nSubEnd != strSubSrc.length() - 1)
				{
					T1 firstTemp;
					T2 secondTemp;
					ss << strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str();
					ss >> firstTemp;
					ss.clear();
					ss << strSubSrc.substr(nSubEnd + 1, strSubSrc.length() - 1).c_str();
					ss >> secondTemp;
					pairResult = make_pair(firstTemp, secondTemp);
				}
			}
		}
		return true;
	}

	static const char *IpToStr(uint32_t dwIp);

	static int GetIpDotId(uint32_t dwIP, int iDotIndex);

	static int IpToNum(const char *pszIp);

	static int GetServerIDFromBusID(uint32_t dwBusID);

	static const char *ServerIDToStr(uint32_t dwIp);
};

class NFStringUtilW
{
public:
	static void ToLower(std::wstring& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), towlower);
	}

	static void ToUpper(std::wstring& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), towupper);
	}

	static void Split(std::vector<std::wstring>& resultSubstrsVec, const std::wstring& str, const std::wstring& delims = L"\t\n ", unsigned int maxSplits = 0);
};

template <class _Tx, class _Ty>
inline void NFStringUtility::Explode(const _Tx& source, const _Tx& delim, std::vector<_Ty>& return_value, int limit)
{
	const char *p1, *p2, *endp;
	const char* str = source.data();
	size_t len = source.size();
	endp = str + source.size();

	if (limit == 0 || limit == 1)
	{
		return_value.push_back(_Ty(str, endp - str));
		return;
	}

	p1 = str;
	size_t delim_len = delim.size();
	p2 = static_cast<const char*>(memmem(str, len, delim.data(), delim_len));
	if (p2 == nullptr)
	{
		return_value.push_back(_Ty(str, len));
	}
	else
	{
		do
		{
			return_value.push_back(_Ty(p1, p2 - p1));
			p1 = p2 + delim_len;
		}
		while ((p2 = static_cast<char*>(memmem(p1, len - (p1 - str), delim.data(), delim_len))) != nullptr && (limit == -1 || --limit > 1));

		if (p1 < endp)
		{
			if ((p2 = static_cast<char*>(memmem(p1, len - (p1 - str), delim.data(), delim_len))) != nullptr)
			{
				endp = p2;
			}
			return_value.push_back(_Ty(p1, endp - p1));
		}
	}
}

template <class _StringType>
inline void NFStringUtility::Trim(_StringType& str, char c, bool left /*= true*/, bool right /*= true*/)
{
	if (str.empty())
	{
		return;
	}

	int stop_pos = static_cast<int>(str.size()) - 1;//included
	if (right)
	{
		for (; stop_pos >= 0; --stop_pos)
		{
			if (str[stop_pos] != c)
			{
				break;
			}
		}
	}

	if (stop_pos < 0)
	{
		str = _StringType();
		return;
	}

	int start_pos = 0;//included
	if (left)
	{
		for (; start_pos <= stop_pos; ++start_pos)
		{
			if (str[start_pos] != c)
			{
				break;
			}
		}
	}

	if (start_pos == 0 && stop_pos == static_cast<int>(str.size()) - 1)
	{
		return;
	}

	str = _StringType(str.data() + start_pos, stop_pos + 1 - start_pos);
}

