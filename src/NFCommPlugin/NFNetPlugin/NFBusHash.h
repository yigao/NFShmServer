// -------------------------------------------------------------------------
//    @FileName         :    NFBusHash.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFHash.hpp"

template <bool is_hash64>
struct hash_factor;

template <>
struct hash_factor<false> {
	static uint32_t hash(uint32_t seed, const void *s, size_t l) {
		return NFHash::murmur_hash3_x86_32(s, static_cast<int>(l), seed);
		// CRC算法性能太差，包长度也不太可能超过2GB
		// return atbus::detail::crc32(crc, static_cast<const unsigned char *>(s), l);
	}
};

template <>
struct hash_factor<true> {
	static uint64_t hash(uint64_t seed, const void *s, size_t l) {
		return NFHash::murmur_hash3_x86_32(s, static_cast<int>(l), static_cast<uint32_t>(seed));
		// CRC算法性能太差，包长度也不太可能超过2GB
		// return atbus::detail::crc64(crc, static_cast<const unsigned char *>(s), l);
	}
};
