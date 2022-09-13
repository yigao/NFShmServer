// -------------------------------------------------------------------------
//    @FileName         :    NFCRC32.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

class _NFExport NFCRC32
{
public:
	// @brief
	// @param d   Source data buffer, If length is length than dwLength, result is unknown.
	// @param len The size of d.
	// @return crc value.
	static uint32_t Sum(const void* d, size_t len);

	static uint32_t Sum(const string& s)
	{
		return Sum(s.data(), s.size());
	}

private:
	// Initialize the CRC table with 256 elements.
	static void InitTable(uint32_t* table);
	static uint32_t Reflect(uint32_t ref, char ch);
};

