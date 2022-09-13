// -------------------------------------------------------------------------
//    @FileName         :    NFCRC16.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

// CRC-16/CCITT
class _NFExport NFCRC16
{
public:
	static uint16_t Sum(const void* data, size_t len);

	static uint16_t Sum(const std::string& s)
	{
		return Sum(s.data(), s.size());
	}
};

