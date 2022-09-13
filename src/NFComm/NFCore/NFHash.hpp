// -------------------------------------------------------------------------
//    @FileName         :    NFHash.hpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <cstdint>
#include <cstring>
#include <limits>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

#define EXPLICIT_FALLTHROUGH

#if defined(_MSC_VER)

#include <stdlib.h>

#define ROTL32(x, y) _rotl(x, y)
#define ROTL64(x, y) _rotl64(x, y)

#define BIG_CONSTANT(x) (x)

	// Other compilers

#else // defined(_MSC_VER)

#define FORCE_INLINE inline __attribute__((always_inline))

inline uint32_t rotl32(uint32_t x, int8_t r) { return (x << r) | (x >> (32 - r)); }

inline uint64_t rotl64(uint64_t x, int8_t r) { return (x << r) | (x >> (64 - r)); }

#define ROTL32(x, y) rotl32(x, y)
#define ROTL64(x, y) rotl64(x, y)

#define BIG_CONSTANT(x) (x##LLU)

#endif // !defined(_MSC_VER)

/**
 *@brief  程序中hash_combine函数主要摘自开源库folly，保证稳定可靠
 */
namespace NFHash
{
	inline uint32_t getblock32(const uint32_t *p, int i) { return p[i]; }

	inline uint64_t getblock64(const uint64_t *p, int i) { return p[i]; }

	inline uint32_t fmix32(uint32_t h) {
		h ^= h >> 16;
		h *= 0x85ebca6b;
		h ^= h >> 13;
		h *= 0xc2b2ae35;
		h ^= h >> 16;

		return h;
	}

	//----------

	inline uint64_t fmix64(uint64_t k) {
		k ^= k >> 33;
		k *= BIG_CONSTANT(0xff51afd7ed558ccd);
		k ^= k >> 33;
		k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
		k ^= k >> 33;

		return k;
	}

	// ===================== MurmurHash2 =====================
	//-----------------------------------------------------------------------------

	inline uint32_t murmur_hash2(const void *key, int len, uint32_t seed) {
		// 'm' and 'r' are mixing constants generated offline.
		// They're not really 'magic', they just happen to work well.

		const uint32_t m = 0x5bd1e995;
		const int      r = 24;

		// Initialize the hash to a 'random' value

		uint32_t h = seed ^ len;

		// Mix 4 bytes at a time into the hash

		const unsigned char *data = (const unsigned char *)key;

		while (len >= 4) {
			uint32_t k = *(uint32_t *)data;

			k *= m;
			k ^= k >> r;
			k *= m;

			h *= m;
			h ^= k;

			data += 4;
			len -= 4;
		}

		// Handle the last few bytes of the input array

		switch (len) {
		case 3:
			h ^= data[2] << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			h ^= data[1] << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			h ^= data[0];
			h *= m;
		};

		// Do a few final mixes of the hash to ensure the last few
		// bytes are well-incorporated.

		h ^= h >> 13;
		h *= m;
		h ^= h >> 15;

		return h;
	}

	//-----------------------------------------------------------------------------
	// MurmurHash2, 64-bit versions, by Austin Appleby

	// The same caveats as 32-bit MurmurHash2 apply here - beware of alignment
	// and endian-ness issues if used across multiple platforms.

	// 64-bit hash for 64-bit platforms

	inline uint64_t murmur_hash2_64a(const void *key, int len, uint64_t seed) {
		const uint64_t m = BIG_CONSTANT(0xc6a4a7935bd1e995);
		const int      r = 47;

		uint64_t h = seed ^ (len * m);

		const uint64_t *data = (const uint64_t *)key;
		const uint64_t *end = data + (len / 8);

		while (data != end) {
			uint64_t k = *data++;

			k *= m;
			k ^= k >> r;
			k *= m;

			h ^= k;
			h *= m;
		}

		const unsigned char *data2 = (const unsigned char *)data;

		switch (len & 7) {
		case 7:
			h ^= uint64_t(data2[6]) << 48;
			EXPLICIT_FALLTHROUGH
		case 6:
			h ^= uint64_t(data2[5]) << 40;
			EXPLICIT_FALLTHROUGH
		case 5:
			h ^= uint64_t(data2[4]) << 32;
			EXPLICIT_FALLTHROUGH
		case 4:
			h ^= uint64_t(data2[3]) << 24;
			EXPLICIT_FALLTHROUGH
		case 3:
			h ^= uint64_t(data2[2]) << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			h ^= uint64_t(data2[1]) << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			h ^= uint64_t(data2[0]);
			h *= m;
		};

		h ^= h >> r;
		h *= m;
		h ^= h >> r;

		return h;
	}


	// 64-bit hash for 32-bit platforms

	inline uint64_t murmur_hash2_64b(const void *key, int len, uint64_t seed) {
		const uint32_t m = 0x5bd1e995;
		const int      r = 24;

		uint32_t h1 = uint32_t(seed) ^ len;
		uint32_t h2 = uint32_t(seed >> 32);

		const uint32_t *data = (const uint32_t *)key;

		while (len >= 8) {
			uint32_t k1 = *data++;
			k1 *= m;
			k1 ^= k1 >> r;
			k1 *= m;
			h1 *= m;
			h1 ^= k1;
			len -= 4;

			uint32_t k2 = *data++;
			k2 *= m;
			k2 ^= k2 >> r;
			k2 *= m;
			h2 *= m;
			h2 ^= k2;
			len -= 4;
		}

		if (len >= 4) {
			uint32_t k1 = *data++;
			k1 *= m;
			k1 ^= k1 >> r;
			k1 *= m;
			h1 *= m;
			h1 ^= k1;
			len -= 4;
		}

		switch (len) {
		case 3:
			h2 ^= ((unsigned char *)data)[2] << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			h2 ^= ((unsigned char *)data)[1] << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			h2 ^= ((unsigned char *)data)[0];
			h2 *= m;
		};

		h1 ^= h2 >> 18;
		h1 *= m;
		h2 ^= h1 >> 22;
		h2 *= m;
		h1 ^= h2 >> 17;
		h1 *= m;
		h2 ^= h1 >> 19;
		h2 *= m;

		uint64_t h = h1;

		h = (h << 32) | h2;

		return h;
	}

	// ===================== MurmurHash3 =====================
	inline uint32_t murmur_hash3_x86_32(const void *key, int len, uint32_t seed) {
		const uint8_t *data = (const uint8_t *)key;
		const int      nblocks = len / 4;

		uint32_t h1 = seed;

		const uint32_t c1 = 0xcc9e2d51;
		const uint32_t c2 = 0x1b873593;

		//----------
		// body

		const uint32_t *blocks = (const uint32_t *)(data + nblocks * 4);

		for (int i = -nblocks; i; i++) {
			uint32_t k1 = getblock32(blocks, i);

			k1 *= c1;
			k1 = ROTL32(k1, 15);
			k1 *= c2;

			h1 ^= k1;
			h1 = ROTL32(h1, 13);
			h1 = h1 * 5 + 0xe6546b64;
		}

		//----------
		// tail

		const uint8_t *tail = (const uint8_t *)(data + nblocks * 4);

		uint32_t k1 = 0;

		switch (len & 3) {
		case 3:
			k1 ^= tail[2] << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			k1 ^= tail[1] << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			k1 ^= tail[0];
			k1 *= c1;
			k1 = ROTL32(k1, 15);
			k1 *= c2;
			h1 ^= k1;
		};

		//----------
		// finalization

		h1 ^= len;

		h1 = fmix32(h1);

		return h1;
	}

	//-----------------------------------------------------------------------------

	inline void murmur_hash3_x86_128(const void *key, const int len, uint32_t seed, uint32_t out[4]) {
		const uint8_t *data = (const uint8_t *)key;
		const int      nblocks = len / 16;

		uint32_t h1 = seed;
		uint32_t h2 = seed;
		uint32_t h3 = seed;
		uint32_t h4 = seed;

		const uint32_t c1 = 0x239b961b;
		const uint32_t c2 = 0xab0e9789;
		const uint32_t c3 = 0x38b34ae5;
		const uint32_t c4 = 0xa1e38b93;

		//----------
		// body

		const uint32_t *blocks = (const uint32_t *)(data + nblocks * 16);

		for (int i = -nblocks; i; i++) {
			uint32_t k1 = getblock32(blocks, i * 4 + 0);
			uint32_t k2 = getblock32(blocks, i * 4 + 1);
			uint32_t k3 = getblock32(blocks, i * 4 + 2);
			uint32_t k4 = getblock32(blocks, i * 4 + 3);

			k1 *= c1;
			k1 = ROTL32(k1, 15);
			k1 *= c2;
			h1 ^= k1;

			h1 = ROTL32(h1, 19);
			h1 += h2;
			h1 = h1 * 5 + 0x561ccd1b;

			k2 *= c2;
			k2 = ROTL32(k2, 16);
			k2 *= c3;
			h2 ^= k2;

			h2 = ROTL32(h2, 17);
			h2 += h3;
			h2 = h2 * 5 + 0x0bcaa747;

			k3 *= c3;
			k3 = ROTL32(k3, 17);
			k3 *= c4;
			h3 ^= k3;

			h3 = ROTL32(h3, 15);
			h3 += h4;
			h3 = h3 * 5 + 0x96cd1c35;

			k4 *= c4;
			k4 = ROTL32(k4, 18);
			k4 *= c1;
			h4 ^= k4;

			h4 = ROTL32(h4, 13);
			h4 += h1;
			h4 = h4 * 5 + 0x32ac3b17;
		}

		//----------
		// tail

		const uint8_t *tail = (const uint8_t *)(data + nblocks * 16);

		uint32_t k1 = 0;
		uint32_t k2 = 0;
		uint32_t k3 = 0;
		uint32_t k4 = 0;

		switch (len & 15) {
		case 15:
			k4 ^= tail[14] << 16;
			EXPLICIT_FALLTHROUGH
		case 14:
			k4 ^= tail[13] << 8;
			EXPLICIT_FALLTHROUGH
		case 13:
			k4 ^= tail[12] << 0;
			k4 *= c4;
			k4 = ROTL32(k4, 18);
			k4 *= c1;
			h4 ^= k4;
			EXPLICIT_FALLTHROUGH
		case 12:
			k3 ^= tail[11] << 24;
			EXPLICIT_FALLTHROUGH
		case 11:
			k3 ^= tail[10] << 16;
			EXPLICIT_FALLTHROUGH
		case 10:
			k3 ^= tail[9] << 8;
			EXPLICIT_FALLTHROUGH
		case 9:
			k3 ^= tail[8] << 0;
			k3 *= c3;
			k3 = ROTL32(k3, 17);
			k3 *= c4;
			h3 ^= k3;
			EXPLICIT_FALLTHROUGH
		case 8:
			k2 ^= tail[7] << 24;
			EXPLICIT_FALLTHROUGH
		case 7:
			k2 ^= tail[6] << 16;
			EXPLICIT_FALLTHROUGH
		case 6:
			k2 ^= tail[5] << 8;
			EXPLICIT_FALLTHROUGH
		case 5:
			k2 ^= tail[4] << 0;
			k2 *= c2;
			k2 = ROTL32(k2, 16);
			k2 *= c3;
			h2 ^= k2;
			EXPLICIT_FALLTHROUGH
		case 4:
			k1 ^= tail[3] << 24;
			EXPLICIT_FALLTHROUGH
		case 3:
			k1 ^= tail[2] << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			k1 ^= tail[1] << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			k1 ^= tail[0] << 0;
			k1 *= c1;
			k1 = ROTL32(k1, 15);
			k1 *= c2;
			h1 ^= k1;
		};

		//----------
		// finalization

		h1 ^= len;
		h2 ^= len;
		h3 ^= len;
		h4 ^= len;

		h1 += h2;
		h1 += h3;
		h1 += h4;
		h2 += h1;
		h3 += h1;
		h4 += h1;

		h1 = fmix32(h1);
		h2 = fmix32(h2);
		h3 = fmix32(h3);
		h4 = fmix32(h4);

		h1 += h2;
		h1 += h3;
		h1 += h4;
		h2 += h1;
		h3 += h1;
		h4 += h1;

		out[0] = h1;
		out[1] = h2;
		out[2] = h3;
		out[3] = h4;
	}

	//-----------------------------------------------------------------------------

	inline void murmur_hash3_x64_128(const void *key, const int len, const uint32_t seed, uint64_t out[2]) {
		const uint8_t *data = (const uint8_t *)key;
		const int      nblocks = len / 16;

		uint64_t h1 = seed;
		uint64_t h2 = seed;

		const uint64_t c1 = BIG_CONSTANT(0x87c37b91114253d5);
		const uint64_t c2 = BIG_CONSTANT(0x4cf5ad432745937f);

		//----------
		// body

		const uint64_t *blocks = (const uint64_t *)(data);

		for (int i = 0; i < nblocks; i++) {
			uint64_t k1 = getblock64(blocks, i * 2 + 0);
			uint64_t k2 = getblock64(blocks, i * 2 + 1);

			k1 *= c1;
			k1 = ROTL64(k1, 31);
			k1 *= c2;
			h1 ^= k1;

			h1 = ROTL64(h1, 27);
			h1 += h2;
			h1 = h1 * 5 + 0x52dce729;

			k2 *= c2;
			k2 = ROTL64(k2, 33);
			k2 *= c1;
			h2 ^= k2;

			h2 = ROTL64(h2, 31);
			h2 += h1;
			h2 = h2 * 5 + 0x38495ab5;
		}

		//----------
		// tail

		const uint8_t *tail = (const uint8_t *)(data + nblocks * 16);

		uint64_t k1 = 0;
		uint64_t k2 = 0;

		switch (len & 15) {
		case 15:
			k2 ^= ((uint64_t)tail[14]) << 48;
			EXPLICIT_FALLTHROUGH
		case 14:
			k2 ^= ((uint64_t)tail[13]) << 40;
			EXPLICIT_FALLTHROUGH
		case 13:
			k2 ^= ((uint64_t)tail[12]) << 32;
			EXPLICIT_FALLTHROUGH
		case 12:
			k2 ^= ((uint64_t)tail[11]) << 24;
			EXPLICIT_FALLTHROUGH
		case 11:
			k2 ^= ((uint64_t)tail[10]) << 16;
			EXPLICIT_FALLTHROUGH
		case 10:
			k2 ^= ((uint64_t)tail[9]) << 8;
			EXPLICIT_FALLTHROUGH
		case 9:
			k2 ^= ((uint64_t)tail[8]) << 0;
			k2 *= c2;
			k2 = ROTL64(k2, 33);
			k2 *= c1;
			h2 ^= k2;
			EXPLICIT_FALLTHROUGH
		case 8:
			k1 ^= ((uint64_t)tail[7]) << 56;
			EXPLICIT_FALLTHROUGH
		case 7:
			k1 ^= ((uint64_t)tail[6]) << 48;
			EXPLICIT_FALLTHROUGH
		case 6:
			k1 ^= ((uint64_t)tail[5]) << 40;
			EXPLICIT_FALLTHROUGH
		case 5:
			k1 ^= ((uint64_t)tail[4]) << 32;
			EXPLICIT_FALLTHROUGH
		case 4:
			k1 ^= ((uint64_t)tail[3]) << 24;
			EXPLICIT_FALLTHROUGH
		case 3:
			k1 ^= ((uint64_t)tail[2]) << 16;
			EXPLICIT_FALLTHROUGH
		case 2:
			k1 ^= ((uint64_t)tail[1]) << 8;
			EXPLICIT_FALLTHROUGH
		case 1:
			k1 ^= ((uint64_t)tail[0]) << 0;
			k1 *= c1;
			k1 = ROTL64(k1, 31);
			k1 *= c2;
			h1 ^= k1;
		};

		//----------
		// finalization

		h1 ^= len;
		h2 ^= len;

		h1 += h2;
		h2 += h1;

		h1 = fmix64(h1);
		h2 = fmix64(h2);

		h1 += h2;
		h2 += h1;

		out[0] = h1;
		out[1] = h2;
	}
	//来自TARS的hash算法
	/////////////////////////////////////////////////
	/**
	* @file NFHash.h
	* @brief hash算法.
	*可以对输入的字节流进行hash得到相当均匀的hash值
	*
	*
	*/
	/////////////////////////////////////////////////

	template <class _Key> struct hash { };
	template <class _Key> struct hash_new { };

	inline size_t hash_string(const char* s)
	{
		unsigned long h = 0;
		for (; *s; ++s)
			h = 5 * h + *s;

		return size_t(h);
	}

	//////////////////////////////////////////////////////////
	/**
	* @brief 尽量采用hash_new, 更均衡一些.
	*
	*可以对输入的字节流进行hash得到相当均匀的hash值
	*/
	//////////////////////////////////////////////////////////
	template <>
	struct hash<std::string>
	{
		size_t operator()(const std::string &s) const
		{
			size_t h = 0, g;
			const char *arKey = s.c_str();
			size_t nKeyLength = s.length();
			const char *arEnd = arKey + nKeyLength;
			while (arKey < arEnd)
			{
				h = (h << 4) + *arKey++;
				if ((g = (h & 0xF0000000)))
				{
					h = h ^ (g >> 24);
					h = h ^ g;
				}
			}
			return h;
		}
	};

	template <>
	struct hash_new<std::string>
	{
		size_t operator()(const std::string &s) const
		{
			const char *ptr = s.c_str();
			size_t key_length = s.length();
			uint32_t value = 0;

			while (key_length--)
			{
				value += *ptr++;
				value += (value << 10);
				value ^= (value >> 6);
			}
			value += (value << 3);
			value ^= (value >> 11);
			value += (value << 15);

			return value == 0 ? 1 : value;
		}
	};

	template <>
	struct hash<char*>
	{
		size_t operator()(const char* s) const { return hash_string(s); }
	};

	template <>
	struct hash<const char*>
	{
		size_t operator()(const char* s) const { return hash_string(s); }
	};

	template <>
	struct hash<char>
	{
		size_t operator()(char x) const { return x; }
	};

	template <>
	struct hash<unsigned char>
	{
		size_t operator()(unsigned char x) const { return x; }
	};

	template <>
	struct hash<signed char>
	{
		size_t operator()(unsigned char x) const { return x; }
	};

	template <>
	struct hash<short>
	{
		size_t operator()(short x) const { return x; }
	};

	template <>
	struct hash<unsigned short>
	{
		size_t operator()(unsigned short x) const { return x; }
	};

	template <>
	struct hash<int>
	{
		size_t operator()(int x) const { return x; }
	};

	template <>
	struct hash<unsigned int>
	{
		size_t operator()(unsigned int x) const { return x; }
	};

	template <>
	struct hash<long>
	{
		size_t operator()(long x) const { return x; }
	};

	template <>
	struct hash<unsigned long>
	{
		size_t operator()(unsigned long x) const { return x; }
	};

	/**
	* @brief 一个奇妙的hash算法.
	*
	*可以对输入的字节流进行hash得到相当均匀的hash值
	*/
	struct magic_string_hash
	{
		size_t operator()(const std::string &s) const
		{
			const char *ptr = s.c_str();
			size_t key_length = s.length();
			uint32_t value = 0;

			while (key_length--)
			{
				value += *ptr++;
				value += (value << 10);
				value ^= (value >> 6);
			}
			value += (value << 3);
			value ^= (value >> 11);
			value += (value << 15);

			return value == 0 ? 1 : value;
		}
	};

	//////////////////////////////////////////////////////////////////////////


	// This is a general-purpose way to create a single hash from multiple
	// hashable objects. hash_combine_generic takes a class Hasher implementing
	// hash<T>; hash_combine uses a default hasher StdHasher that uses std::hash.
	// hash_combine_generic hashes each argument and combines those hashes in
	// an order-dependent way to yield a new hash.

	// This is the Hash128to64 function from Google's cityhash (available
	// under the MIT License).  We use it to reduce multiple 64 bit hashes
	// into a single hash.
	inline uint64_t hash_128_to_64(
		const uint64_t upper,
		const uint64_t lower) noexcept
	{
		// Murmur-inspired hashing.
		const uint64_t kMul = 0x9ddfea08eb382d69ULL;
		uint64_t a = (lower ^ upper) * kMul;
		a ^= (a >> 47);
		uint64_t b = (upper ^ a) * kMul;
		b ^= (b >> 47);
		b *= kMul;
		return b;
	}

	// Never used, but gcc demands it.
	template <class Hasher>
	inline size_t hash_combine_generic()
	{
		return 0;
	}

	template <
		class Iter,
		class Hash = std::hash<typename std::iterator_traits<Iter>::value_type>>
	uint64_t
	hash_range(Iter begin, Iter end, uint64_t hash = 0, Hash hasher = Hash())
	{
		for (; begin != end; ++begin)
		{
			hash = hash_128_to_64(hash, hasher(*begin));
		}
		return hash;
	}

	inline uint32_t twang_32from64(uint64_t key) noexcept;

	template <class Hasher, typename T, typename... Ts>
	size_t hash_combine_generic(const T& t, const Ts&... ts)
	{
		size_t seed = Hasher::hash(t);
		if (sizeof...(ts) == 0)
		{
			return seed;
		}
		size_t remainder = hash_combine_generic<Hasher>(ts...);
		/* static */
		if (sizeof(size_t) == sizeof(uint32_t))
		{
			return twang_32from64((uint64_t(seed) << 32) | remainder);
		}
		else
		{
			return static_cast<size_t>(hash_128_to_64(seed, remainder));
		}
	}

	// Simply uses std::hash to hash.  Note that std::hash is not guaranteed
	// to be a very good hash function; provided std::hash doesn't collide on
	// the individual inputs, you are fine, but that won't be true for, say,
	// strings or pairs
	class StdHasher
	{
	public:
		// The standard requires all explicit and partial specializations of std::hash
		// supplied by either the standard library or by users to be default
		// constructible.
		template <typename T>
		static size_t hash(const T& t) noexcept(noexcept(std::hash<T>()(t)))
		{
			return std::hash<T>()(t);
		}
	};

	template <typename T, typename... Ts>
	size_t hash_combine(const T& t, const Ts&... ts)
	{
		return hash_combine_generic<StdHasher>(t, ts...);
	}

	//////////////////////////////////////////////////////////////////////

	/*
	* Thomas Wang 64 bit mix hash function
	*/

	inline uint64_t twang_mix64(uint64_t key) noexcept
	{
		key = (~key) + (key << 21); // key *= (1 << 21) - 1; key -= 1;
		key = key ^ (key >> 24);
		key = key + (key << 3) + (key << 8); // key *= 1 + (1 << 3) + (1 << 8)
		key = key ^ (key >> 14);
		key = key + (key << 2) + (key << 4); // key *= 1 + (1 << 2) + (1 << 4)
		key = key ^ (key >> 28);
		key = key + (key << 31); // key *= 1 + (1 << 31)
		return key;
	}

	/*
	* Inverse of twang_mix64
	*
	* Note that twang_unmix64 is significantly slower than twang_mix64.
	*/

	inline uint64_t twang_unmix64(uint64_t key) noexcept
	{
		// See the comments in jenkins_rev_unmix32 for an explanation as to how this
		// was generated
		key *= 4611686016279904257U;
		key ^= (key >> 28) ^ (key >> 56);
		key *= 14933078535860113213U;
		key ^= (key >> 14) ^ (key >> 28) ^ (key >> 42) ^ (key >> 56);
		key *= 15244667743933553977U;
		key ^= (key >> 24) ^ (key >> 48);
		key = (key + 1) * 9223367638806167551U;
		return key;
	}

	/*
	* Thomas Wang downscaling hash function
	*/

	inline uint32_t twang_32from64(uint64_t key) noexcept
	{
		key = (~key) + (key << 18);
		key = key ^ (key >> 31);
		key = key * 21;
		key = key ^ (key >> 11);
		key = key + (key << 6);
		key = key ^ (key >> 22);
		return static_cast<uint32_t>(key);
	}

	/*
	* Robert Jenkins' reversible 32 bit mix hash function
	*/

	inline uint32_t jenkins_rev_mix32(uint32_t key) noexcept
	{
		key += (key << 12); // key *= (1 + (1 << 12))
		key ^= (key >> 22);
		key += (key << 4); // key *= (1 + (1 << 4))
		key ^= (key >> 9);
		key += (key << 10); // key *= (1 + (1 << 10))
		key ^= (key >> 2);
		// key *= (1 + (1 << 7)) * (1 + (1 << 12))
		key += (key << 7);
		key += (key << 12);
		return key;
	}

	/*
	* Inverse of jenkins_rev_mix32
	*
	* Note that jenkinks_rev_unmix32 is significantly slower than
	* jenkins_rev_mix32.
	*/

	inline uint32_t jenkins_rev_unmix32(uint32_t key) noexcept
	{
		// These are the modular multiplicative inverses (in Z_2^32) of the
		// multiplication factors in jenkins_rev_mix32, in reverse order.  They were
		// computed using the Extended Euclidean algorithm, see
		// http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
		key *= 2364026753U;

		// The inverse of a ^= (a >> n) is
		// b = a
		// for (int i = n; i < 32; i += n) {
		//   b ^= (a >> i);
		// }
		key ^= (key >> 2) ^ (key >> 4) ^ (key >> 6) ^ (key >> 8) ^ (key >> 10) ^
			(key >> 12) ^ (key >> 14) ^ (key >> 16) ^ (key >> 18) ^ (key >> 20) ^
			(key >> 22) ^ (key >> 24) ^ (key >> 26) ^ (key >> 28) ^ (key >> 30);
		key *= 3222273025U;
		key ^= (key >> 9) ^ (key >> 18) ^ (key >> 27);
		key *= 4042322161U;
		key ^= (key >> 22);
		key *= 16773121U;
		return key;
	}

	/*
	* Fowler / Noll / Vo (FNV) Hash
	*     http://www.isthe.com/chongo/tech/comp/fnv/
	*/

	const uint32_t FNV_32_HASH_START = 2166136261UL;
	const uint64_t FNV_64_HASH_START = 14695981039346656037ULL;
	const uint64_t FNVA_64_HASH_START = 14695981039346656037ULL;

	inline uint32_t fnv32(
		const char* buf,
		uint32_t hash = FNV_32_HASH_START) noexcept
	{
		// forcing signed char, since other platforms can use unsigned
		const signed char* s = reinterpret_cast<const signed char*>(buf);

		for (; *s; ++s)
		{
			hash +=
				(hash << 1) + (hash << 4) + (hash << 7) + (hash << 8) + (hash << 24);
			hash ^= *s;
		}
		return hash;
	}

	inline uint32_t fnv32_buf(
		const void* buf,
		size_t n,
		uint32_t hash = FNV_32_HASH_START) noexcept
	{
		// forcing signed char, since other platforms can use unsigned
		const signed char* char_buf = reinterpret_cast<const signed char*>(buf);

		for (size_t i = 0; i < n; ++i)
		{
			hash +=
				(hash << 1) + (hash << 4) + (hash << 7) + (hash << 8) + (hash << 24);
			hash ^= char_buf[i];
		}

		return hash;
	}

	inline uint32_t fnv32(
		const std::string& str,
		uint32_t hash = FNV_32_HASH_START) noexcept
	{
		return fnv32_buf(str.data(), str.size(), hash);
	}

	inline uint64_t fnv64(
		const char* buf,
		uint64_t hash = FNV_64_HASH_START) noexcept
	{
		// forcing signed char, since other platforms can use unsigned
		const signed char* s = reinterpret_cast<const signed char*>(buf);

		for (; *s; ++s)
		{
			hash += (hash << 1) + (hash << 4) + (hash << 5) + (hash << 7) +
				(hash << 8) + (hash << 40);
			hash ^= *s;
		}
		return hash;
	}

	inline uint64_t fnv64_buf(
		const void* buf,
		size_t n,
		uint64_t hash = FNV_64_HASH_START) noexcept
	{
		// forcing signed char, since other platforms can use unsigned
		const signed char* char_buf = reinterpret_cast<const signed char*>(buf);

		for (size_t i = 0; i < n; ++i)
		{
			hash += (hash << 1) + (hash << 4) + (hash << 5) + (hash << 7) +
				(hash << 8) + (hash << 40);
			hash ^= char_buf[i];
		}
		return hash;
	}

	inline uint64_t fnv64(
		const std::string& str,
		uint64_t hash = FNV_64_HASH_START) noexcept
	{
		return fnv64_buf(str.data(), str.size(), hash);
	}

	inline uint64_t fnva64_buf(
		const void* buf,
		size_t n,
		uint64_t hash = FNVA_64_HASH_START) noexcept
	{
		const uint8_t* char_buf = reinterpret_cast<const uint8_t*>(buf);

		for (size_t i = 0; i < n; ++i)
		{
			hash ^= char_buf[i];
			hash += (hash << 1) + (hash << 4) + (hash << 5) + (hash << 7) +
				(hash << 8) + (hash << 40);
		}
		return hash;
	}

	inline uint64_t fnva64(
		const std::string& str,
		uint64_t hash = FNVA_64_HASH_START) noexcept
	{
		return fnva64_buf(str.data(), str.size(), hash);
	}
} //namespace NFHash


