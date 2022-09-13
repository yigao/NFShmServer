// -------------------------------------------------------------------------
//    @FileName         :    QiPaiNetPacketParse.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------
#pragma once

#include "NFIPacketParse.h"

#include <set>

class ExternalPacketParse : public NFIPacketParse
{
public:
	ExternalPacketParse();
	////////////////////////////////////////////////////////////////////
	virtual int DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, uint32_t& nMsgId, uint64_t& nSendValue, uint64_t& nSendId, uint64_t* nSendBusLinkId = NULL) override;
	virtual int EnCodeImpl(uint32_t unMsgID, uint64_t nSendValue, uint64_t nSendId, const char* strData, uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId = 0) override;
};
