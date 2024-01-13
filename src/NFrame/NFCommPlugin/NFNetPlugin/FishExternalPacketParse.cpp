//
// Created by gaoyi on 23-7-16.
//

#include "FishExternalPacketParse.h"

#include "NFNetDefine.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#ifdef __cplusplus
extern "C"
{
#include "lzf/lzf.h"
}
#else
#include "lzf/lzf.h"
#endif

#pragma pack(push)
#pragma pack(1)

struct FishExternalMsg
{
public:
    FishExternalMsg() : mSZ(0), mCmdID(0)
    {
        mHead[0] = 'h';
        mHead[1] = 'e';
        mHead[2] = 'a';
        mHead[3] = 'd';
    }

    char mHead[4];
    uint32_t mSZ;
    uint32_t mCmdID;
};

#pragma pack(pop)

FishExternalPacketParse::FishExternalPacketParse()
{
}

int FishExternalPacketParse::DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage)
{
    if (strData == nullptr || unLen == 0) return 1;

    FishExternalMsg* packHead = nullptr;

    if (unLen < static_cast<uint32_t>(sizeof(FishExternalMsg)))
    {
        return 1;
    }

    packHead = (FishExternalMsg*)strData; //-V519
    uint32_t msgSize = packHead->mSZ;
    uint32_t tmpMsgId = packHead->mCmdID;

    if (sizeof(FishExternalMsg) + msgSize >= MAX_RECV_BUFFER_SIZE) //-V560
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "net server parse data failed, msgSize:{}, msgId:{}", msgSize, tmpMsgId);
        return -1;
    }

    if (sizeof(FishExternalMsg) + msgSize > unLen)
    {
        return 1;
    }

    outData = const_cast<char*>(strData + sizeof(FishExternalMsg));
    outLen = msgSize;
    recvPackage.mModuleId = 1;
    recvPackage.nMsgId = tmpMsgId;
    recvPackage.nParam1 = 0;
    recvPackage.nParam2 = 0;
    recvPackage.bCompress = false;
    allLen = sizeof(FishExternalMsg) + msgSize;
    return 0;;
}

int FishExternalPacketParse::EnCodeImpl(const NFDataPackage& recvPackage, const char* strData, uint32_t unLen, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
    FishExternalMsg packHead;
    packHead.mSZ = unLen;
    packHead.mCmdID = recvPackage.nMsgId;

    buffer.PushData(&packHead, sizeof(FishExternalMsg));
    buffer.PushData(strData, unLen);

    return unLen + sizeof(FishExternalMsg);
}

// 使用 lzf 算法 压缩、解压
int FishExternalPacketParse::CompressImpl(const char* inBuffer, int inLen, void *outBuffer, unsigned int outSize)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
    return lzf_compress(inBuffer, inLen, outBuffer, outSize);
#else
    return 0;
#endif
}

int FishExternalPacketParse::DecompressImpl(const char* inBuffer, int inLen, void *outBuffer, int outSize)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
    return lzf_decompress(inBuffer, inLen, outBuffer, outSize);
#else
    return 0;
#endif
}
