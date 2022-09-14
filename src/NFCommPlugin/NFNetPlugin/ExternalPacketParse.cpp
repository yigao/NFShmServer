// -------------------------------------------------------------------------
//    @FileName         :    QiPaiNetPacketParse.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------
#include "ExternalPacketParse.h"
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

struct ExternalMsg
{
public:
    //高16位：1位压缩 + 15位模块号
    //低16位：16位命令号
	ExternalMsg() : mCmdAndFlag(0), mLength(0)
	{
	}

	uint32_t mCmdAndFlag;
    uint32_t mLength;

    void Reset()
    {
        mCmdAndFlag = 0;
        mLength = 0;
    }

    void SetLength(uint32_t len)
    {
        mLength = len;
    }

    uint32_t GetLength() const
    {
        return mLength;
    }

    void SetModule(uint16_t module)
    {
        uint16_t hiWord = MMO_HIWORD(mCmdAndFlag);
        hiWord = module | (hiWord & (1 << s_compressBitPos));
        mCmdAndFlag = MMO_MAKELONG(MMO_LOWORD(mCmdAndFlag), hiWord);
    }

    void SetCmd(uint16_t cmd)
    {
        mCmdAndFlag = MMO_MAKELONG(cmd, MMO_HIWORD(mCmdAndFlag));
    }

    uint16_t GetModule() const
    {
        uint16_t hiWord = MMO_HIWORD(mCmdAndFlag);
        return (hiWord & (~(1 << s_compressBitPos)));
    }

    uint16_t GetCmd() const
    {
        return MMO_LOWORD(mCmdAndFlag);
    }

    void SetCompress()
    {
        uint16_t hiWord = MMO_HIWORD(mCmdAndFlag);
        hiWord |= (1 << s_compressBitPos);
        mCmdAndFlag = MMO_MAKELONG(MMO_LOWORD(mCmdAndFlag), hiWord);
    }

    void ClearCompress()
    {
        uint16_t hiWord = MMO_HIWORD(mCmdAndFlag);
        hiWord &= ~(1 << s_compressBitPos);
        mCmdAndFlag = MMO_MAKELONG(MMO_LOWORD(mCmdAndFlag), hiWord);
    }

    bool IsCompressed() const
    {
        uint16_t hiWord = MMO_HIWORD(mCmdAndFlag);
        return 0 != (hiWord & (1 << s_compressBitPos));
    }
};

#pragma pack(pop)

ExternalPacketParse::ExternalPacketParse()
{
}

int ExternalPacketParse::DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFDataPackage& recvPackage)
{
	if (strData == nullptr || unLen == 0) return 1;

	ExternalMsg* packHead = nullptr;

	if (unLen < static_cast<uint32_t>(sizeof(ExternalMsg)))
	{
		return 1;
	}

	packHead = (ExternalMsg*)strData; //-V519
	uint32_t msgSize = packHead->mLength;
	bool isCompressed = packHead->IsCompressed();
	uint32_t moduleId = (uint32_t)packHead->GetModule();
    uint32_t tmpMsgId = (uint32_t)packHead->GetCmd();

	if (sizeof(ExternalMsg) + msgSize >= MAX_RECV_BUFFER_SIZE) //-V560
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "net server parse data failed, msgSize:{}, moduleId:{} msgId:{}", msgSize, moduleId, tmpMsgId);
		return -1;
	}

	if (sizeof(ExternalMsg) + msgSize > unLen)
	{
		return 1;
	}

    outData = const_cast<char*>(strData + sizeof(ExternalMsg));
    outLen = msgSize;
    recvPackage.mModuleId = moduleId;
    recvPackage.nMsgId = tmpMsgId;
    recvPackage.nSendValue = 0;
    recvPackage.nSendId = 0;
    recvPackage.bSecurity = isCompressed;
    allLen = sizeof(ExternalMsg) + msgSize;
	return 0;
}

int ExternalPacketParse::EnCodeImpl(const uint32_t unMsgID, uint64_t nSendValue, uint64_t nSendId, const char* strData, const uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
	ExternalMsg packHead;
	packHead.mLength = unDataLen;
	packHead.mCmdAndFlag = unMsgID;

	buffer.PushData(&packHead, sizeof(ExternalMsg));
	buffer.PushData(strData, unDataLen);

	return unDataLen + sizeof(ExternalMsg);
}

// 使用 lzf 算法 压缩、解压
int ExternalPacketParse::CompressImpl(const char* inBuffer, int inLen, void *outBuffer, unsigned int outSize)
{
    return lzf_compress(inBuffer, inLen, outBuffer, outSize);
}

int ExternalPacketParse::DecompressImpl(const char* inBuffer, int inLen, void *outBuffer, int outSize)
{
    return lzf_decompress(inBuffer, inLen, outBuffer, outSize);
}