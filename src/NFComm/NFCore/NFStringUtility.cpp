// -------------------------------------------------------------------------
//    @FileName         :    NFStringUtility.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include <string.h>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cstdarg>

#include "NFStringUtility.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <cxxabi.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#else
#include <winsock.h>
#endif

struct NoCaseCompareChar
{
	bool operator()(char l, char r) const
	{
		bool bEqual = (l == r);
		if (bEqual)
		{
			return true;
		}
		if (isalpha(static_cast<unsigned char>(l)))
		{
			if (isupper(static_cast<unsigned char>(l)))
			{
				return l == toupper(r);
			}
			else
			{
				return l == tolower(r);
			}
		}

		return bEqual;
	}

	bool operator()(wchar_t l, wchar_t r) const
	{
		bool bEqual = (l == r);

		if (bEqual)
		{
			return true;
		}

		if (iswalpha(l))
		{
			if (iswupper(l))
			{
				return l == static_cast<wchar_t>(towupper(r));
			}
			else
			{
				return l == static_cast<wchar_t>(towlower(r));
			}
		}

		return bEqual;
	}
} no_case_compare_char;

template <class T>
bool stringUtil_StartsWith(const T& str, const T& pattern, bool case_sensitive)
{
	//H_ASSERT( str.length() >= pattern.length() );
	if (str.length() < pattern.length())
	{
		return false;
	}

	if (case_sensitive)
	{
		return std::equal(pattern.begin(), pattern.end(), str.begin());
	}
	else
	{
		return std::equal(pattern.begin(), pattern.end(), str.begin(), no_case_compare_char);
	}
}

template <class T>
bool stringUtil_EndsWith(const T& str, const T& pattern, bool case_sensitive)
{
	//H_ASSERT( str.length() >= pattern.length() );
	if (str.length() < pattern.length())
	{
		return false;
	}

	if (case_sensitive)
	{
		return equal(pattern.rbegin(), pattern.rend(), str.rbegin());
	}
	else
	{
		return equal(pattern.rbegin(), pattern.rend(), str.rbegin(), no_case_compare_char);
	}
}

template <class T>
struct nocase_equal_char
{
	T m_c;

	nocase_equal_char(T c) : m_c(c)
	{
	}

	bool operator()(T c)
	{
		return no_case_compare_char(m_c, c);
	}
};

template <class T>
bool stringUtil_contains(const T& str, typename T::value_type c, bool case_sensitive)
{
	if (case_sensitive)
	{
		return str.find(c, 0) != T::npos;
	}
	else
	{
		return str.end() != std::find_if(str.begin(), str.end(), nocase_equal_char<typename T::value_type>(c));
	}
}

template <class T>
bool stringUtil_contains(const T& strL, const T& strR, bool case_sensitive)
{
	if (case_sensitive)
	{
		return strL.end() != std::search(strL.begin(), strL.end(), strR.begin(), strR.end());
	}
	else
	{
		return strL.end() != std::search(strL.begin(), strL.end(), strR.begin(), strR.end(), no_case_compare_char);
	}
}

template <class _StringType>
void stringUtil_trim_charptr(_StringType& str, typename _StringType::const_pointer delims, bool left, bool right)
{
	if (str.empty())
	{
		return;
	}

	size_t stop_pos = static_cast<size_t>(str.size()) - 1;//included
	if (right)
	{
		stop_pos = str.find_last_not_of(delims);
	}

	if (stop_pos == _StringType::npos)
	{
		str = _StringType();
		return;
	}

	size_t start_pos = 0;//included
	if (left)
	{
		start_pos = str.find_first_not_of(delims);
	}

	if (start_pos == 0 && stop_pos == str.size() - 1)
	{
		return;
	}

	str = _StringType(str.data() + start_pos, stop_pos + 1 - start_pos);
}

template <class _StringType>
void stringUtil_trim_string(_StringType& str, const _StringType& delims, bool left, bool right)
{
#if 1
	if (str.empty())
	{
		return;
	}

	if (str.empty())
	{
		return;
	}

	size_t stop_pos = static_cast<size_t>(str.size()) - 1;//included
	if (right)
	{
		stop_pos = str.find_last_not_of(delims);
	}

	if (stop_pos == _StringType::npos)
	{
		str = _StringType();
		return;
	}

	size_t start_pos = 0;//included
	if (left)
	{
		start_pos = str.find_first_not_of(delims);
	}

	if (start_pos == 0 && stop_pos == str.size() - 1)
	{
		return;
	}

	str = _StringType(str.data() + start_pos, stop_pos + 1 - start_pos);
#else
	if (str.empty()) {
		return;
	}

	if (right) {
		str.erase(str.find_last_not_of(delims) + 1);        // trim right
	}

	if (left) {
		str.erase(0, str.find_first_not_of(delims));        // trim left
	}
#endif
}

template <class _StringVector,
          class StringType,
          class _DelimType>
inline void _stringUtilSplit(
	_StringVector& ret,
	const StringType& str,
	const _DelimType& delims,
	unsigned int maxSplits)
{
	unsigned int numSplits = 0;

	// Use STL methods
	size_t start, pos;
	start = 0;

	do
	{
		pos = str.find_first_of(delims, start);

		if (pos == start)
		{
			ret.push_back(StringType());
			start = pos + 1;
		}
		else if (pos == StringType::npos || (maxSplits && numSplits + 1 == maxSplits))
		{
			// Copy the rest of the string
			ret.push_back(StringType());
			*(ret.rbegin()) = StringType(str.data() + start, str.size() - start);
			break;
		}
		else
		{
			// Copy up to delimiter
			//ret.push_back( str.substr( start, pos - start ) );
			ret.push_back(StringType());
			*(ret.rbegin()) = StringType(str.data() + start, pos - start);
			start = pos + 1;
		}

		++numSplits;
	}
	while (pos != StringType::npos);
}

template <class _SliceVector,
          class StringType,
          class _DelimType>
void _stringUtilSplitStringToSlice(
	_SliceVector& ret,
	const StringType& str,
	const _DelimType& delims,
	unsigned int maxSplits)
{
	unsigned int numSplits = 0;

	// Use STL methods
	size_t start, pos;
	start = 0;

	do
	{
		pos = str.find_first_of(delims, start);

		if (pos == start)
		{
			ret.push_back(NFSlice());
			start = pos + 1;
		}
		else if (pos == StringType::npos || (maxSplits && numSplits + 1 == maxSplits))
		{
			// Copy the rest of the string
			ret.push_back(NFSlice(str.data() + start, str.size() - start));
			break;
		}
		else
		{
			// Copy up to delimiter
			//ret.push_back( str.substr( start, pos - start ) );
			ret.push_back(NFSlice(str.data() + start, pos - start));
			start = pos + 1;
		}

		++numSplits;
	}
	while (pos != StringType::npos);
}

template <class StringType,
          class _DelimType>
inline void _stringUtilSplitStringToSlice(
	const StringType& str,
	const _DelimType& delims,
	NFSlice* ret, size_t& slices_count)
{
	unsigned int numSplits = 0;

	// Use STL methods
	size_t start, pos;
	start = 0;

	do
	{
		pos = str.find_first_of(delims, start);

		if (pos == start)
		{
			ret[numSplits++] = NFSlice();
			start = pos + 1;
		}
		else if (pos == StringType::npos || (numSplits + 1 == slices_count))
		{
			// Copy the rest of the string
			ret[numSplits++] = (NFSlice(str.data() + start, str.size() - start));
			break;
		}
		else
		{
			// Copy up to delimiter
			//ret.push_back( str.substr( start, pos - start ) );
			ret[numSplits++] = (NFSlice(str.data() + start, pos - start));
			start = pos + 1;
		}
	}
	while (pos != StringType::npos);

	slices_count = numSplits;
}

inline void _stringUtilSplitSliceToSlice(
	const NFSlice& str,
	const char& delim,
	std::vector<NFSlice>& ret, unsigned int maxSplits)
{
	// Use STL methods
	size_t start, pos;
	start = 0;

	const char* p = nullptr;
	do
	{
		//fix strchr compile warning
#if NF_PLATFORM == NF_PLATFORM_WIN
		p = static_cast<const char*>(memchr(start + const_cast<char*>(str.data()), delim, str.size() - start));
#else
		p = (const char*)memchr(start + str.data(), delim, str.size() - start);
#endif

		if (!p || p >= str.data() + str.size() || ((maxSplits) && (ret.size() + 1 == maxSplits)))
		{
			ret.push_back(NFSlice(str.data() + start, str.size() - start));
			break;
		}

		pos = p - str.data();

		if (pos == start)
		{
			ret.push_back(NFSlice());
			start = pos + 1;
		}
		else
		{
			ret.push_back(NFSlice(str.data() + start, pos - start));
			start = pos + 1;
		}
	}
	while (true);
}

inline void _stringUtilSplitSliceToSlice(
	const NFSlice& str,
	const char& delim,
	NFSlice* ret, size_t& slices_count)
{
	unsigned int numSplits = 0;

	// Use STL methods
	size_t start, pos;
	start = 0;

	const char* p = nullptr;
	do
	{
		//fix strchr compile warning
#if NF_PLATFORM == NF_PLATFORM_WIN
		p = static_cast<const char*>(memchr(start + const_cast<char*>(str.data()), delim, str.size() - start));
#else
		p = (const char*)memchr(start + str.data(), delim, str.size() - start);
#endif
		if (!p || p >= str.data() + str.size() || (numSplits == slices_count - 1))
		{
			ret[numSplits++] = (NFSlice(str.data() + start, str.size() - start));
			break;
		}

		pos = p - str.data();

		if (pos == start)
		{
			ret[numSplits++] = NFSlice();
			start = pos + 1;
		}
		else
		{
			ret[numSplits++] = (NFSlice(str.data() + start, pos - start));
			start = pos + 1;
		}
	}
	while (true);

	slices_count = numSplits;
}

template <typename StringType>
void stringUtil_Split(const StringType& src, StringType& left, StringType& right, typename StringType::const_pointer pDelims, size_t nDelimsLength)
{
	typename StringType::const_iterator iter = find_first_of(src.begin(), src.end(), pDelims, pDelims + nDelimsLength);
	if (src.end() == iter)
	{
		return;
	}

	left.assign(src.begin(), iter);
	++iter;
	right.assign(iter, src.end());
}

const string NFStringUtility::kEmpty;

void NFStringUtility::Trim(std::string& str, const char* delims, bool left, bool right)
{
	stringUtil_trim_charptr(str, delims, left, right);
}

void NFStringUtility::Trim(std::wstring& str, const wchar_t* delims, bool left, bool right)
{
	stringUtil_trim_charptr(str, delims, left, right);
}

void NFStringUtility::Trim(string& str, bool left, bool right)
{
	//const char* delims = " \t\r\n";
	static const std::string delims("\0 \t\r\n\v", 6);
	NFStringUtility::Trim(str, delims, left, right);
}

void NFStringUtility::Trim(std::vector<std::string>& vecStr)
{
    for(int i = 0; i < (int)vecStr.size(); i++)
    {
        Trim(vecStr[i]);
    }
}

void NFStringUtility::Trim(std::string& str, const std::string& delims, bool left, bool right)
{
	stringUtil_trim_string(str, delims, left, right);
}

void NFStringUtility::Trim(std::wstring& str, bool left, bool right)
{
	//const wchar_t* delims = L" \t\r\n";
	static const std::wstring delims(L"\0 \t\r\n\v", 6);
	Trim(str, delims, left, right);
}

void NFStringUtility::Trim(std::wstring& str, const std::wstring& delims, bool left, bool right)
{
	stringUtil_trim_string(str, delims, left, right);
}

void NFStringUtility::Split(std::vector<std::string>& ret, const std::string& str, const std::string& delims, unsigned int maxSplits)
{
	_stringUtilSplit(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(std::vector<std::string>& ret, const std::string& str, const std::string::value_type& delims, unsigned int maxSplits)
{
	_stringUtilSplit(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(std::vector<std::wstring>& ret, const std::wstring& str, const std::wstring& delims, unsigned int maxSplits)
{
	_stringUtilSplit(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(std::vector<std::wstring>& ret, const std::wstring& str, const std::wstring::value_type& delims, unsigned int maxSplits)
{
	_stringUtilSplit(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(std::vector<NFSlice>& ret, const std::string& str, int delims, unsigned int maxSplits)
{
	_stringUtilSplitStringToSlice(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(std::vector<NFSlice>& ret, const std::string& str, const std::string& delims, unsigned int maxSplits)
{
	_stringUtilSplitStringToSlice(ret, str, delims, maxSplits);
}

void NFStringUtility::Split(const std::string& str, int delims, NFSlice slices[], size_t& slice_count)
{
	_stringUtilSplitStringToSlice(str, delims, slices, slice_count);
}

void NFStringUtility::Split(const std::string& str, const std::string& delims, NFSlice slices[], size_t& slice_count)
{
	_stringUtilSplitStringToSlice(str, delims, slices, slice_count);
}

void NFStringUtility::Split(const NFSlice& str, int delims, NFSlice slices[], size_t& slice_count)
{
	_stringUtilSplitSliceToSlice(str, delims, slices, slice_count);
}

void NFStringUtility::Split(const NFSlice& str, int delims, std::vector<NFSlice>& slices, unsigned int maxSplits)
{
	_stringUtilSplitSliceToSlice(str, delims, slices, maxSplits);
}

void NFStringUtility::Split(const std::string& src, std::string& left, std::string& right, const char* delims/* = "\t\n "*/)
{
	stringUtil_Split(src, left, right, delims, strlen(delims));
}

void NFStringUtility::Split(const std::string& src, std::string& left, std::string& right, const std::string& delims/* = "\t\n "*/)
{
	Split(src, left, right, delims.c_str());
}

void NFStringUtility::Split(const std::wstring& src, std::wstring& left, std::wstring& right, const wchar_t* delims/* = L"\t\n "*/)
{
	stringUtil_Split(src, left, right, delims, wcslen(delims));
}

void NFStringUtility::Split(const std::wstring& src, std::wstring& left, std::wstring& right, const std::wstring& delims/* = L"\t\n "*/)
{
	Split(src, left, right, delims.c_str());
}

template <typename _String>
void _replace(_String& str, const _String& needle, const _String& new_value, size_t start_pos/* = 0*/, int replace_count /*= -1 */)
{
	if (0 == replace_count)
	{
		return;
	}

	size_t i = 0;
	size_t a = needle.size();
	size_t b = new_value.size();
	size_t pos = str.find(needle, start_pos);
	while (pos != _String::npos)
	{
		str.replace(pos, a, new_value);
		pos += b;
		pos = str.find(needle, pos);
		if (++i >= static_cast<size_t>(replace_count))
		{
			break;
		}
	}
}

void NFStringUtility::Replace(std::string& str, const std::string& needle, const std::string& new_value, size_t start_pos/* = 0*/, int replace_count /*= -1 */)
{
	return _replace(str, needle, new_value, start_pos, replace_count);
}

void NFStringUtility::Replace(std::wstring& str, const std::wstring& needle, const std::wstring& new_value, size_t start_pos/* = 0*/, int replace_count /*= -1 */)
{
	return _replace(str, needle, new_value, start_pos, replace_count);
}

bool NFStringUtility::StartsWith(const std::string& str, const std::string& pattern, bool case_sensitive)
{
	return stringUtil_StartsWith(str, pattern, case_sensitive);
}

bool NFStringUtility::StartsWith(const std::wstring& str, const std::wstring& pattern, bool case_sensitive)
{
	return stringUtil_StartsWith(str, pattern, case_sensitive);
}

bool NFStringUtility::EndsWith(const std::string& str, const std::string& pattern, bool case_sensitive)
{
	return stringUtil_EndsWith(str, pattern, case_sensitive);
}

bool NFStringUtility::EndsWith(const std::wstring& str, const std::wstring& pattern, bool case_sensitive)
{
	return stringUtil_EndsWith(str, pattern, case_sensitive);
}

bool NFStringUtility::Match(const std::string& str, const std::string& pattern, bool caseSensitive)
{
	std::string tmpStr = str;
	std::string tmpPattern = pattern;

	if (!caseSensitive)
	{
		NFStringUtility::ToLower(tmpStr);
		NFStringUtility::ToLower(tmpPattern);
	}

	std::string::const_iterator strIt = tmpStr.begin();
	std::string::const_iterator patIt = tmpPattern.begin();
	std::string::const_iterator lastWildCardIt = tmpPattern.end();

	while (strIt != tmpStr.end() && patIt != tmpPattern.end())
	{
		if (*patIt == '*')
		{
			lastWildCardIt = patIt;
			// Skip over looking for next character
			++patIt;

			if (patIt == tmpPattern.end())
			{
				// Skip right to the end since * matches the entire rest of the string
				strIt = tmpStr.end();
			}
			else
			{
				// scan until we find next pattern character
				while (strIt != tmpStr.end() && *strIt != *patIt)
				{
					++strIt;
				}
			}
		}
		else
		{
			if (*patIt != *strIt)
			{
				if (lastWildCardIt != tmpPattern.end())
				{
					// The last wildcard can match this incorrect sequence
					// rewind pattern to wildcard and keep searching
					patIt = lastWildCardIt;
					lastWildCardIt = tmpPattern.end();
				}
				else
				{
					// no wildwards left
					return false;
				}
			}
			else
			{
				++patIt;
				++strIt;
			}
		}
	}

	// If we reached the end of both the pattern and the string, we succeeded
	if (patIt == tmpPattern.end() && strIt == tmpStr.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NFStringUtility::Match(const std::wstring& str, const std::wstring& pattern, bool caseSensitive)
{
	std::wstring tmpStr = str;
	std::wstring tmpPattern = pattern;

	if (!caseSensitive)
	{
		NFStringUtility::ToLower(tmpStr);
		NFStringUtility::ToLower(tmpPattern);
	}

	std::wstring::const_iterator strIt = tmpStr.begin();
	std::wstring::const_iterator patIt = tmpPattern.begin();
	std::wstring::const_iterator lastWildCardIt = tmpPattern.end();

	while (strIt != tmpStr.end() && patIt != tmpPattern.end())
	{
		if (*patIt == L'*')
		{
			lastWildCardIt = patIt;
			// Skip over looking for next character
			++patIt;

			if (patIt == tmpPattern.end())
			{
				// Skip right to the end since * matches the entire rest of the string
				strIt = tmpStr.end();
			}
			else
			{
				// scan until we find next pattern character
				while (strIt != tmpStr.end() && *strIt != *patIt)
				{
					++strIt;
				}
			}
		}
		else
		{
			if (*patIt != *strIt)
			{
				if (lastWildCardIt != tmpPattern.end())
				{
					// The last wildcard can match this incorrect sequence
					// rewind pattern to wildcard and keep searching
					patIt = lastWildCardIt;
					lastWildCardIt = tmpPattern.end();
				}
				else
				{
					// no wildwards left
					return false;
				}
			}
			else
			{
				++patIt;
				++strIt;
			}
		}
	}

	// If we reached the end of both the pattern and the string, we succeeded
	if (patIt == tmpPattern.end() && strIt == tmpStr.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NFStringUtility::Contains(const std::string& motherStr, char pattern, bool caseSensitive)
{
	return stringUtil_contains(motherStr, pattern, caseSensitive);
}

bool NFStringUtility::Contains(const std::wstring& motherStr, wchar_t pattern, bool caseSensitive)
{
	return stringUtil_contains(motherStr, pattern, caseSensitive);
}

bool NFStringUtility::Contains(const std::string& motherStr, const std::string& pattern, bool caseSensitive)
{
	return stringUtil_contains(motherStr, pattern, caseSensitive);
}

bool NFStringUtility::Contains(const wstring& motherStr, const wstring& pattern, bool caseSensitive)
{
	return stringUtil_contains(motherStr, pattern, caseSensitive);
}

static unsigned char hexchars[] = "0123456789ABCDEF";

void NFStringUtility::URLEncode(const char* url, size_t url_len, std::string& strDest)
{
#if 1
	size_t encoded_url_len = url_len * 3;
	strDest.resize(encoded_url_len);
	URLEncode(url, url_len, &strDest[0], encoded_url_len);
	strDest.resize(encoded_url_len);
#else
	//copy from php source code : ext/standard/url.c: PHPAPI char *php_url_encode(char const *s, int len, int *new_length)
	strDest.resize(url_len * 3);

	unsigned char c;
	unsigned char* to, *start;
	unsigned char const* from, *end;

	start = to = (unsigned char*)(&strDest[0]);

	from = (unsigned char const*)url;
	end = from + url_len;

	while (from < end) {
		c = *from++;

		if (c == ' ') {
			*to++ = '+';
		}
		else if ((c < '0' && c != '-' && c != '.') ||
			(c < 'A' && c > '9') ||
			(c > 'Z' && c < 'a' && c != '_') ||
			(c > 'z')) {
			to[0] = '%';
			to[1] = hexchars[c >> 4];
			to[2] = hexchars[c & 15];
			to += 3;
		}
		else {
			*to++ = c;
		}
	}
	*to = 0;

	strDest.resize(to - start);
#endif
}

bool NFStringUtility::URLEncode(const char* url, size_t url_len, char* edcoded_url, size_t& edcoded_url_len)
{
	//copy from php source code : ext/standard/url.c: PHPAPI char *php_url_encode(char const *s, int len, int *new_length)

	unsigned char c;
	unsigned char *to, *start, *to_end;
	unsigned char const *from, *end;

	start = to = reinterpret_cast<unsigned char*>(edcoded_url);
	to_end = to + edcoded_url_len;

	from = reinterpret_cast<unsigned char const*>(url);
	end = from + url_len;

	while (from < end)
	{
		c = *from++;

		if (c == ' ')
		{
			if (to < to_end)
			{
				*to++ = '+';
			}
			else
			{
				return false;
			}
		}
		else if ((c < '0' && c != '-' && c != '.') ||
			(c < 'A' && c > '9') ||
			(c > 'Z' && c < 'a' && c != '_') ||
			(c > 'z'))
		{
			if (to + 2 < to_end)
			{
				to[0] = '%';
				to[1] = hexchars[c >> 4];
				to[2] = hexchars[c & 15];
				to += 3;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (to < to_end)
			{
				*to++ = c;
			}
			else
			{
				return false;
			}
		}
	}
	*to = 0;
	edcoded_url_len = (to - start);
	return true;
}

static int php_htoi(const char* s)
{
	int value;
	int c;

	c = reinterpret_cast<const unsigned char*>(s)[0];
	if (isupper(c))
	{
		c = tolower(c);
	}
	value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;

	c = reinterpret_cast<const unsigned char*>(s)[1];
	if (isupper(c))
	{
		c = tolower(c);
	}
	value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;

	return (value);
}

void NFStringUtility::URLDecode(const std::string& str, std::string& out)
{
	//copy from php source code : ext/standard/url.c: PHPAPI int php_url_decode(char *str, int len)
#if 1
	URLDecode(str.data(), str.size(), out);
	//         out.resize(str.size());
	// #if 1
	//         size_t decoded_url_len = str.size();
	//         urldecode(str.data(), str.size(), &out[0], decoded_url_len);
	//         out.resize(decoded_url_len);
#else
	char* dest = &out[0];
	const char* data = str.data();
	int len = (int)str.size();
	while (len--) {
		if (*data == '+') {
			*dest = ' ';
		}
		else if (*data == '%' && len >= 2 && isxdigit((int)* (data + 1))
			&& isxdigit((int)* (data + 2))) {
			*dest = (char)php_htoi(data + 1);
			data += 2;
			len -= 2;
		}
		else {
			*dest = *data;
		}
		data++;
		dest++;
	}

	out.resize(dest - out.data());
#endif
}

void NFStringUtility::URLDecode(const char* encoded_url, size_t encoded_url_len, char* decoded_url, size_t& decoded_url_len)
{
	char* dest = decoded_url;
	const char* data = encoded_url;
	int len = static_cast<int>(encoded_url_len);
	while (len--)
	{
		if (*data == '+')
		{
			*dest = ' ';
		}
		else if (*data == '%' && len >= 2 && isxdigit(static_cast<int>(*(data + 1)))
			&& isxdigit(static_cast<int>(*(data + 2))))
		{
			*dest = static_cast<char>(php_htoi(data + 1));
			data += 2;
			len -= 2;
		}
		else
		{
			*dest = *data;
		}
		data++;
		dest++;
	}

	decoded_url_len = dest - decoded_url;
}

void NFStringUtility::URLDecode(const char* encoded_url, size_t encoded_url_len, std::string& out)
{
	out.resize(encoded_url_len);
	size_t decoded_url_len = encoded_url_len;
	URLDecode(encoded_url, encoded_url_len, &out[0], decoded_url_len);
	out.resize(decoded_url_len);
}

bool NFStringUtility::Equals(const std::string& str1, const std::string& str2, bool case_sensitive /*= true */)
{
	if (case_sensitive)
	{
		return (str1 == str2) ? true : false;
	}
	else
	{
		return EqualsIgnoreCase(str1, str2);
	}
}

bool NFStringUtility::EqualsIgnoreCase(const std::string& str1, const std::string& str2)
{
	if (str1.length() == str2.length())
	{
		return std::equal(str1.begin(), str1.end(), str2.begin(), no_case_compare_char);
	}
	return false;
}

bool NFStringUtility::IsFloatNumber(std::string& s)
{
	if (s.find('.') != std::string::npos
		|| s.find('e') != std::string::npos
		|| s.find('E') != std::string::npos)
	{
		return true;
	}

	return false;
}

std::string NFStringUtility::Rot13(const std::string& s)
{
	return Rot13(s.data(), s.size());
}

std::string NFStringUtility::Rot13(const char* str, size_t len)
{
	std::string ret;
	if (str == nullptr || len == 0)
	{
		return ret;
	}

	int rot = 13;
	ret.resize(len);
	char* res = &ret[0];
	unsigned char c, e;

	for (size_t i = 0; i < len; i++)
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
		{
			if ((e = c + rot) <= 'Z')
			{
				res[i] = e;
			}
			else
			{
				res[i] = c - rot;
			}
		}
		else if (c >= 'a' && c <= 'z')
		{
			if ((e = c + rot) <= 'z')
			{
				res[i] = e;
			}
			else
			{
				res[i] = c - rot;
			}
		}
		else
		{
			res[i] = str[i];
		}
	}
	return ret;
}

void NFStringUtilW::Split(std::vector<std::wstring>& ret, const std::wstring& str, const std::wstring& delims, unsigned int maxSplits)
{
	_stringUtilSplit(ret, str, delims, maxSplits);
}

void NFStringUtility::ToLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
	               {
		               return tolower(c);
	               });
}

void NFStringUtility::ToLower(std::wstring& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](wchar_t c)
	               {
		               return towlower(c);
	               });
}

void NFStringUtility::ToUpper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
	               {
		               return toupper(c);
	               });
}

void NFStringUtility::ToUpper(std::wstring& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](wchar_t c)
	               {
		               return towupper(c);
	               });
}

void NFStringUtility::Split(const std::string& str,
                            const std::string& delim,
                            std::vector<std::string>* result)
{
	if (str.empty())
	{
		return;
	}
	if (delim[0] == '\0')
	{
		result->push_back(str);
		return;
	}

	size_t delim_length = delim.length();

	for (std::string::size_type begin_index = 0; begin_index < str.size();)
	{
		std::string::size_type end_index = str.find(delim, begin_index);
		if (end_index == std::string::npos)
		{
			result->push_back(str.substr(begin_index));
			return;
		}
		if (end_index > begin_index)
		{
			result->push_back(str.substr(begin_index, (end_index - begin_index)));
		}

		begin_index = end_index + delim_length;
	}
}

std::string& NFStringUtility::Ltrim(std::string& str) // NOLINT
{
	std::string::iterator it = find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isspace)));
	str.erase(str.begin(), it);
	return str;
}

std::string& NFStringUtility::Rtrim(std::string& str) // NOLINT
{
	std::string::reverse_iterator it = find_if(str.rbegin(),
	                                           str.rend(), std::not1(std::ptr_fun(::isspace)));

	str.erase(it.base(), str.end());
	return str;
}

std::string& NFStringUtility::LRTrim(std::string& str) // NOLINT
{
	return Rtrim(Ltrim(str));
}

void NFStringUtility::LRTrim(std::vector<std::string>* str_list)
{
	if (NULL == str_list)
	{
		return;
	}

	std::vector<std::string>::iterator it;
	for (it = str_list->begin(); it != str_list->end(); ++it)
	{
		*it = LRTrim(*it);
	}
}

void NFStringUtility::StringReplace(const std::string& sub_str1,
                                    const std::string& sub_str2, std::string* str)
{
	std::string::size_type pos = 0;
	std::string::size_type a = sub_str1.size();
	std::string::size_type b = sub_str2.size();
	while ((pos = str->find(sub_str1, pos)) != std::string::npos)
	{
		str->replace(pos, a, sub_str2);
		pos += b;
	}
}

static const char ENCODECHARS[1024] =
{
	3, '%', '0', '0', 3, '%', '0', '1', 3, '%', '0', '2', 3, '%', '0', '3',
	3, '%', '0', '4', 3, '%', '0', '5', 3, '%', '0', '6', 3, '%', '0', '7',
	3, '%', '0', '8', 3, '%', '0', '9', 3, '%', '0', 'A', 3, '%', '0', 'B',
	3, '%', '0', 'C', 3, '%', '0', 'D', 3, '%', '0', 'E', 3, '%', '0', 'F',
	3, '%', '1', '0', 3, '%', '1', '1', 3, '%', '1', '2', 3, '%', '1', '3',
	3, '%', '1', '4', 3, '%', '1', '5', 3, '%', '1', '6', 3, '%', '1', '7',
	3, '%', '1', '8', 3, '%', '1', '9', 3, '%', '1', 'A', 3, '%', '1', 'B',
	3, '%', '1', 'C', 3, '%', '1', 'D', 3, '%', '1', 'E', 3, '%', '1', 'F',
	1, '+', '2', '0', 3, '%', '2', '1', 3, '%', '2', '2', 3, '%', '2', '3',
	3, '%', '2', '4', 3, '%', '2', '5', 3, '%', '2', '6', 3, '%', '2', '7',
	3, '%', '2', '8', 3, '%', '2', '9', 3, '%', '2', 'A', 3, '%', '2', 'B',
	3, '%', '2', 'C', 1, '-', '2', 'D', 1, '.', '2', 'E', 3, '%', '2', 'F',
	1, '0', '3', '0', 1, '1', '3', '1', 1, '2', '3', '2', 1, '3', '3', '3',
	1, '4', '3', '4', 1, '5', '3', '5', 1, '6', '3', '6', 1, '7', '3', '7',
	1, '8', '3', '8', 1, '9', '3', '9', 3, '%', '3', 'A', 3, '%', '3', 'B',
	3, '%', '3', 'C', 3, '%', '3', 'D', 3, '%', '3', 'E', 3, '%', '3', 'F',
	3, '%', '4', '0', 1, 'A', '4', '1', 1, 'B', '4', '2', 1, 'C', '4', '3',
	1, 'D', '4', '4', 1, 'E', '4', '5', 1, 'F', '4', '6', 1, 'G', '4', '7',
	1, 'H', '4', '8', 1, 'I', '4', '9', 1, 'J', '4', 'A', 1, 'K', '4', 'B',
	1, 'L', '4', 'C', 1, 'M', '4', 'D', 1, 'N', '4', 'E', 1, 'O', '4', 'F',
	1, 'P', '5', '0', 1, 'Q', '5', '1', 1, 'R', '5', '2', 1, 'S', '5', '3',
	1, 'T', '5', '4', 1, 'U', '5', '5', 1, 'V', '5', '6', 1, 'W', '5', '7',
	1, 'X', '5', '8', 1, 'Y', '5', '9', 1, 'Z', '5', 'A', 3, '%', '5', 'B',
	3, '%', '5', 'C', 3, '%', '5', 'D', 3, '%', '5', 'E', 1, '_', '5', 'F',
	3, '%', '6', '0', 1, 'a', '6', '1', 1, 'b', '6', '2', 1, 'c', '6', '3',
	1, 'd', '6', '4', 1, 'e', '6', '5', 1, 'f', '6', '6', 1, 'g', '6', '7',
	1, 'h', '6', '8', 1, 'i', '6', '9', 1, 'j', '6', 'A', 1, 'k', '6', 'B',
	1, 'l', '6', 'C', 1, 'm', '6', 'D', 1, 'n', '6', 'E', 1, 'o', '6', 'F',
	1, 'p', '7', '0', 1, 'q', '7', '1', 1, 'r', '7', '2', 1, 's', '7', '3',
	1, 't', '7', '4', 1, 'u', '7', '5', 1, 'v', '7', '6', 1, 'w', '7', '7',
	1, 'x', '7', '8', 1, 'y', '7', '9', 1, 'z', '7', 'A', 3, '%', '7', 'B',
	3, '%', '7', 'C', 3, '%', '7', 'D', 1, '~', '7', 'E', 3, '%', '7', 'F',
	3, '%', '8', '0', 3, '%', '8', '1', 3, '%', '8', '2', 3, '%', '8', '3',
	3, '%', '8', '4', 3, '%', '8', '5', 3, '%', '8', '6', 3, '%', '8', '7',
	3, '%', '8', '8', 3, '%', '8', '9', 3, '%', '8', 'A', 3, '%', '8', 'B',
	3, '%', '8', 'C', 3, '%', '8', 'D', 3, '%', '8', 'E', 3, '%', '8', 'F',
	3, '%', '9', '0', 3, '%', '9', '1', 3, '%', '9', '2', 3, '%', '9', '3',
	3, '%', '9', '4', 3, '%', '9', '5', 3, '%', '9', '6', 3, '%', '9', '7',
	3, '%', '9', '8', 3, '%', '9', '9', 3, '%', '9', 'A', 3, '%', '9', 'B',
	3, '%', '9', 'C', 3, '%', '9', 'D', 3, '%', '9', 'E', 3, '%', '9', 'F',
	3, '%', 'A', '0', 3, '%', 'A', '1', 3, '%', 'A', '2', 3, '%', 'A', '3',
	3, '%', 'A', '4', 3, '%', 'A', '5', 3, '%', 'A', '6', 3, '%', 'A', '7',
	3, '%', 'A', '8', 3, '%', 'A', '9', 3, '%', 'A', 'A', 3, '%', 'A', 'B',
	3, '%', 'A', 'C', 3, '%', 'A', 'D', 3, '%', 'A', 'E', 3, '%', 'A', 'F',
	3, '%', 'B', '0', 3, '%', 'B', '1', 3, '%', 'B', '2', 3, '%', 'B', '3',
	3, '%', 'B', '4', 3, '%', 'B', '5', 3, '%', 'B', '6', 3, '%', 'B', '7',
	3, '%', 'B', '8', 3, '%', 'B', '9', 3, '%', 'B', 'A', 3, '%', 'B', 'B',
	3, '%', 'B', 'C', 3, '%', 'B', 'D', 3, '%', 'B', 'E', 3, '%', 'B', 'F',
	3, '%', 'C', '0', 3, '%', 'C', '1', 3, '%', 'C', '2', 3, '%', 'C', '3',
	3, '%', 'C', '4', 3, '%', 'C', '5', 3, '%', 'C', '6', 3, '%', 'C', '7',
	3, '%', 'C', '8', 3, '%', 'C', '9', 3, '%', 'C', 'A', 3, '%', 'C', 'B',
	3, '%', 'C', 'C', 3, '%', 'C', 'D', 3, '%', 'C', 'E', 3, '%', 'C', 'F',
	3, '%', 'D', '0', 3, '%', 'D', '1', 3, '%', 'D', '2', 3, '%', 'D', '3',
	3, '%', 'D', '4', 3, '%', 'D', '5', 3, '%', 'D', '6', 3, '%', 'D', '7',
	3, '%', 'D', '8', 3, '%', 'D', '9', 3, '%', 'D', 'A', 3, '%', 'D', 'B',
	3, '%', 'D', 'C', 3, '%', 'D', 'D', 3, '%', 'D', 'E', 3, '%', 'D', 'F',
	3, '%', 'E', '0', 3, '%', 'E', '1', 3, '%', 'E', '2', 3, '%', 'E', '3',
	3, '%', 'E', '4', 3, '%', 'E', '5', 3, '%', 'E', '6', 3, '%', 'E', '7',
	3, '%', 'E', '8', 3, '%', 'E', '9', 3, '%', 'E', 'A', 3, '%', 'E', 'B',
	3, '%', 'E', 'C', 3, '%', 'E', 'D', 3, '%', 'E', 'E', 3, '%', 'E', 'F',
	3, '%', 'F', '0', 3, '%', 'F', '1', 3, '%', 'F', '2', 3, '%', 'F', '3',
	3, '%', 'F', '4', 3, '%', 'F', '5', 3, '%', 'F', '6', 3, '%', 'F', '7',
	3, '%', 'F', '8', 3, '%', 'F', '9', 3, '%', 'F', 'A', 3, '%', 'F', 'B',
	3, '%', 'F', 'C', 3, '%', 'F', 'D', 3, '%', 'F', 'E', 3, '%', 'F', 'F',
};

void NFStringUtility::UrlEncode(const std::string& src_str, std::string* dst_str)
{
	dst_str->clear();
	for (size_t i = 0; i < src_str.length(); i++)
	{
		unsigned short offset = static_cast<unsigned short>(src_str[i]) * 4;
		dst_str->append((ENCODECHARS + offset + 1), ENCODECHARS[offset]);
	}
}

static const char HEX2DEC[256] =
{
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	0 , 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

void NFStringUtility::UrlDecode(const std::string& src_str, std::string* dst_str)
{
	dst_str->clear();
	const unsigned char* src_begin = reinterpret_cast<const unsigned char*>(src_str.data());
	const unsigned char* src_end = src_begin + src_str.length();
	const unsigned char* src_last = src_end - 2;
	while (src_begin < src_last)
	{
		if ((*src_begin) == '%')
		{
			char dec1, dec2;
			if (-1 != (dec1 = HEX2DEC[*(src_begin + 1)])
				&& -1 != (dec2 = HEX2DEC[*(src_begin + 2)]))
			{
				dst_str->append(1, (dec1 << 4) + dec2);
				src_begin += 3;
				continue;
			}
		}
		else if ((*src_begin) == '+')
		{
			dst_str->append(1, ' ');
			++src_begin;
			continue;
		}
		dst_str->append(1, static_cast<char>(*src_begin));
		++src_begin;
	}
	while (src_begin < src_end)
	{
		dst_str->append(1, static_cast<char>(*src_begin));
		++src_begin;
	}
}

void NFStringUtility::ToUpper(std::string* str)
{
	std::transform(str->begin(), str->end(), str->begin(), ::toupper);
}

void NFStringUtility::ToLower(std::string* str)
{
	std::transform(str->begin(), str->end(), str->begin(), ::tolower);
}

std::string NFStringUtility::ToLower(const std::string& str)
{
	std::string ss = str;
	ToLower(&ss);
	return ss;
}

bool NFStringUtility::StripSuffix(std::string* str, const std::string& suffix)
{
	if (str->length() >= suffix.length())
	{
		size_t suffix_pos = str->length() - suffix.length();
		if (str->compare(suffix_pos, std::string::npos, suffix) == 0)
		{
			str->resize(str->size() - suffix.size());
			return true;
		}
	}

	return false;
}

bool NFStringUtility::StripPrefix(std::string* str, const std::string& prefix)
{
	if (str->length() >= prefix.length())
	{
		if (str->substr(0, prefix.size()) == prefix)
		{
			*str = str->substr(prefix.size());
			return true;
		}
	}
	return false;
}

bool NFStringUtility::Hex2Bin(const char* hex_str, std::string* bin_str)
{
	if (NULL == hex_str || NULL == bin_str)
	{
		return false;
	}
	bin_str->clear();
	while (*hex_str != '\0')
	{
		if (hex_str[1] == '\0')
		{
			return false;
		}
		uint8_t high = static_cast<uint8_t>(hex_str[0]);
		uint8_t low = static_cast<uint8_t>(hex_str[1]);
#define ASCII2DEC(c) \
    if (c >= '0' && c <= '9') c -= '0'; \
    else if (c >= 'A' && c <= 'F') c -= ('A' - 10); \
    else if (c >= 'a' && c <= 'f') c -= ('a' - 10); \
    else return false
		ASCII2DEC(high);
		ASCII2DEC(low);
		bin_str->append(1, static_cast<char>((high << 4) + low));
		hex_str += 2;
	}
	return true;
}

bool NFStringUtility::Bin2Hex(const char* bin_str, std::string* hex_str)
{
	if (NULL == bin_str || NULL == hex_str)
	{
		return false;
	}
	hex_str->clear();
	while (*bin_str != '\0')
	{
		uint8_t high = (static_cast<uint8_t>(*bin_str) >> 4);
		uint8_t low = (static_cast<uint8_t>(*bin_str) & 0xF);
#define DEC2ASCII(c) \
    if (c <= 9) c += '0'; \
    else c += ('A' - 10)
		DEC2ASCII(high);
		DEC2ASCII(low);
		hex_str->append(1, static_cast<char>(high));
		hex_str->append(1, static_cast<char>(low));
		bin_str += 1;
	}
	return true;
}

#define TEMP_SIZE 102400

std::string NFStringUtility::Format(std::string sz, ...)
{
	char sTemp[TEMP_SIZE];
	va_list argList;
	va_start(argList, sz);
	//vsprintf_s(sTemp, sizeof(sTemp), sz.c_str(), argList);
	vsnprintf(sTemp, sizeof(sTemp), sz.c_str(), argList);
	va_end(argList);
	return sTemp;
};

#ifdef _MSC_VER
enum
{
	IS_COMPILER_MSVC = 1
};
#ifndef va_copy
// Define va_copy for MSVC. This is a hack, assuming va_list is simply a
// pointer into the stack and is safe to copy.
#define va_copy(dest, src) ((dest) = (src))
#endif
#else
enum { IS_COMPILER_MSVC = 0 };
#endif

void NFStringUtility::StringAppendV(std::string* dst, const char* format, va_list ap)
{
	// First try with a small fixed size buffer
	static const int kSpaceLength = 10240;
	char space[kSpaceLength];

	// It's possible for methods that use a va_list to invalidate
	// the data in it upon use.  The fix is to make a copy
	// of the structure before using it and use that copy instead.
	va_list backup_ap;
	va_copy(backup_ap, ap);
	int result = vsnprintf(space, kSpaceLength, format, backup_ap);
	va_end(backup_ap);

	if (result < kSpaceLength)
	{
		if (result >= 0)
		{
			// Normal case -- everything fit.
			dst->append(space, result);
			return;
		}

		if (IS_COMPILER_MSVC)
		{
			// Error or MSVC running out of space.  MSVC 8.0 and higher
			// can be asked about space needed with the special idiom below:
			va_copy(backup_ap, ap);
			result = vsnprintf(nullptr, 0, format, backup_ap);
			va_end(backup_ap);
		}

		if (result < 0)
		{
			// Just an error.
			return;
		}
	}

	// Increase the buffer size to the size requested by vsnprintf,
	// plus one for the closing \0.
	int length = result + 1;
	char* buf = new char[length];

	// Restore the va_list before we use it again
	va_copy(backup_ap, ap);
	result = vsnprintf(buf, length, format, backup_ap);
	va_end(backup_ap);

	if (result >= 0 && result < length)
	{
		// It fit
		dst->append(buf, result);
	}
	delete[] buf;
}

std::string NFStringUtility::StringPrintf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	std::string result;
	StringAppendV(&result, format, ap);
	va_end(ap);
	return result;
}

const std::string& NFStringUtility::SStringPrintf(std::string* dst, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	dst->clear();
	StringAppendV(dst, format, ap);
	va_end(ap);
	return *dst;
}

void NFStringUtility::StringAppendF(std::string* dst, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	StringAppendV(dst, format, ap);
	va_end(ap);
}

bool NFStringUtility::IsUTF8String(const std::string& str)
{
	int check_sub = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (check_sub == 0)
		{
			if ((str[i] >> 7) == 0)         //0xxx xxxx  
			{
				continue;
			}
			else if ((str[i] & 0xE0) == 0xC0) //110x xxxx  
			{
				check_sub = 1;
			}
			else if ((str[i] & 0xF0) == 0xE0) //1110 xxxx  
			{
				check_sub = 2;
			}
			else if ((str[i] & 0xF8) == 0xF0) //1111 0xxx  
			{
				check_sub = 3;
			}
			else if ((str[i] & 0xFC) == 0xF8) //1111 10xx  
			{
				check_sub = 4;
			}
			else if ((str[i] & 0xFE) == 0xFC) //1111 110x  
			{
				check_sub = 5;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ((str[i] & 0xC0) != 0x80)
			{
				return false;
			}
			check_sub--;
		}
	}
	return true;
}

std::string NFStringUtility::Demangle(const std::string& name)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	int status = 0;
	char *p = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
	std::string ret(p);
	free(p);
	return ret;
#else
	char buffer[1024];
	DWORD length = UnDecorateSymbolName(name.c_str(), buffer, sizeof(buffer), 0);
	if (length > 0)
		return std::string(buffer, length);
	else
		return name;
#endif
}

void NFStringUtility::SplitString(const std::string& sSrc, std::string sDelimit, std::vector<std::string>& vResult, std::string sNull_subst)
{
	typedef std::basic_string<char>::size_type s_t;
	if (sSrc.empty() || sDelimit.empty()) {
		//throw "split:empty string\0";
		return;
	}
	std::vector<std::string> v;
	s_t deli_len = sDelimit.size();
	s_t index = std::string::npos;
	s_t last_search_position = 0;
	while ((index = sSrc.find(sDelimit, last_search_position)) != std::string::npos) {
		if (index == last_search_position) {
			vResult.push_back(sNull_subst);
		}
		else {
			vResult.push_back(sSrc.substr(last_search_position, index
				- last_search_position));
		}
		last_search_position = index + deli_len;
	}
	std::string last_one = sSrc.substr(last_search_position);
	vResult.push_back(last_one.empty() ? sNull_subst : last_one);
}


void NFStringUtility::SplitStringToUint32(const std::string& strSrc, const std::string& strToken, std::vector<uint32_t>& vecResult, int nBase /*= 10*/)
{
	vecResult.clear();
	std::string::size_type nBegin = 0;
	std::string::size_type nEnd = 0;

	while ((nBegin = strSrc.find_first_not_of(strToken.c_str(), nEnd)) != std::string::npos)
	{
		nEnd = strSrc.find_first_of(strToken.c_str(), nBegin);
		vecResult.push_back((uint32_t)strtol(strSrc.substr(nBegin, nEnd - nBegin).c_str(), NULL, nBase));
	}
}

bool NFStringUtility::SplitStringToUint32Ex(const std::string& strSrc, vector<pair<uint32_t, uint32_t> >& vecResult)
{
	vecResult.clear();
	std::string::size_type nBegin = 0;
	std::string::size_type nEnd = 0;

	vector<uint32_t> tmpvec;
	std::string::size_type nSubBegin = 0;
	std::string::size_type nSubEnd = 0;

	while ((nBegin = strSrc.find_first_not_of("$", nEnd)) != std::string::npos)
	{
		nEnd = strSrc.find_first_of("$", nBegin);
		string strSubSrc = strSrc.substr(nBegin, nEnd - nBegin);
		nSubBegin = 0;
		nSubEnd = 0;
		tmpvec.clear();
		while ((nSubBegin = strSubSrc.find_first_not_of("~", nSubEnd)) != std::string::npos)
		{
			nSubEnd = strSubSrc.find_first_of("~", nSubBegin);
			tmpvec.push_back((uint32_t)strtol(strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str(), NULL, 10));
		}
		if (tmpvec.size() < 2)
		{
			return false;
		}
		vecResult.push_back(make_pair(tmpvec[0], tmpvec[1]));
	}

	return true;
}

bool NFStringUtility::SplitStringToInt32(const std::string& strSrc, std::vector<std::pair<int32_t, int32_t> >& vecResult)
{
	vecResult.clear();
	std::string::size_type nBegin = 0;
	std::string::size_type nEnd = 0;

	std::vector<int32_t> tmpvec;
	std::string::size_type nSubBegin = 0;
	std::string::size_type nSubEnd = 0;

	while ((nBegin = strSrc.find_first_not_of("$", nEnd)) != std::string::npos)
	{
		nEnd = strSrc.find_first_of("$", nBegin);
		string strSubSrc = strSrc.substr(nBegin, nEnd - nBegin);
		nSubBegin = 0;
		nSubEnd = 0;
		tmpvec.clear();
		while ((nSubBegin = strSubSrc.find_first_not_of("~", nSubEnd)) != std::string::npos)
		{
			nSubEnd = strSubSrc.find_first_of("~", nSubBegin);
			tmpvec.push_back((uint32_t)strtol(strSubSrc.substr(nSubBegin, nSubEnd - nSubBegin).c_str(), NULL, 10));
		}

		//只填了一个0的话  补齐成0~0
		if (tmpvec.size() == 1 && tmpvec[0] == 0)
		{
			tmpvec.push_back(0);
		}

		if (tmpvec.size() < 2)
		{
			return false;
		}
		vecResult.push_back(make_pair(tmpvec[0], tmpvec[1]));
	}

	return true;
}

const char *NFStringUtility::IpToStr(uint32_t dwIp)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	struct in_addr _in_addr;
	_in_addr.s_addr = dwIp;

	return inet_ntoa(_in_addr);
#else
	return NULL;
#endif
}

int  NFStringUtility::GetIpDotId(uint32_t dwIp, int iIPIndex)
{
	const char *pIp = IpToStr(dwIp);

	if (pIp == NULL)
	{
		return -1;
	}

	char szIp[25] = { 0 };
	snprintf(szIp, sizeof(szIp), "%s", pIp);

	char *pCurr = szIp;
	char *pNext = strchr(pCurr, '.');

	int i = 0;

	for (i = 0; i < iIPIndex && pNext != NULL; i++)
	{
		pCurr = pNext + 1;
		pNext = strchr(pCurr, '.');
	}

	if (i == iIPIndex)
	{
		if (pNext != NULL)
		{
			*pNext = '\0';
		}

		return atoi(pCurr);
	}
	else
	{
		return -1;
	}
}

int  NFStringUtility::IpToNum(const char *pszIp)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	struct in_addr _in_addr;
	_in_addr.s_addr = -1;

	inet_aton(pszIp, &_in_addr);

	return _in_addr.s_addr;
#else
	return 0;
#endif
}

int  NFStringUtility::GetServerIDFromBusID(uint32_t dwBusID)
{
	return GetIpDotId(dwBusID, 2);
}

const char * NFStringUtility::ServerIDToStr(uint32_t dwIp)
{
	return IpToStr(dwIp);
}

