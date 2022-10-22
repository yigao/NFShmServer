// -------------------------------------------------------------------------
//    @FileName         :    NFIPacketParse.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
	virtual int DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage) = 0;
	virtual int EnCodeImpl(const NFDataPackage& recvPackage, const char* strData, uint32_t unLen, NFBuffer& buffer, uint64_t nSendBusLinkId = 0) = 0;
	/////////////////////////////////////////////////////////////
	static int DeCode(uint32_t packetType, const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage);
    static int EnCode(uint32_t packetType, const NFDataPackage& recvPackage, const char* strData, uint32_t unLen, NFBuffer& buffer, uint64_t nSendBusLinkId = 0);

    // 使用 lzf 算法 压缩、解压
    virtual int CompressImpl(const char* inBuffer, int inLen, void *outBuffer, unsigned int outSize) { return -1; }
    virtual int DecompressImpl(const char* inBuffer, int inLen, void *outBuffer, int outSize) { return -1; }

    // 使用 lzf 算法 压缩、解压
    static int Compress(uint32_t packetType, const char* inBuffer, int inLen, void *outBuffer, unsigned int outSize);
    static int Decompress(uint32_t packetType, const char* inBuffer, int inLen, void *outBuffer, int outSize);

	////////////////////////////////////////////////////////////
	static NFIPacketParse* CreatePacketParse(int parseType = 0);
	static void DeletePacketParse(NFIPacketParse* pPacketParse);
	static void ReleasePacketParse();
private:
	static std::vector<NFIPacketParse*> m_pPacketParse;
};
