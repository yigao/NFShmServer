// -------------------------------------------------------------------------
//    @FileName         :    NFCBusServer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCBusServer.cpp
//
// -------------------------------------------------------------------------


#include "NFCBusServer.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFIPacketParse.h"
#include "NFComm/NFPluginModule/NFNetInfoPool.h"
#include <string.h>
#include <sstream>
#include <NFComm/NFPluginModule/NFCheck.h>

NFCBusServer::~NFCBusServer()
{

}

bool NFCBusServer::Execute()
{
    if (!m_eventLoop)
    {
        ProcessMsgLogicThread();
    }
    return true;
}

bool NFCBusServer::Init()
{
    if (mServerType == NF_ST_ROUTE_AGENT_SERVER || mServerType == NF_ST_ROUTE_SERVER || mServerType == NF_ST_PROXY_AGENT_SERVER)
    {
        m_eventLoop = NF_NEW evpp::EventLoopThread();
        m_eventLoop->Start(true);
    }

    int64_t linkId = BindServer(mFlag);
    if (linkId <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "BindServer Failed!");
        return false;
    }

    if (m_eventLoop)
    {
        m_eventLoop->loop()->RunEvery(evpp::Duration((int64_t)100000), std::bind(&NFCBusServer::ProcessMsgLogicThread, this ));
    }

    return true;
}

bool NFCBusServer::Shut()
{
    m_busMsgPeerCb = NULL;
    if (m_eventLoop)
    {
        while(m_eventLoop->IsRunning())
        {
            m_eventLoop->Stop(true);
        }
    }

    return true;
}

bool NFCBusServer::Finalize()
{
    if (m_eventLoop)
    {
        NF_SAFE_DELETE(m_eventLoop);
    }
    return true;
}

/**
* @brief	初始化
*
* @return 是否成功
*/
int64_t NFCBusServer::BindServer(const NFMessageFlag& flag)
{
    if (flag.mBusId <= 0 || flag.mBusLength <= 4096)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "busid:{} busLength:{} error!", flag.mBusId, flag.mBusLength);
        return -1;
    }

    int ret = AttachShm((key_t)flag.mBusId, (size_t)flag.mBusLength, NULL, NULL);
    if (ret < 0)
    {
        ret = InitShm((key_t)flag.mBusId, (size_t)flag.mBusLength, NULL, NULL);
    }

    if (ret < 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bus init failed:{} ", ret);
        return ret;
    }

    NFShmRecordType * pShmRecord = GetShmRecord();
    if (pShmRecord == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetShmRecord failed, busid:{} ", flag.mBusId);
        return -1;
    }

    pShmRecord->m_nOwner = true;
    pShmRecord->m_nBusId = flag.mBusId;
    pShmRecord->m_nBusLenth = flag.mBusLength;
    pShmRecord->mPacketParseType = flag.mPacketParseType;
    pShmRecord->m_nUnLinkId = GetUnLinkId(NF_IS_BUS, mServerType, flag.mBusId);
    m_bindFlag = flag;
    m_bindFlag.mLinkId = pShmRecord->m_nUnLinkId;
    SetLinkId(pShmRecord->m_nUnLinkId);
    SetConnectionType(NF_CONNECTION_TYPE_TCP_SERVER);

    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    if (head->m_nShmAddr.mDstLinkId == 0)
    {
        head->m_nShmAddr.mDstLinkId = pShmRecord->m_nUnLinkId;
    }
    else
    {
        if (head->m_nShmAddr.mDstLinkId != pShmRecord->m_nUnLinkId)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "shm dst linkId:{} != now linkId:{} ", head->m_nShmAddr.mDstLinkId, pShmRecord->m_nUnLinkId);
            return -1;
        }
    }

    return pShmRecord->m_nUnLinkId;
}

/**
 * @brief 主线程处理消息队列
 */
void NFCBusServer::ProcessMsgLogicThread()
{
    size_t max_times = 10000;

    NFShmRecordType* pShmRecord = GetShmRecord();
    if (pShmRecord->m_nOwner)
    {
        NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
        NFShmChannel *pChannel = &head->m_nShmChannel;
        size_t left_times = max_times;
        mxBuffer.Clear();
        while(left_times-- > 0)
        {
            size_t recv_len = 0;
            int ret = ShmRecv(pChannel, mxBuffer.WriteAddr(), mxBuffer.WritableSize(), &recv_len);

            if (ret == EN_NFBUS_ERR_NO_DATA) {
                break;
            }

            mxBuffer.Produce(recv_len);

            // 回调收到数据事件
            if (ret < 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Shm Recv Error:{}", ret)
                break;
            }
            else
            {
                while (true)
                {
                    char* outData = nullptr;
                    uint32_t outLen = 0;
                    uint32_t allLen = 0;
                    NFBaseDataPackage dataPacket;
                    int ret = NFIPacketParse::DeCode(pShmRecord->mPacketParseType, mxBuffer.ReadAddr(), mxBuffer.ReadableSize(), outData, outLen, allLen, dataPacket);
                    if (ret < 0)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "nfbus parse data failed!");
                        mxBuffer.Clear();
                        break;
                    }
                    else if (ret > 0)
                    {
                        break;
                    }
                    else
                    {
                        mxBuffer.Consume(allLen);

                        MsgFromBusInfo* pPacket = NFNetInfoPool<MsgFromBusInfo>::Instance()->Alloc(outLen);
                        CHECK_EXPR_ASSERT_NOT_RET(pPacket, "pPacket == NULL, NFNetInfoPool<MsgFromBusInfo>::Instance()->Alloc(outLen:{}) Failed", outLen);

                        pPacket->mPacket.Copy(dataPacket);
                        pPacket->mPacket.mBufferMsg.PushData(outData, outLen);

                        if (pPacket->mPacket.mModuleId == 0 && pPacket->mPacket.nMsgId == NF_SERVER_TO_SERVER_BUS_CONNECT_REQ)
                        {
                            m_busMsgPeerCb(eMsgType_CONNECTED, pPacket->mPacket.nSendBusLinkId, pPacket->mPacket.nSendBusLinkId, pPacket);
                        }
                        else if (pPacket->mPacket.mModuleId == 0 && pPacket->mPacket.nMsgId == NF_SERVER_TO_SERVER_BUS_CONNECT_RSP)
                        {
                            m_busMsgPeerCb(eMsgType_CONNECTED, pPacket->mPacket.nSendBusLinkId, pPacket->mPacket.nSendBusLinkId, pPacket);
                        }
                        else
                        {
                            m_busMsgPeerCb(eMsgType_RECIVEDATA, pPacket->mPacket.nSendBusLinkId, pPacket->mPacket.nSendBusLinkId, pPacket);
                        }

                        continue;
                    }
                }
            }
        }
    }
}

bool NFCBusServer::Send(const char *pData, uint32_t unSize)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Bus Server Can't Send Data.............");
    return false;
}

bool NFCBusServer::Send(uint32_t nModuleId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Bus Server Can't Send Data............., nMsgID:{} nLen:{} nParam1:{} nParam2:{}", nSendValue, nSendId);
    return false;
}

bool NFCBusServer::Send(NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Bus Server Can't Send Data............., packet:{}", packet.ToString());
    return false;
}


