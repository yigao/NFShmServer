// -------------------------------------------------------------------------
//    @FileName         :    NFCommon.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFCommon.h"

#include <signal.h>
#include <string.h>
#include <cmath>
#include "NFTime.h"
#include "NFPlatform.h"

bool NFCommon::GetBit(uint32_t src, uint32_t pos)
{
	bool retval = false;
	if (pos <= sizeof(uint32_t) * 8 - 1) {
		uint32_t nMask = 1 << pos;
		retval = (src & nMask) == nMask;
	};
	return retval;
}

void NFCommon::SetBit(uint32_t &src, uint32_t pos, bool flag)
{
	if (pos <= sizeof(uint32_t) * 8 - 1) {
		if (flag) {
			src |= (1 << pos);
		}
		else {
			src &= ~(1 << pos);
		}
	};
}

//#if NF_PLATFORM == NF_PLATFORM_LINUX

template <>
std::string NFCommon::tostr<bool>(const bool &t)
{
	char buf[2];
	buf[0] = t ? '1' : '0';
	buf[1] = '\0';
	return std::string(buf);
}


template <>
std::string NFCommon::tostr<char>(const char &t)
{
	char buf[2];
	snprintf(buf, 2, "%c", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<unsigned char>(const unsigned char &t)
{
	char buf[2];
	snprintf(buf, 2, "%c", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<short>(const short &t)
{
	char buf[16];
	snprintf(buf, 16, "%d", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<unsigned short>(const unsigned short &t)
{
	char buf[16];
	snprintf(buf, 16, "%u", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<int>(const int &t)
{
	char buf[16];
	snprintf(buf, 16, "%d", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<unsigned int>(const unsigned int &t)
{
	char buf[16];
	snprintf(buf, 16, "%u", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<long>(const long &t)
{
	char buf[32];
	snprintf(buf, 32, "%ld", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<long long>(const long long &t)
{
	char buf[32];
	snprintf(buf, 32, "%lld", t);
	return std::string(buf);
}


template <>
std::string NFCommon::tostr<unsigned long>(const unsigned long &t)
{
	char buf[32];
	snprintf(buf, 32, "%lu", t);
	return std::string(buf);
}

template <>
std::string NFCommon::tostr<float>(const float &t)
{
	char buf[32];
	snprintf(buf, 32, "%.5f", t);
	std::string s(buf);

	//去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
	bool bFlag = false;
	int pos = int(s.size() - 1);
	for (; pos > 0; --pos)
	{
		if (s[pos] == '0')
		{
			bFlag = true;
			if (s[pos - 1] == '.')
			{
				//-2为了去掉"."号
				pos -= 2;
				break;
			}
		}
		else
		{
			break;
		}
	}

	if (bFlag)
		s = s.substr(0, pos + 1);

	return s;
}

template <>
std::string NFCommon::tostr<double>(const double &t)
{
	char buf[32];
	snprintf(buf, 32, "%.5f", t);
	std::string s(buf);

	//去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
	bool bFlag = false;
	int pos = int(s.size() - 1);
	for (; pos > 0; --pos)
	{
		if (s[pos] == '0')
		{
			bFlag = true;
			if (s[pos - 1] == '.')
			{
				//-2为了去掉"."号
				pos -= 2;
				break;
			}
		}
		else
		{
			break;
		}
	}

	if (bFlag)
		s = s.substr(0, pos + 1);

	return s;

}

template <>
std::string NFCommon::tostr<long double>(const long double &t)
{
	char buf[32];
	snprintf(buf, 32, "%Lf", t);
	std::string s(buf);

	//去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
	bool bFlag = false;
	int pos = int(s.size() - 1);
	for (; pos > 0; --pos)
	{
		if (s[pos] == '0')
		{
			bFlag = true;
			if (s[pos - 1] == '.')
			{
				//-2为了去掉"."号
				pos -= 2;
				break;
			}
		}
		else
		{
			break;
		}
	}

	if (bFlag)
		s = s.substr(0, pos + 1);

	return s;

}

template <>
std::string NFCommon::tostr<std::string>(const std::string &t)
{
	return t;
}

//#endif

std::string NFCommon::trim(const std::string &sStr, const std::string &s, bool bChar)
{
	if (sStr.empty())
	{
		return sStr;
	}

	/**
	* 将完全与s相同的字符串去掉
	*/
	if (!bChar)
	{
		return trimright(trimleft(sStr, s, false), s, false);
	}

	return trimright(trimleft(sStr, s, true), s, true);
}

std::string NFCommon::trimleft(const std::string &sStr, const std::string &s, bool bChar)
{
	if (sStr.empty())
	{
		return sStr;
	}

	/**
	* 去掉sStr左边的字符串s
	*/
	if (!bChar)
	{
		if (sStr.length() < s.length())
		{
			return sStr;
		}

		if (sStr.compare(0, s.length(), s) == 0)
		{
			return sStr.substr(s.length());
		}

		return sStr;
	}

	/**
	* 去掉sStr左边的 字符串s中的字符
	*/
	std::string::size_type pos = 0;
	while (pos < sStr.length())
	{
		if (s.find_first_of(sStr[pos]) == std::string::npos)
		{
			break;
		}

		pos++;
	}

	if (pos == 0) return sStr;

	return sStr.substr(pos);
}

std::string NFCommon::trimright(const std::string &sStr, const std::string &s, bool bChar)
{
	if (sStr.empty())
	{
		return sStr;
	}

	/**
	* 去掉sStr右边的字符串s
	*/
	if (!bChar)
	{
		if (sStr.length() < s.length())
		{
			return sStr;
		}

		if (sStr.compare(sStr.length() - s.length(), s.length(), s) == 0)
		{
			return sStr.substr(0, sStr.length() - s.length());
		}

		return sStr;
	}

	/**
	* 去掉sStr右边的 字符串s中的字符
	*/
	std::string::size_type pos = sStr.length();
	while (pos != 0)
	{
		if (s.find_first_of(sStr[pos - 1]) == std::string::npos)
		{
			break;
		}

		pos--;
	}

	if (pos == sStr.length()) return sStr;

	return sStr.substr(0, pos);
}

std::string NFCommon::lower(const std::string &s)
{
	std::string sString = s;
	for (std::string::iterator iter = sString.begin(); iter != sString.end(); ++iter)
	{
		*iter = tolower(*iter);
	}

	return sString;
}

std::string NFCommon::upper(const std::string &s)
{
	std::string sString = s;

	for (std::string::iterator iter = sString.begin(); iter != sString.end(); ++iter)
	{
		*iter = toupper(*iter);
	}

	return sString;
}

bool NFCommon::isdigit(const std::string &sInput)
{
	std::string::const_iterator iter = sInput.begin();

	if (sInput.empty())
	{
		return false;
	}

	while (iter != sInput.end())
	{
		if (!::isdigit(*iter))
		{
			return false;
		}
		++iter;
	}
	return true;
}

int NFCommon::str2tm(const std::string &sString, const std::string &sFormat, struct tm &stTm)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	char *p = strptime(sString.c_str(), sFormat.c_str(), &stTm);
	return (p != NULL) ? 0 : -1;
#else
	return 0;
#endif
}

int NFCommon::strgmt2tm(const std::string &sString, struct tm &stTm)
{
	return str2tm(sString, "%a, %d %b %Y %H:%M:%S GMT", stTm);
}

std::string NFCommon::tm2str(const struct tm &stTm, const std::string &sFormat)
{
	char sTimeString[255] = "\0";

	strftime(sTimeString, sizeof(sTimeString), sFormat.c_str(), &stTm);

	return std::string(sTimeString);
}

std::string NFCommon::tm2str(const time_t &t, const std::string &sFormat)
{
	struct tm tt;
	localtime_r(&t, &tt);

	return tm2str(tt, sFormat);
}

std::string NFCommon::now2str(const std::string &sFormat)
{
	time_t t = time(NULL);
	return tm2str(t, sFormat.c_str());
}

std::string NFCommon::now2GMTstr()
{
	time_t t = time(NULL);
	return tm2GMTstr(t);
}

std::string NFCommon::tm2GMTstr(const time_t &t)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	struct tm tt;
	gmtime_r(&t, &tt);
	return tm2str(tt, "%a, %d %b %Y %H:%M:%S GMT");
#else
	return std::string();
#endif
}

std::string NFCommon::tm2GMTstr(const struct tm &stTm)
{
	return tm2str(stTm, "%a, %d %b %Y %H:%M:%S GMT");
}

std::string NFCommon::nowdate2str()
{
	return now2str("%Y%m%d");
}

std::string NFCommon::nowtime2str()
{
	return now2str("%H%M%S");
}

int64_t NFCommon::now2ms()
{
	return NFTime::Tick();
}

int64_t NFCommon::now2us()
{
	return NFGetMicroSecondTime();
}

//参照phorix的优化
static char c_b2s[256][4] = { "00","01","02","03","04","05","06","07","08","09","0a","0b","0c","0d","0e","0f","10","11","12","13","14","15","16","17","18","19","1a","1b","1c","1d","1e","1f","20","21","22","23","24","25","26","27","28","29","2a","2b","2c","2d","2e","2f","30","31","32","33","34","35","36","37","38","39","3a","3b","3c","3d","3e","3f","40","41","42","43","44","45","46","47","48","49","4a","4b","4c","4d","4e","4f","50","51","52","53","54","55","56","57","58","59","5a","5b","5c","5d","5e","5f","60","61","62","63","64","65","66","67","68","69","6a","6b","6c","6d","6e","6f","70","71","72","73","74","75","76","77","78","79","7a","7b","7c","7d","7e","7f","80","81","82","83","84","85","86","87","88","89","8a","8b","8c","8d","8e","8f","90","91","92","93","94","95","96","97","98","99","9a","9b","9c","9d","9e","9f","a0","a1","a2","a3","a4","a5","a6","a7","a8","a9","aa","ab","ac","ad","ae","af","b0","b1","b2","b3","b4","b5","b6","b7","b8","b9","ba","bb","bc","bd","be","bf","c0","c1","c2","c3","c4","c5","c6","c7","c8","c9","ca","cb","cc","cd","ce","cf","d0","d1","d2","d3","d4","d5","d6","d7","d8","d9","da","db","dc","dd","de","df","e0","e1","e2","e3","e4","e5","e6","e7","e8","e9","ea","eb","ec","ed","ee","ef","f0","f1","f2","f3","f4","f5","f6","f7","f8","f9","fa","fb","fc","fd","fe","ff" };

std::string NFCommon::bin2str(const void *buf, size_t len, const std::string &sSep, size_t lines)
{
	if (buf == NULL || len <= 0)
	{
		return "";
	}

	std::string sOut;
	const unsigned char *p = (const unsigned char *)buf;

	for (size_t i = 0; i < len; ++i, ++p)
	{
		sOut += c_b2s[*p][0];
		sOut += c_b2s[*p][1];
		sOut += sSep;

		//换行
		if ((lines != 0) && ((i + 1) % lines == 0))
		{
			sOut += "\n";
		}
	}

	return sOut;
}

std::string NFCommon::bin2str(const std::string &sBinData, const std::string &sSep, size_t lines)
{
	return bin2str((const void *)sBinData.data(), sBinData.length(), sSep, lines);
}

int NFCommon::str2bin(const char *psAsciiData, unsigned char *sBinData, int iBinSize)
{
	int iAsciiLength = strlen(psAsciiData);

	int iRealLength = (iAsciiLength / 2 > iBinSize) ? iBinSize : (iAsciiLength / 2);
	for (int i = 0; i < iRealLength; i++)
	{
		sBinData[i] = x2c(psAsciiData + i * 2);
	}
	return iRealLength;
}

std::string NFCommon::str2bin(const std::string &sString, const std::string &sSep, size_t lines)
{
	const char *psAsciiData = sString.c_str();

	int iAsciiLength = sString.length();
	std::string sBinData;
	for (int i = 0; i < iAsciiLength; i++)
	{
		sBinData += x2c(psAsciiData + i);
		i++;
		i += sSep.length(); //过滤掉分隔符

		if (lines != 0 && sBinData.length() % lines == 0)
		{
			i++;    //过滤掉回车
		}
	}

	return sBinData;
}

char NFCommon::x2c(const std::string &sWhat)
{
	register char digit;

	if (sWhat.length() < 2)
	{
		return '\0';
	}

	digit = (sWhat[0] >= 'A' ? ((sWhat[0] & 0xdf) - 'A') + 10 : (sWhat[0] - '0'));
	digit *= 16;
	digit += (sWhat[1] >= 'A' ? ((sWhat[1] & 0xdf) - 'A') + 10 : (sWhat[1] - '0'));

	return(digit);
}

std::string NFCommon::replace(const std::string &sString, const std::string &sSrc, const std::string &sDest)
{
	if (sSrc.empty())
	{
		return sString;
	}

	std::string sBuf = sString;

	std::string::size_type pos = 0;

	while ((pos = sBuf.find(sSrc, pos)) != std::string::npos)
	{
		sBuf.replace(pos, sSrc.length(), sDest);
		pos += sDest.length();
	}

	return sBuf;
}

std::string NFCommon::replace(const std::string &sString, const std::map<std::string, std::string>& mSrcDest)
{
	if (sString.empty())
	{
		return sString;
	}

	std::string tmp = sString;
	std::map<std::string, std::string>::const_iterator it = mSrcDest.begin();

	while (it != mSrcDest.end())
	{

		std::string::size_type pos = 0;
		while ((pos = tmp.find(it->first, pos)) != std::string::npos)
		{
			tmp.replace(pos, it->first.length(), it->second);
			pos += it->second.length();
		}

		++it;
	}

	return tmp;
}

bool NFCommon::matchPeriod(const std::string& s, const std::string& pat)
{
	if (s.empty())
	{
		return false;
	}

	if (pat.empty())
	{
		return true;
	}

	if (pat.find('*') == std::string::npos)
	{
		return s == pat;
	}

	std::string::size_type sIndex = 0;
	std::string::size_type patIndex = 0;
	do
	{
		if (pat[patIndex] == '*')
		{
			if (s[sIndex] == '.')
			{
				return false;
			}

			while (sIndex < s.size() && s[sIndex] != '.')
			{
				++sIndex;
			}
			patIndex++;
		}
		else
		{
			if (pat[patIndex] != s[sIndex])
			{
				return false;
			}
			++sIndex;
			++patIndex;
		}
	} while (sIndex < s.size() && patIndex < pat.size());

	return sIndex == s.size() && patIndex == pat.size();
}

bool NFCommon::matchPeriod(const std::string& s, const std::vector<std::string>& pat)
{
	for (size_t i = 0; i < pat.size(); i++)
	{
		if (NFCommon::matchPeriod(s, pat[i]))
		{
			return true;
		}
	}
	return false;
}

bool NFCommon::isPrimeNumber(size_t n)
{
	size_t nn = (size_t)sqrt((double)n);
	for (size_t i = 2; i < nn; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

size_t NFCommon::toSize(const std::string &s, size_t iDefaultSize)
{
	if (s.empty())
	{
		return iDefaultSize;
	}

	char c = s[s.length() - 1];
	if (c != 'K' && c != 'M' && c != 'G' && NFCommon::trim(s) == NFCommon::tostr(NFCommon::strto<size_t>(s)))
	{
		//没有后缀, 且转换是正确的
		return (size_t)(NFCommon::strto<size_t>(s));
	}
	else if (c == 'K' || c == 'M' || c == 'G')
	{
		if (s.length() == 1)
		{
			return iDefaultSize;
		}

		float n = NFCommon::strto<float>(s.substr(0, s.length() - 1));

		if (NFCommon::trim(s.substr(0, s.length() - 1)) != NFCommon::tostr<float>(n))
		{
			return iDefaultSize;
		}

		if (c == 'K')
		{
			return (size_t)(n * 1024);
		}
		if (c == 'M')
		{
			return (size_t)(n * 1024 * 1024);
		}
		if (c == 'G') //-V547
		{
			return (size_t)(n * 1024 * 1024 * 1024);
		}
	}

	return iDefaultSize;
}

NFIdGenerator::NFIdGenerator(uint64_t server_id)
{
	m_nServerID = server_id;
	m_nLastTime = time(NULL);
	m_nLastID = (m_nServerID << 52) + (m_nLastTime << 20) + 0;
}

uint64_t NFIdGenerator::GenId()
{
	uint64_t nCurrTime = time(NULL);
	if (nCurrTime == m_nLastTime)
	{
		return ++m_nLastID;
	}

	m_nLastTime = nCurrTime;
	m_nLastID = (m_nServerID << 52) + (m_nLastTime << 20) + 0;
	return m_nLastID;
}

bool NFCommon::IsValidPhone(const std::string& phone)
{
    return true;
}
