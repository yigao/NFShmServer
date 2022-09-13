// -------------------------------------------------------------------------
//    @FileName         :    NFRandom.hpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <time.h>
#include <stdint.h>
#include <assert.h>
#include <random>
#include <string>

#include "NFPlatform.h"

// Copy from leveldb project
// @see https://github.com/google/leveldb/blob/master/util/random.h
//
// A very simple random number generator.  Not especially good at
// generating truly random bits, but good enough for our needs in this
// package.
class _NFExport NFRandom
{
public:
	explicit NFRandom(uint32_t s) : seed_(s & 0x7fffffffu)
	{
	}

	uint32_t Next()
	{
		static const uint32_t M = 2147483647L; // 2^31-1
		static const uint64_t A = 16807; // bits 14, 8, 7, 5, 2, 1, 0

		// We are computing
		//       seed_ = (seed_ * A) % M,    where M = 2^31-1
		//
		// seed_ must not be zero or M, or else all subsequent computed values
		// will be zero or M respectively.  For all other values, seed_ will end
		// up cycling through every number in [1,M-1]
		uint64_t product = seed_ * A;

		// Compute (product % M) using the fact that ((x << 31) % M) == x.
		seed_ = static_cast<uint32_t>((product >> 31) + (product & M));
		// The first reduction may overflow by 1 bit, so we may need to
		// repeat.  mod == M is not possible; using > allows the faster
		// sign-bit-based test.
		if (seed_ > M)
		{
			seed_ -= M;
		}

		return seed_;
	}

	// Returns a uniformly distributed value in the range [0..n-1]
	// REQUIRES: n > 0
	uint32_t Uniform(int n)
	{
		assert(n > 0);
		return Next() % n;
	}

	// Randomly returns true ~"1/n" of the time, and false otherwise.
	// REQUIRES: n > 0
	bool Onein(int n)
	{
		assert(n > 0);
		return (Next() % n) == 0;
	}

	// Skewed: pick "base" uniformly from range [0,max_log] and then
	// return "base" random bits.  The effect is to pick a number in the
	// range [0,2^max_log-1] with exponential bias towards smaller numbers.
	uint32_t Skewed(int max_log)
	{
		return Uniform(1 << Uniform(max_log + 1));
	}

private:
	uint32_t seed_;
};

_NFExport void NFRandomSeed();

_NFExport int32_t NFRandomAInt();

_NFExport uint32_t NFRandomAUInt();

_NFExport int32_t NFRandomInt(int32_t min, int32_t max);

_NFExport uint32_t NFRandomUInt(uint32_t min, uint32_t max);

_NFExport float NFRandomFloat(float min, float max);

_NFExport double NFRandomDouble(double min, double max);

_NFExport std::string NFRandomString(size_t nChar);

_NFExport std::string NFRandomEnglish(size_t nChar);;

//[min, max)范围内的随机数
template <typename T>
T NFRandInt(T min, T max)
{
	static std::default_random_engine generator(static_cast<uint32_t>(time(nullptr)));
	std::uniform_int_distribution<T> distribution(min, max - 1);
	return distribution(generator);
}

template <typename T>
T NFRandReal(T min, T max)
{
	static std::default_random_engine generator(time(nullptr));
	std::uniform_real_distribution<T> distribution(min, max);
	return distribution(generator);
}

