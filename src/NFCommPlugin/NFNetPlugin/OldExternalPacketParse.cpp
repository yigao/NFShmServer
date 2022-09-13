// -------------------------------------------------------------------------
//    @FileName         :    QiPaiNetPacketParse.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------
#include "OldExternalPacketParse.h"
#include "NFNetDefine.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

#pragma pack(push)
#pragma pack(1)

struct ExternalMsg
{
public:
	ExternalMsg() : mSZ(0), mCmdID(0), mOperateId(0)
	{
		mHead[0] = 'h';
		mHead[1] = 'e';
		mHead[2] = 'a';
		mHead[3] = 'd';
	}

	char mHead[4];
	uint32_t mSZ;
	uint16_t mCmdID;
	uint16_t mOperateId;
};

#pragma pack(pop)

OldExternalPacketParse::OldExternalPacketParse()
{
}

int OldExternalPacketParse::DeCodeImpl(const char* strData, uint32_t unLen, char*& outData, uint32_t& outLen, uint32_t& allLen, uint32_t& nMsgId, uint64_t& nSendValue, uint64_t& nSendId, uint64_t* nSendBusLinkId)
{
	if (strData == nullptr || unLen == 0) return 1;

	ExternalMsg* packHead = nullptr;

	if (unLen < static_cast<uint32_t>(sizeof(ExternalMsg)))
	{
		return 1;
	}

	packHead = (ExternalMsg*)strData; //-V519
	uint32_t msgSize = packHead->mSZ;
	uint16_t tmpMsgId = packHead->mCmdID;
	uint16_t tmpValue = packHead->mOperateId;

	if (sizeof(ExternalMsg) + msgSize >= MAX_RECV_BUFFER_SIZE) //-V560
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "net server parse data failed, msgSize:{}, msgId:{}, operateId:{}", msgSize, tmpMsgId, tmpValue);
		return -1;
	}

	if (sizeof(ExternalMsg) + msgSize > unLen)
	{
		return 1;
	}

	outData = const_cast<char*>(strData + sizeof(ExternalMsg));
	outLen = msgSize;
	nMsgId = tmpMsgId;
	nSendValue = 0;
	nSendId = 0;
	allLen = sizeof(ExternalMsg) + msgSize;
	return 0;
}

int OldExternalPacketParse::EnCodeImpl(uint32_t unMsgID, uint64_t nSendValue, uint64_t nSendId, const char* strData, uint32_t unDataLen, NFBuffer& buffer, uint64_t nSendBusLinkId)
{
	ExternalMsg packHead;
	packHead.mSZ = unDataLen;
	packHead.mCmdID = (uint16_t)unMsgID;
	packHead.mOperateId = 0;

	buffer.PushData(&packHead, sizeof(ExternalMsg));
	buffer.PushData(strData, unDataLen);

	return unDataLen + sizeof(ExternalMsg);
}

