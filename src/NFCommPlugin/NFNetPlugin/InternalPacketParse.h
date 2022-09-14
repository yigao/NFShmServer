// -------------------------------------------------------------------------
//    @FileName         :    InternalPacketParse.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------
#pragma once

#include "NFIPacketParse.h"

#include <set>

class InternalPacketParse : public NFIPacketParse
{
public:
	InternalPacketParse();
	////////////////////////////////////////////////////////////////////
	virtual int DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage) override;
	virtual int EnCodeImpl(const NFDataPackage& recvPackage, NFBuffer& buffer, uint64_t nSendBusLinkId = 0) override;
};
