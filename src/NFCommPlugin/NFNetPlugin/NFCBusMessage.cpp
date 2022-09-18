// -------------------------------------------------------------------------
//    @FileName         :    NFCBusMessage.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCBusMessage.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
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

/**
 * @brief	发送数据
 *
 * @param pData		发送的数据, 这里的数据已经包含了数据头
 * @param unSize	数据的大小
 * @return
 */
bool NFCBusMessage::Send(uint64_t usLinkId, const char* pData, uint32_t unSize)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);
    CHECK_EXPR(pConn, false, "usLinkId:{} not find", usLinkId);

    return pConn->Send(pData, unSize);
}

/**
 * @brief	发送数据 不包含数据头
 *
 * @param pData		发送的数据,
 * @param unSize	数据的大小
 * @return
 */
bool NFCBusMessage::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);
    CHECK_EXPR(pConn, false, "usLinkId:{} not find", usLinkId);

    return pConn->Send(nModuleId, nMsgID, msg, nLen, nParam1, nParam2);
}

bool NFCBusMessage::Send(uint64_t usLinkId, NFDataPackage& package)
{
    auto pConn = m_busConnectMap.GetElement(usLinkId);
    CHECK_EXPR(pConn, false, "usLinkId:{} not find", usLinkId);

    return pConn->Send(package);
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

void NFCBusMessage::OnHandleMsgPeerThread(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, const NFDataPackage& packet)
{
    MsgFromBusInfo msgInfo;
    msgInfo.nType = type;
    msgInfo.mPacket = packet;
    msgInfo.mPacket.nSendBusLinkId = objectLinkId;
    while(!m_msgQueue.Enqueue(msgInfo)) {}
}

void NFCBusMessage::OnHandleMsgQueue()
{
    uint32_t max_times = 10000;
    while (!m_msgQueue.IsQueueEmpty() && max_times > 0)
    {
        std::vector<MsgFromBusInfo> vecMsg;
        vecMsg.resize(200);
        m_msgQueue.TryDequeueBulk(vecMsg);

        for(int i = 0; i < (int)vecMsg.size(); i++)
        {
            max_times--;
            MsgFromBusInfo& msg = vecMsg[i];
            OnHandleMsgPeer(msg.nType, msg.mPacket.nSendBusLinkId, msg.mPacket.nSendBusLinkId, msg.mPacket);
        }
    }
}

void NFCBusMessage::OnHandleMsgPeer(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, const NFDataPackage& packet)
{
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
            }

            CHECK_EXPR(pConn, , "m_busConnectMap.GetElement busId:{} == NULL", flag.mBusId);

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
            break;
        case eMsgType_DISCONNECTED:
        {
        }
            break;
        default:
            break;
    }
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
                    NFDataPackage tmpPacket;
                    tmpPacket.nSendBusLinkId = pServerData->mUnlinkId;
                    tmpPacket.mModuleId = 0;
                    tmpPacket.nMsgId = NF_SERVER_TO_SERVER_BUS_CONNECT_REQ;
                    tmpPacket.nParam1 = flag.mBusId;
                    tmpPacket.nParam2 = flag.mBusLength;

                    OnHandleMsgPeer(eMsgType_CONNECTED, pServerData->mUnlinkId, pServerData->mUnlinkId, tmpPacket);
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

