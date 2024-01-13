// -------------------------------------------------------------------------
//    @FileName         :    NFIPacketParse.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------

#include "NFIPacketParse.h"
#include "InternalPacketParse.h"
#include "ExternalPacketParse.h"
#include "FishExternalPacketParse.h"

std::vector<NFIPacketParse*> NFIPacketParse::m_pPacketParse = { CreatePacketParse(PACKET_PARSE_TYPE_INTERNAL), CreatePacketParse(PACKET_PARSE_TYPE_EXTERNAL), CreatePacketParse(PACKET_PARSE_TYPE_FISH_EXTERNAL) };

void NFIPacketParse::DeletePacketParse(NFIPacketParse* pPacketParse)
{
    NF_SAFE_DELETE(pPacketParse);
}

void NFIPacketParse::ReleasePacketParse()
{
    for(int i = 0; i < (int)m_pPacketParse.size(); i++)
    {
        DeletePacketParse(m_pPacketParse[i]);
    }
    m_pPacketParse.clear();
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
    else if (parseType == PACKET_PARSE_TYPE_FISH_EXTERNAL)
    {
        return NF_NEW FishExternalPacketParse();
    }
	else
	{
        return NF_NEW InternalPacketParse();
	}
}

int NFIPacketParse::DeCode(uint32_t packetType, const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage)
{
	if (packetType >= m_pPacketParse.size())
	{
		return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->DeCodeImpl(strData, unLen, outData, outLen, allLen, recvPackage);
	}
	return m_pPacketParse[packetType]->DeCodeImpl(strData, unLen, outData, outLen, allLen, recvPackage);
}

int NFIPacketParse::EnCode(uint32_t packetType, const NFDataPackage& recvPackage, const char* strData, uint32_t unLen, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
	if (packetType >= m_pPacketParse.size())
	{
		return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->EnCodeImpl(recvPackage, strData, unLen, buffer, nSendBusLinkId);
	}
	return m_pPacketParse[packetType]->EnCodeImpl(recvPackage, strData, unLen, buffer, nSendBusLinkId);
}

// 使用 lzf 算法 压缩、解压
int NFIPacketParse::Compress(uint32_t packetType, const char* inBuffer, int inLen, void *outBuffer, unsigned int outSize)
{
    if (packetType >= (uint32_t)m_pPacketParse.size())
    {
        return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->CompressImpl(inBuffer, inLen, outBuffer, outSize);
    }
    return m_pPacketParse[packetType]->CompressImpl(inBuffer, inLen, outBuffer, outSize);
}

int NFIPacketParse::Decompress(uint32_t packetType, const char* inBuffer, int inLen, void *outBuffer, int outSize)
{
    if (packetType >= m_pPacketParse.size())
    {
        return m_pPacketParse[PACKET_PARSE_TYPE_INTERNAL]->DecompressImpl(inBuffer, inLen, outBuffer, outSize);
    }
    return m_pPacketParse[packetType]->DecompressImpl(inBuffer, inLen, outBuffer, outSize);
}
