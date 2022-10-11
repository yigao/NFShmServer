// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFTime.h>
#include <common_msg.pb.h>
#include <server_to_client.pb.h>
#include <client_to_server.pb.h>
#include <ClientToServer.pb.h>
#include <ServerToClient.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include "NFProxyClientModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"

NFCProxyClientModule::NFCProxyClientModule(NFIPluginManager *p) : NFIProxyClientModule(p)
{
    m_proxyClientLinkId = 0;
    m_loginInterPing = 0;
}

NFCProxyClientModule::~NFCProxyClientModule()
{
}

bool NFCProxyClientModule::Awake()
{
    m_packetConfig.LoadConfig(m_pObjPluginManager->GetConfigPath() + "/Server", "ProxyServer");
    SetTimer(NF_PROXY_CLIENT_TIMER_ID, NF_PROXY_CLIENT_INTERVAL_TIME);
    //////来自客户端的协议////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::CLIENT_TO_LOGIC_PING, this,
                                                       &NFCProxyClientModule::OnHandleClientHeartBeat);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::CLIENT_TO_CENTER_LOGIN, this,
                                                       &NFCProxyClientModule::OnHandleClientCenterLogin);
    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        if (!m_pObjPluginManager->IsLoadAllServer())
        {
            if (pConfig->ServerType != NF_ST_PROXY_SERVER)
            {
                NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        int64_t extern_unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_PROXY_SERVER, externUrl, pConfig->NetThreadNum,
                                                                             pConfig->MaxConnectNum,
                                                                             pConfig->ParseType, pConfig->Security);
        if (extern_unlinkId >= 0)
        {
            /*
            注册服务器事件
            */
            m_proxyClientLinkId = (uint64_t) extern_unlinkId;
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnProxyClientSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnHandleProxyClientOtherMessage);
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        } else
        {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
            return false;
        }
    } else
    {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "I Can't get the Proxy Server config!");
        return false;
    }

    return true;
}

bool NFCProxyClientModule::Init()
{
    SetTimer(1, 1000);
    return true;
}

bool NFCProxyClientModule::Execute()
{
    return true;
}

bool NFCProxyClientModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseLinkId(m_proxyClientLinkId);
    return true;
}

void NFCProxyClientModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == NF_PROXY_CLIENT_TIMER_ID)
    {
        HandleProxyClientTick();
    }
}

/*
	处理客户端链接事件
*/
int NFCProxyClientModule::OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} port:{} linkId:{} connected proxy server success!", ip, port, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->SetLinkId(unLinkId);
            pLinkInfo->SetIpAddr(ip);
            pLinkInfo->SetPort(port);
            pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());
            mClientLinkInfo.AddElement(unLinkId, pLinkInfo);
        }
    } else if (nEvent == eMsgType_DISCONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} port:{} link:{} disconnected proxy server!", ip, port, unLinkId);
        OnHandleClientDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyClientModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "can't find the link, ip:{} packet:{}",
                     ip, packet.ToString());

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return 0;
    }

    int count = 0;
    int interval = 0;
    uint64_t roleID = 0;
    pLinkInfo->AddPkgStatistic(packet.nMsgId, pLinkInfo->GetPlayerId(), unLinkId);
    int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, packet.nMsgId, count, interval);
    if (ret != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check and kick player:{| linkId:{} count:{} interval:{} ret:{} packet:{}", roleID, unLinkId, count, interval, ret, packet.ToString());
        KickPlayer(unLinkId, proto_ff::LOGOUT_FLAG_KICK);
        return 0;
    }


    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetPlayerId());
    if (pPlayerInfo == nullptr)
    {
        auto pPacketConfig = m_packetConfig.GetPacketConfig(packet.nMsgId);
        if (pPacketConfig && pPacketConfig->servertype() == NF_ST_WORLD_SERVER)
        {
            NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER);
            if (pWorldServer)
            {
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(), packet.nMsgId, packet.mBufferMsg.ReadAddr(), packet.mBufferMsg.ReadableSize(), unLinkId);
            }
            else {
                NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, pLinkInfo->GetPlayerId(), "can't find the player:{} info, the cmd don't find the trans to world server, world server not exist, ip:{} packet:{}", pLinkInfo->GetPlayerId(), ip, packet.ToString());
            }
        }
        else {
            NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, pLinkInfo->GetPlayerId(), "can't find the player:{} info, the cmd don't find the trans config, ip:{} packet:{}", pLinkInfo->GetPlayerId(), ip, packet.ToString());
        }
        return 0;
    }
    else {
        if (!pPlayerInfo->IsLogin())
        {
            NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "ip:{} not login,send packet:{}, the msg will not send",
                         ip, packet.ToString());

            return 0;
        }

        if (pPlayerInfo->GetLogicBusId() > 0)
        {
            NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->GetPlayerId(), "recv packet = {}, transfer to logic server", packet.ToString());
            //FindModule<NFIMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mLogicBusId, nMsgId, msg, nLen,
            //                                         pPlayerInfo->mPlayerId);
        } else
        {
            NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->GetPlayerId(), "recv nMsgId = {}, not transfer to logic server", packet.ToString());

            FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        }
    }

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleClientDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo)
    {
        if (pLinkInfo->GetPlayerId() > 0)
        {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetPlayerId());
            if (pPlayerInfo)
            {
                pPlayerInfo->SetLinkId(0);
                pPlayerInfo->SetGameBusId(0);
                pPlayerInfo->SetLogicBusId(0);
                pPlayerInfo->SetOnline(false);
                pPlayerInfo->SetDisconnectTime(NFTime::Now().UnixSec());

                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} link:{} disconenct.........", pLinkInfo->GetPlayerId(), unLinkId);
            }
        }
        mClientLinkInfo.RemoveElement(unLinkId);
    }

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleOtherServerOtherMessage(uint64_t unLinkId, const NFDataPackage &packet)
{
    /*
    auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, busId);
    if (pServerData)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, playerId, "proxy trans other server:{} msg:{} to client", pServerData->mServerInfo.server_name(), nMsgId);
        NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
        if (pPlayerInfo)
        {
            FindModule<NFIMessageModule>()->Send(pPlayerInfo->mLinkId, nMsgId, msg, nLen, 0);
        }
        else
        {
            NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "other server msg:{} not handle", nMsgId);
        }
    }
    */

    return 0;
}

int NFCProxyClientModule::OnHandleClientHeartBeat(uint64_t unLinkId, NFDataPackage &packet)
{
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find unLinkId:{}", unLinkId);
        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return -1;
    }

    pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());

    proto_ff::PingRsp xData;
    xData.set_currentmstime(NFTime::Now().UnixMSec());
    xData.set_queuereducenum(m_loginInterPing);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::SERVER_TO_CLIENT_PING, xData);

    return 0;
}

int NFCProxyClientModule::OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_ff::ClientLoginGateReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find unLinkId:{}", unLinkId);
        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return -1;
    }

    pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());

    proto_ff::ClientToLogInfoProto *pLogInfo = xMsg.mutable_loginfo();
    if (pLogInfo)
    {
        pLogInfo->set_ip(pLinkInfo->GetIpAddr());
        pLogInfo->set_port(pLinkInfo->GetPort());
    }

    NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER);
    if (pWorldServer)
    {
        FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(), proto_ff::CLIENT_TO_CENTER_LOGIN, xMsg, unLinkId);
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find world server, the packet:{} drop msg", packet.ToString());
    }

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::HandleProxyClientTick()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pProxyClient = mClientLinkInfo.First();
    while (pProxyClient)
    {
        if (pProxyClient->GetPlayerId() <= 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->HeartBeatTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check heart beat timeout........., disconnect link:{} ", pProxyClient->GetLinkId());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        if (pProxyClient->GetPlayerId() > 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->ClientKeepAliveTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pProxyClient->GetPlayerId(), "check player keep alive timeout........., disconnect link:{} playerId:{}",
                       pProxyClient->GetLinkId(), pProxyClient->GetPlayerId());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        pProxyClient = mClientLinkInfo.Next();
    }
    return 0;
}

int NFCProxyClientModule::KickPlayer(uint64_t unLinkId, uint32_t flag)
{
    proto_ff::NotifyLogoutGame leave;
    leave.set_flag((::proto_ff::LOGOUT_FLAG)flag);

    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CENTER_TO_CLIENT_LOGINOUT, leave);
    FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
    return 0;
}
