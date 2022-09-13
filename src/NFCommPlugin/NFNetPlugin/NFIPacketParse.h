// -------------------------------------------------------------------------
//    @FileName         :    NFIPacketParse.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include <stdint.h>
#include <string>
#include "NFComm/NFCore/NFBuffer.h"
#include "NFNetDefine.h"
#include <vector>
#include "NFComm/NFPluginModule/NFServerDefine.h"

class NFIPacketParse
{
public:
	virtual ~NFIPacketParse()
	{
	}

	//////////////////////////////////////////////////////////////
	virtual int DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, uint32_t& nMsgId, uint64_t& nSendValue, uint64_t& nSendId, uint64_t* nSendBusLinkId = NULL) = 0;
	virtual int EnCodeImpl(uint32_t unMsgID,uint64_t nSendValue, uint64_t nSendId, const char* strData, uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId = 0) = 0;
	/////////////////////////////////////////////////////////////
	static int DeCode(uint32_t packetType, const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, uint32_t& nMsgId, uint64_t& nSendValue, uint64_t& nSendId, uint64_t* nSendBusLinkId = NULL);
	static int EnCode(uint32_t packetType, uint32_t unMsgID, uint64_t nSendValue, uint64_t nSendId, const char* strData, uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId = 0);

	////////////////////////////////////////////////////////////
	static NFIPacketParse* CreatePacketParse(int parseType = 0);
	static void DeletePacketParse(NFIPacketParse* pPacketParse);
private:
	static std::vector<NFIPacketParse*> m_pPacketParse;
};
