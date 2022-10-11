// -------------------------------------------------------------------------
//    @FileName         :    InternalPacketParse.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------
#include "InternalPacketParse.h"
#include "NFNetDefine.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

#pragma pack(push)
#pragma pack(1)

//高16位：1位压缩 + 15位模块号
//低16位：16位命令号
struct InternalMsg
{
public:
	InternalMsg() : mCmdAndFlag(0), mLength(0), nParam1(0), nParam2(0), nSrcId(0), nDstId(0), ulSendBusLinkId(0)
	{
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

	uint32_t mCmdAndFlag;
    uint32_t mLength;
	uint64_t nParam1;
	uint64_t nParam2;
	uint64_t nSrcId;
	uint64_t nDstId;
	uint64_t ulSendBusLinkId; //bus message need
};

#pragma pack(pop)

InternalPacketParse::InternalPacketParse()
{
}

int InternalPacketParse::DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, NFBaseDataPackage& recvPackage)
{
	if (strData == nullptr || unLen == 0) return 1;

	InternalMsg* packHead = nullptr;

	if (unLen < static_cast<uint32_t>(sizeof(InternalMsg)))
	{
		return 1;
	}

    packHead = (InternalMsg*)strData; //-V519
    uint32_t msgSize = packHead->mLength;
    uint32_t moduleId = (uint32_t)packHead->GetModule();
    uint32_t tmpMsgId = (uint32_t)packHead->GetCmd();

    if (sizeof(InternalMsg) + msgSize >= MAX_RECV_BUFFER_SIZE) //-V560
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "net server parse data failed, msgSize:{}, moduleId:{} msgId:{}", msgSize, moduleId, tmpMsgId);
        return -1;
    }

    if (sizeof(InternalMsg) + msgSize > unLen)
    {
        return 1;
    }

    outData = const_cast<char*>(strData + sizeof(InternalMsg));
    outLen = msgSize;
    recvPackage.mModuleId = moduleId;
    recvPackage.nMsgId = tmpMsgId;
    recvPackage.nParam1 = packHead->nParam1;
    recvPackage.nParam2 = packHead->nParam2;
    recvPackage.nSrcId = packHead->nSrcId;
    recvPackage.nDstId = packHead->nDstId;
    recvPackage.nSendBusLinkId = packHead->ulSendBusLinkId;
    allLen = sizeof(InternalMsg) + msgSize;
	return 0;
}

int InternalPacketParse::EnCodeImpl(const NFDataPackage& recvPackage, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
	InternalMsg packHead;
    packHead.SetModule(recvPackage.mModuleId);
    packHead.SetCmd(recvPackage.nMsgId);
    packHead.SetLength(recvPackage.mBufferMsg.ReadableSize());
	packHead.nParam1 = recvPackage.nParam1;
	packHead.nParam2 = recvPackage.nParam2;
	packHead.nSrcId = recvPackage.nSrcId;
	packHead.nDstId = recvPackage.nDstId;
	packHead.ulSendBusLinkId = nSendBusLinkId;

	buffer.PushData(&packHead, sizeof(InternalMsg));
	buffer.PushData(recvPackage.mBufferMsg.ReadAddr(), recvPackage.mBufferMsg.ReadableSize());

	return packHead.mLength;
}