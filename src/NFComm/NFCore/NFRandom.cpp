// -------------------------------------------------------------------------
//    @FileName         :    NFRandom.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFRandom.hpp"
#include "NFTime.h"
#include <vector>

static uint32_t g_seed = 0;
static const uint32_t g_nNull = 0;
static const uint32_t g_nOne = 1;
static const uint32_t g_nPar1 = 214013;
static const uint32_t g_nPar2 = 2531011;
static const uint32_t g_nPar3 = 15;
static const uint32_t g_nPar4 = 16;
static const float g_fPar5 = 1.0f / 65535.0f;
static const double g_dPar6 = 1.0 / 4294967295.0;
static const uint32_t g_nPar7 = 0x7fffffff;

void NFRandomSeed()
{
	g_seed = static_cast<uint32_t>(NFTime::Tick());
}

uint32_t NFRandomAUInt()
{
	g_seed = g_nPar1 * g_seed + g_nPar2;
	return (g_seed ^ g_seed >> g_nPar3);
}

uint32_t NFRandomUInt(uint32_t min, uint32_t max)
{
	if (min > max)
	{
		return max;
	}

	return min + NFRandomAUInt() % (max - min + g_nOne);
}

int32_t NFRandomAInt()
{
	return static_cast<int32_t>(NFRandomUInt(g_nNull, g_nPar7));
}

int32_t NFRandomInt(int32_t min, int32_t max)
{
	if (min > max)
	{
		return max;
	}

	return min + static_cast<int32_t>(NFRandomAUInt() % (max - min + g_nOne));
}

float NFRandomFloat(float min, float max)
{
	if (min > max)
	{
		return max;
	}

	g_seed = g_nPar1 * g_seed + g_nPar2;
	return min + (g_seed >> g_nPar4) * g_fPar5 * (max - min);
}

double NFRandomDouble(double min, double max)
{
	if (min > max)
	{
		return max;
	}

	g_seed = g_nPar1 * g_seed + g_nPar2;
	return min + g_seed * g_dPar6 * (max - min);
}

//随机字符串
std::string NFRandomString(size_t nChar)
{
	static std::string strList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string str;
	for (size_t i = 0; i < nChar; i++)
	{
		size_t index = NFRandInt((int)0, (int)strList.size());
		str += strList[index];
	}
	return str;
}

//随机英文
std::string NFRandomEnglish(size_t nChar)
{
	static std::string strList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string str;
	for (size_t i = 0; i < nChar; i++)
	{
		size_t index = NFRandInt((int)0, (int)strList.size());
		str += strList[index];
	}
	return str;
}

