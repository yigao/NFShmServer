// -------------------------------------------------------------------------
//    @FileName         :    NFIPacketParse.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------

#include "NFIPacketParse.h"
#include "InternalPacketParse.h"
#include "ExternalPacketParse.h"
#include "OldExternalPacketParse.h"

std::vector<NFIPacketParse*> NFIPacketParse::m_pPacketParse = { CreatePacketParse(PACKET_PARSE_TYPE_INTERNAL), CreatePacketParse(PACKET_PARSE_TYPE_EXTERNAL), CreatePacketParse(PACKET_PARSE_TYPE_OLD_EXTERNAL) };

void NFIPacketParse::DeletePacketParse(NFIPacketParse* pPacketParse)
{
	delete pPacketParse;
}

NFIPacketParse* NFIPacketParse::CreatePacketParse(int parseType)
{
	if (parseType == PACKET_PARSE_TYPE_INTERNAL)
	{
		return NF_NEW InternalPacketParse();
	}
	else if (parseType == PACKET_PARSE_TYPE_EXTERNAL)
	{
		return NF_NEW ExternalPacketParse();
	}
	else if (parseType == PACKET_PARSE_TYPE_OLD_EXTERNAL)
	{
		return NF_NEW OldExternalPacketParse();
	}
	else
	{
		return NF_NEW InternalPacketParse();
	}
}

int NFIPacketParse::DeCode(uint32_t packetType, const char* strData, const uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, uint32_t& nMsgId, uint64_t& nSendValue, uint64_t& nSendId, uint64_t* nSendBusLinkId)
{
	if (packetType < 0 || packetType >= m_pPacketParse.size())
	{
		return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->DeCodeImpl(strData, unLen, outData, outLen, allLen, nMsgId, nSendValue, nSendId, nSendBusLinkId);
	}
	return m_pPacketParse[packetType]->DeCodeImpl(strData, unLen, outData, outLen, allLen, nMsgId, nSendValue, nSendId, nSendBusLinkId);
}

int NFIPacketParse::EnCode(uint32_t packetType, const uint32_t unMsgID, uint64_t nSendValue, uint64_t nSendId, const char* strData, const uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
	if (packetType < 0 || packetType >= m_pPacketParse.size())
	{
		return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->EnCodeImpl(unMsgID, nSendValue, nSendId, strData, unDataLen, buffer, nSendBusLinkId);
	}
	return m_pPacketParse[packetType]->EnCodeImpl(unMsgID, nSendValue, nSendId, strData, unDataLen, buffer, nSendBusLinkId);
}
