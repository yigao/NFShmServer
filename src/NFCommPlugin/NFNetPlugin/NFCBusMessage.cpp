// -------------------------------------------------------------------------
//    @FileName         :    NFCBusMessage.cpp
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCBusMessage.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFNetInfoPool.h"
#include "NFIPacketParse.h"
#include "NFCBusServer.h"
#include "NFCBusClient.h"
#include <string.h>
#include <sstream>

NFCBusMessage::NFCBusMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType):NFINetMessage(p, serverType)
{
    m_bindConnect = NULL;
}

NFCBusMessage::~NFCBusMessage()
{

}

bool NFCBusMessage::Execute()
{
    if (m_bindConnect)
    {
        m_bindConnect->Execute();
    }
    OnHandleMsgQueue();
	return true;
}

bool NFCBusMessage::Shut()
{
    auto pConn = m_busConnectMap.First();
    while(pConn)
    {
        pConn->Shut();
        pConn = m_busConnectMap.Next();
    }

    return true;
}

bool NFCBusMessage::Finalize()
{
    auto pConn = m_busConnectMap.First();
    while(pConn)
    {
        pConn->Finalize();
        pConn = m_busConnectMap.Next();
    }
    m_bindConnect = NULL;
    m_busConnectMap.ClearAll();
    return true;
}

bool NFCBusMessage::ReadyExecute()
{
    return true;
}

/**
* @brief	初始化
*
* @return 是否成功
*/
int64_t NFCBusMessage::BindServer(const NFMessageFlag& flag)
{
    CHECK_EXPR(m_bindConnect == NULL, -1, "BindServer Failed!");
    NF_SHARE_PTR<NFCBusServer> pServer = NF_SHARE_PTR<NFCBusServer>(NF_NEW NFCBusServer(m_pObjPluginManager, mServerType, flag));
    NF_ASSERT(pServer);

    if (mServerType == NF_ST_ROUTE_AGENT_SERVER || mServerType == NF_ST_ROUTE_SERVER || mServerType == NF_ST_PROXY_AGENT_SERVER)
    {
        pServer->SetMsgPeerCallback(std::bind(&NFCBusMessage::OnHandleMsgPeerThread, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                              std::placeholders::_4));
    }
    else
    {
        pServer->SetMsgPeerCallback(std::bind(&NFCBusMessage::OnHandleMsgPeer, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                              std::placeholders::_4));
    }


    if (pServer->Init())
    {
        m_busConnectMap.AddElement(pServer->GetLinkId(), pServer);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFCBusServer Init Failed!");
        return -1;
    }

    m_bindConnect = pServer;
    return pServer->GetLinkId();
}

int64_t NFCBusMessage::ConnectServer(const NFMessageFlag& flag)
{
    CHECK_EXPR(m_bindConnect, -1, "ConnectServer Failed, muset bindserver");

    NF_SHARE_PTR<NFCBusClient> pConn = NF_SHARE_PTR<NFCBusClient>(NF_NEW NFCBusClient(m_pObjPluginManager, mServerType, flag, m_bindConnect->GetBindFlag()));
    NF_ASSERT(pConn);

    if (pConn->Init())
    {
        m_busConnectMap.AddElement(pConn->GetLinkId(), pConn);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFCBusClient Init Failed")
        return -1;
    }

    return pConn->GetLinkId();
}

bool NFCBusMessage::Send(uint64_t usLinkId, NFDataPackage* pPackage)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);

    if (pConn)
    {
        return pConn->Send(pPackage);
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "usLinkId:{} not find", usLinkId);
    pPackage->Clear();
    NFNetInfoPool<NFDataPackage>::Instance()->Free(pPackage, pPackage->mBufferMsg.Capacity());
    return false;
}

/**
 * @brief 获得连接IP
 *
 * @param  usLinkId
 * @return std::string
 */
std::string NFCBusMessage::GetLinkIp(uint64_t usLinkId)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);
    CHECK_EXPR(pConn, "", "usLinkId:{} not find", usLinkId);

    return pConn->GetLinkIp();
}

uint32_t NFCBusMessage::GetPort(uint64_t usLinkId)
{
    return 0;
}

/**
* @brief 关闭连接
*
* @param  usLinkId
* @return
*/
void NFCBusMessage::CloseLinkId(uint64_t usLinkId)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);
    CHECK_EXPR(pConn, , "usLinkId:{} not find", usLinkId);

    return pConn->CloseLinkId();
}

void NFCBusMessage::OnHandleMsgPeerThread(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, MsgFromBusInfo* packet)
{
    packet->nType = type;
    while(!m_msgQueue.Enqueue(packet)) {}
}

void NFCBusMessage::OnHandleMsgQueue()
{
    uint32_t max_times = 10000;
    while (!m_msgQueue.IsQueueEmpty() && max_times > 0)
    {
        std::vector<MsgFromBusInfo*> vecMsg;
        vecMsg.resize(200);
        m_msgQueue.TryDequeueBulk(vecMsg);

        for(int i = 0; i < (int)vecMsg.size(); i++)
        {
            max_times--;
            MsgFromBusInfo* pMsg = vecMsg[i];
            CHECK_EXPR_CONTINUE(pMsg, "pMsg == NULL");

            OnHandleMsgPeer(pMsg->nType, pMsg->mPacket.nSendBusLinkId, pMsg->mPacket.nSendBusLinkId, pMsg);
        }
    }
}

void NFCBusMessage::OnHandleMsgPeer(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, MsgFromBusInfo* pMsg)
{
    CHECK_EXPR_NOT_RET(pMsg, "pMsg == NULL");

    NFDataPackage& packet = pMsg->mPacket;
    if (!(packet.mModuleId == 0 && (packet.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT
                                    || packet.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT_RSP || packet.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT || packet.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT_RSP)))
    {
        NFLogTrace(NF_LOG_RECV_MSG,0,"recv msg:{} ", packet.ToString());
    }

    uint32_t fromBusId = (key_t)GetServerIndexFromUnlinkId(objectLinkId);
    uint64_t fromLinkId = GetUnLinkId(NF_IS_BUS, mServerType, fromBusId);
    switch (type)
    {
        case eMsgType_RECIVEDATA:
        {
            if (mRecvCB)
            {
                auto pConn = m_busConnectMap.GetElement(fromLinkId);
                if (pConn)
                {
                    mRecvCB(m_bindConnect->GetLinkId(), pConn->GetLinkId(), packet);
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "BusMessage OnHandleMsgPeer Error, busId:{} can't find", NFServerIDUtil::GetBusNameFromBusID(fromBusId));
                }
            }
        }
            break;
        case eMsgType_CONNECTED:
        {
            NFMessageFlag flag;
            flag.mBusId = packet.nParam1;
            flag.mBusLength = packet.nParam1;
            flag.bActivityConnect = false;
            if ((uint64_t)fromBusId != flag.mBusId)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "BusMessage fromBusId:{} != busId:{}", fromBusId, flag.mBusId);
            }

            auto pConn = m_busConnectMap.GetElement(fromLinkId);
            if (pConn == NULL)
            {
                ConnectServer(flag);
                pConn = m_busConnectMap.GetElement(fromLinkId);
                CHECK_EXPR_MSG(pConn, "m_busConnectMap.GetElement busId:{} == NULL", flag.mBusId);
            }

            if (pConn)
            {
                if (packet.mModuleId == 0 && packet.nMsgId == NF_SERVER_TO_SERVER_BUS_CONNECT_REQ)
                {
                    pConn->SendBusConnectRspMsg(m_bindConnect->GetBusId(), m_bindConnect->GetBusLength());
                    if (mEventCB)
                    {
                        mEventCB(type, m_bindConnect->GetLinkId(), pConn->GetLinkId());
                    }
                }
                else
                {
                    if (mEventCB)
                    {
                        mEventCB(type, pConn->GetLinkId(),  pConn->GetLinkId());
                    }
                }
            }
        }
            break;
        case eMsgType_DISCONNECTED:
        {
        }
            break;
        default:
            break;
    }

    pMsg->Clear();
    NFNetInfoPool<MsgFromBusInfo>::Instance()->Free(pMsg, pMsg->mPacket.mBufferMsg.Capacity());
}

int NFCBusMessage::ResumeConnect()
{
    CHECK_NULL(m_bindConnect);
    CHECK_NULL(m_bindConnect->GetShmRecord());

    NFShmChannelHead *head = (NFShmChannelHead *)m_bindConnect->GetShmRecord()->m_nBuffer;
    CHECK_NULL(head);
    CHECK_EXPR(head->m_nShmAddr.mDstLinkId == m_bindConnect->GetShmRecord()->m_nUnLinkId, -1, "head->m_nShmAddr.mDstLinkId == m_nShmBindRecord.m_nUnLinkId");

    for(size_t i = 0; i < ARRAYSIZE(head->m_nShmAddr.mSrcLinkId); i++)
    {
        if (head->m_nShmAddr.mSrcLinkId[i] > 0)
        {
            uint64_t linkId = head->m_nShmAddr.mSrcLinkId[i];
            NFMessageFlag flag;
            flag.mBusId = GetServerIndexFromUnlinkId(linkId);
            flag.mBusLength = head->m_nShmAddr.mSrcBusLength[i];
            flag.mPacketParseType = head->m_nShmAddr.mSrcParseType[i];
            bool bActivityConnect = head->m_nShmAddr.bActiveConnect[i];
            flag.bActivityConnect = !bActivityConnect;
            uint32_t serverType = GetServerTypeFromUnlinkId(linkId);

            NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId((NF_SERVER_TYPES)mServerType, flag.mBusId);
            if (!pServerData) {
                proto_ff::ServerInfoReport xData;
                xData.set_bus_id(flag.mBusId);
                xData.set_bus_length(flag.mBusLength);
                xData.set_link_mode("bus");
                xData.set_server_type(serverType);
                std::string busName = NFServerIDUtil::GetBusNameFromBusID(flag.mBusId);
                std::string url = NF_FORMAT("bus://{}:{}", busName, flag.mBusLength);
                xData.set_url(url);
                pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId((NF_SERVER_TYPES)mServerType, flag.mBusId, (NF_SERVER_TYPES)serverType, xData);

                pServerData->mUnlinkId = GetUnLinkId(NF_IS_BUS, mServerType, flag.mBusId);
                FindModule<NFIMessageModule>()->CreateLinkToServer((NF_SERVER_TYPES)mServerType, flag.mBusId, pServerData->mUnlinkId);
                if (bActivityConnect)
                {
                    MsgFromBusInfo* pPacket = NFNetInfoPool<MsgFromBusInfo>::Instance()->Alloc(0);
                    CHECK_EXPR_ASSERT(pPacket, -1, "pPacket == NULL, NFNetInfoPool<MsgFromBusInfo>::Instance()->Alloc(0) Failed");

                    pPacket->mPacket.nSendBusLinkId = pServerData->mUnlinkId;
                    pPacket->mPacket.mModuleId = 0;
                    pPacket->mPacket.nMsgId = NF_SERVER_TO_SERVER_BUS_CONNECT_REQ;
                    pPacket->mPacket.nParam1 = flag.mBusId;
                    pPacket->mPacket.nParam2 = flag.mBusLength;

                    OnHandleMsgPeer(eMsgType_CONNECTED, pServerData->mUnlinkId, pServerData->mUnlinkId, pPacket);
                }
                else
                {
                    uint64_t connectLinkId = ConnectServer(flag);
                    if (connectLinkId != pServerData->mUnlinkId)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "ReConnect Server Error, connectLinkId:{} != pServerData->mUnlinkId:{}", connectLinkId, pServerData->mUnlinkId);
                    }
                }
            }
        }
    }

    return 0;
}

