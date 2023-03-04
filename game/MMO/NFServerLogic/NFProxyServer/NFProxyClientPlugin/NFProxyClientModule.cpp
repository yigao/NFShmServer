// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFTime.h>
#include <Com.pb.h>
#include <ComDefine.pb.h>
#include <ClientServerCmd.pb.h>
#include <ClientServer.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <ServerInternalCmd.pb.h>
#include "NFProxyClientModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "CSLogin.pb.h"
#include "ServerInternal.pb.h"
#include "ServerInternal2.pb.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "ServerInternalCmd2.pb.h"

NFCProxyClientModule::NFCProxyClientModule(NFIPluginManager *p) : NFIProxyClientModule(p)
{
    m_proxyClientLinkId = 0;
}

NFCProxyClientModule::~NFCProxyClientModule()
{
}

bool NFCProxyClientModule::Awake()
{
    m_packetConfig.LoadConfig(m_pObjPluginManager->GetConfigPath() + "/Server", "ProxyServer");
    SetTimer(NF_PROXY_CLIENT_TIMER_ID, NF_PROXY_CLIENT_INTERVAL_TIME);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FindModule<NFIProxyServerModule>()->SetOtherServerMsgHandle(this, &NFCProxyClientModule::OnHandleOtherServerToClientMsg);
    //////来自客户端的协议////////////////////////////////////////
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_PING_REQ);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_LOGIN_REQ);

    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::NOTIFY_GATE_LEAVE_GAME);
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_QUEUE_POS_RSP);
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_LOGIN_RSP);
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_CREATE_ROLE_RSP);
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_ENTER_GAME_RSP);

    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::WORLD_TO_PROXY_SERVER_BUS_ID_CHANGE_NOTIFY);

    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        if (!m_pObjPluginManager->IsLoadAllServer())
        {
            if (pConfig->ServerType != NF_ST_PROXY_SERVER)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        uint64_t extern_unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_PROXY_SERVER, externUrl, pConfig->NetThreadNum,
                                                                             pConfig->MaxConnectNum,
                                                                             pConfig->ParseType, pConfig->Security);
        if (extern_unlinkId > 0)
        {
            /*
            注册服务器事件
            */
            m_proxyClientLinkId = extern_unlinkId;
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnProxyClientSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnHandleProxyClientOtherMessage);
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "proxy client listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "proxy client listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
            return false;
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the Proxy Server config!");
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

int NFCProxyClientModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == NF_PROXY_CLIENT_TIMER_ID)
    {
        HandleProxyClientTick();
        HandlePlayerTick();
    }
    return 0;
}

int NFCProxyClientModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        case proto_ff::CLIENT_PING_REQ:
        {
            OnHandleClientHeartBeat(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_LOGIN_REQ:
        {
            OnHandleClientLogin(unLinkId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCProxyClientModule::OnHandleLeaveGame(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::NotifyGateLeaveGame2 xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t clientId = xMsg.clientid();
    proto_ff::LOGOUT_TYPE leaveFlag = xMsg.leave_flag();

    LeaveGame(clientId, leaveFlag);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        case proto_ff::NOTIFY_GATE_LEAVE_GAME:
        {
            OnHandleLeaveGame(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_QUEUE_POS_RSP:
        {
            OnHandleClientQueueResult(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_LOGIN_RSP:
        {
            OnHandleClientLoginRep(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_CREATE_ROLE_RSP:
        {
            OnHandleCreateRoleRsp(unLinkId, packet);
            break;
        }
        case proto_ff::WORLD_TO_PROXY_SERVER_BUS_ID_CHANGE_NOTIFY:
        {
            OnHandleChangeServerBusId(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_ENTER_GAME_RSP:
        {
            OnHandleEnterGameRsp(unLinkId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

/*
	处理客户端链接事件
*/
int NFCProxyClientModule::OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} linkId:{} connected proxy server success!", ip, port, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        CHECK_EXPR_ASSERT(pLinkInfo == NULL, -1, "unLinkId:{} Exist", unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->SetLinkId(unLinkId);
            pLinkInfo->SetIpAddr(ip);
            pLinkInfo->SetPort(port);
            pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());
            mClientLinkInfo.AddElement(unLinkId, pLinkInfo);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} link:{} disconnected proxy server!", ip, port, unLinkId);
        OnHandleClientDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyClientModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "can't find the link, ip:{} packet:{}",
                     ip, packet.ToString());

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return 0;
    }

    int count = 0;
    int interval = 0;
    uint64_t roleID = 0;
    pLinkInfo->AddPkgStatistic(packet.nMsgId, pLinkInfo->GetUid(), unLinkId);
    int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, packet.nMsgId, count, interval);
    if (ret != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check and kick player:{| linkId:{} count:{} interval:{} ret:{} packet:{}", roleID, unLinkId, count,
                   interval, ret, packet.ToString());
        LeaveGame(unLinkId, proto_ff::LOGOUT_KICK_OUT);
        return 0;
    }

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetUid());
    if (pPlayerInfo == nullptr)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the clientId:{} 's playerId:{}, drop msg:{}", unLinkId, pLinkInfo->GetUid(), packet.ToString());
        LeaveGame(unLinkId, proto_ff::LOGOUT_KICK_OUT);
        return 0;
    }
    else
    {
        if (!pPlayerInfo->IsLogin())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "the clientId:{} 's playerId:{} not login, drop msg:{}", unLinkId, pLinkInfo->GetUid(), packet.ToString());
            LeaveGame(unLinkId, proto_ff::LOGOUT_KICK_OUT);
            return 0;
        }

        uint32_t serverType = FindModule<NFIProxyServerModule>()->GetClientMsgServer(packet.nMsgId);
        if (serverType == NF_ST_WORLD_SERVER)
        {
            NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                                                  NF_ST_WORLD_SERVER,
                                                                                                                pPlayerInfo->GetUid());
            if (pWorldServer)
            {
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(), NF_MODULE_CLIENT, packet.nMsgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetUid(),
                                                                          pPlayerInfo->GetRoleId());
            }
            else
            {
                NFLogWarning(NF_LOG_SYSTEMLOG, pLinkInfo->GetUid(),
                             "can't find the player:{} info, the cmd don't find the trans to world server, world server not exist, ip:{} packet:{}",
                             pLinkInfo->GetUid(), ip, packet.ToString());
            }
        }
        else if (serverType == NF_ST_LOGIC_SERVER)
        {
            if (pPlayerInfo->GetLogicBusId() > 0)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "recv packet = {}, transfer to logic server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->GetLogicBusId(), NF_MODULE_CLIENT, packet.nMsgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetUid(),
                                                                          pPlayerInfo->GetRoleId());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "recv nMsgId = {}, not transfer to logic server", packet.ToString());

                //FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
            }
        }
        else if (serverType == NF_ST_GAME_SERVER)
        {
            if (pPlayerInfo->GetGameBusId() > 0)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "recv packet = {}, transfer to game server", packet.ToString());
                FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->GetGameBusId(), NF_MODULE_CLIENT, packet.nMsgId,
                                                                          packet.GetBuffer(), packet.GetSize(), pPlayerInfo->GetUid(),
                                                                          pPlayerInfo->GetRoleId());
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "recv nMsgId = {}, not transfer to game server", packet.ToString());

                //FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "no server handle the msg, drop msg:{}", packet.ToString());
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleClientDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo)
    {
        if (pLinkInfo->GetUid() > 0)
        {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetUid());
            if (pPlayerInfo && pPlayerInfo->GetLinkId() == unLinkId)
            {
                NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
            }
        }
        mClientLinkInfo.RemoveElement(unLinkId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::NotifyPlayerDisconnect(uint64_t unLinkId, NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo) const
{
    CHECK_NULL(pPlayerInfo);
    pPlayerInfo->SetLinkId(0);
    pPlayerInfo->SetOnline(false);
    pPlayerInfo->SetDisconnectTime(NFTime::Now().UnixSec());

    NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER,
                                                                          pPlayerInfo->GetUid());
    if (pWorldServer)
    {
        proto_ff::NotifyCenterDisConnect xMsg;
        xMsg.set_cid(pPlayerInfo->GetRoleId());
        xMsg.set_clientid(unLinkId);
        FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(), NF_MODULE_SERVER,
                                          proto_ff::NOTIFY_CENTER_DISCONNECT, xMsg, unLinkId, pPlayerInfo->GetUid());
    }
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "uid:{} roleId:{} link:{} disconenct.........", pPlayerInfo->GetUid(), pPlayerInfo->GetRoleId(), unLinkId);
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
            NFLogError(NF_LOG_SYSTEMLOG, 0, "other server msg:{} not handle", nMsgId);
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

    proto_ff::ClientPingRsp xData;
    xData.set_unix_sec(NFTime::Now().UnixSec());
    xData.set_unix_msec(NFTime::Now().UnixMSec());
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_PING_RSP, xData);

    return 0;
}

int NFCProxyClientModule::OnHandleClientLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find unLinkId:{}", unLinkId);
        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return -1;
    }

    uint64_t uid = xMsg.uid();

    if (pLinkInfo->GetUid() > 0)
    {
        if (uid != pLinkInfo->GetUid())
        {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->GetUid());
            if (pPlayerInfo)
            {
                if (pPlayerInfo->GetLinkId() > 0 && pPlayerInfo->GetLinkId() != unLinkId)
                {
                    if (LeaveGame(pPlayerInfo->GetLinkId(), proto_ff::LOGOUT_REPLACE) != 0)
                    {
                        pPlayerInfo->SetLinkId(0);
                    }
                }
                else if (pPlayerInfo->GetLinkId() == unLinkId)
                {
                    NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
                }
            }
        }
    }

    pLinkInfo->SetUid(uid);

    pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(uid);
    if (pPlayerInfo == nullptr)
    {
        pPlayerInfo = NF_SHARE_PTR<NFProxyPlayerInfo>(NF_NEW NFProxyPlayerInfo());

        pPlayerInfo->SetLinkId(unLinkId);
        pPlayerInfo->SetIpAddr(pLinkInfo->GetIpAddr());
        pPlayerInfo->SetIsLogin(false);
        pPlayerInfo->SetUid(uid);

        mPlayerLinkInfo.AddElement(pPlayerInfo->GetUid(), pPlayerInfo);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create player:{} link:{}............", pPlayerInfo->GetUid(), unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->GetUid(), unLinkId);
    }
    else
    {
        if (pPlayerInfo->GetLinkId() > 0 && pPlayerInfo->GetLinkId() != unLinkId)
        {
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
            if (pOtherInfo)
            {
                LeaveGame(pPlayerInfo->GetLinkId(), proto_ff::LOGOUT_KICK_OUT);
            }
        }
        else
        {
            if (pPlayerInfo->GetRoleId() > 0)
            {
                NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
            }
        }

        pPlayerInfo->SetLinkId(unLinkId);
        pPlayerInfo->SetIpAddr(pLinkInfo->GetIpAddr());
        pPlayerInfo->SetIsLogin(false);
        pPlayerInfo->SetUid(uid);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->GetUid(), unLinkId);
    }

    NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER,
                                                                                                        pPlayerInfo->GetUid());
    if (pWorldServer)
    {
        FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pWorldServer->mServerInfo.bus_id(), NF_MODULE_CLIENT,
                                                                  packet.nMsgId, xMsg, unLinkId);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find world server, the packet:{} drop msg", packet.ToString());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::HandleProxyClientTick()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pProxyClient = mClientLinkInfo.First();
    while (pProxyClient)
    {
        if (pProxyClient->GetUid() <= 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->HeartBeatTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check heart beat timeout........., disconnect link:{} ", pProxyClient->GetLinkId());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        if (pProxyClient->GetUid() > 0 && pProxyClient->GetLastActiveTime() > 0 &&
            NFTime::Now().UnixSec() - pProxyClient->GetLastActiveTime() >= pConfig->ClientKeepAliveTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pProxyClient->GetUid(), "check player keep alive timeout........., disconnect link:{} playerId:{}",
                       pProxyClient->GetLinkId(), pProxyClient->GetUid());
            FindModule<NFIMessageModule>()->CloseLinkId(pProxyClient->GetLinkId());
        }

        pProxyClient = mClientLinkInfo.Next();
    }
    return 0;
}

int NFCProxyClientModule::KickPlayer(uint64_t unLinkId, uint32_t flag)
{
    return 0;
}

/**
 * @brief 处理世界服务器返回的排队协议
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCProxyClientModule::OnHandleClientQueueResult(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.nParam1;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
    if (pPlayerInfo)
    {
        pPlayerInfo->SetIsLogin(true);
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        FindModule<NFIMessageModule>()->TransPackage(pPlayerInfo->GetLinkId(), packet);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "other server msg:{} not handle", packet.ToString());
    }

    return 0;
}

int NFCProxyClientModule::LeaveGame(uint64_t clientId, proto_ff::LOGOUT_TYPE flag)
{
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, clientId, "can't find player linkId, player disconnect:{}", clientId);
        return -1;
    }

    KickPlayer(clientId, flag);

    FindModule<NFIMessageModule>()->CloseLinkId(clientId);

    return 0;
}

int NFCProxyClientModule::OnHandleOtherServerToClientMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.nParam1;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
    if (pPlayerInfo)
    {
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), NF_MODULE_CLIENT, packet.nMsgId, packet.GetBuffer(), packet.GetSize());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info, other server msg:{} not handle", playerId, packet.ToString());
    }

    return 0;
}

int NFCProxyClientModule::OnHandleRedirectMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    const ::proto_ff::Proto_RedirectInfo& redirectInfo = xMsg.redirect_info();
    for(int i = 0; i < (int)redirectInfo.id_size(); i++)
    {
        uint64_t playerId = redirectInfo.id(i);
        NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
        if (pPlayerInfo)
        {
            NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
            if (pLinkInfo == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
                return -1;
            }

            FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), NF_MODULE_CLIENT, (uint32_t)xMsg.msg_id(), xMsg.msg_data());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info, other server msg:{} not handle", playerId, packet.ToString());
        }
    }

    return 0;
}

int NFCProxyClientModule::OnHandleClientLoginRep(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.nParam1;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
    if (pPlayerInfo)
    {
        pPlayerInfo->SetIsLogin(true);
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), packet.nMsgId, packet.GetBuffer(), packet.GetSize());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "other server msg:{} not handle", packet.ToString());
    }

    return 0;
}

int NFCProxyClientModule::HandlePlayerTick()
{
    std::vector<uint64_t> vec;
    auto pPlayerInfo = mPlayerLinkInfo.First();
    while(pPlayerInfo)
    {
        if (pPlayerInfo->IsOnline() == false) {
            if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_EXIST_TIME) {
                vec.push_back(pPlayerInfo->GetUid());
            }

            if (pPlayerInfo->IsLogin())
            {
                if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_RECONNECT_TIME)
                {
                    pPlayerInfo->SetIsLogin(false);
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "player disconnect 60s, islogin = false:{}", pPlayerInfo->GetUid());
                }
            }
        }
        pPlayerInfo = mPlayerLinkInfo.Next();
    }

    for(int i = 0; i < (int)vec.size(); i++)
    {
        mPlayerLinkInfo.RemoveElement(vec[i]);
    }
    return 0;
}

int NFCProxyClientModule::OnHandleCreateRoleRsp(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::ClientCreateRoleRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t uid = packet.nParam1;
    uint64_t cid = packet.nParam2;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(uid);
    if (pPlayerInfo)
    {
        if (xMsg.result() == 0)
        {
            pPlayerInfo->SetRoleId(cid);
        }

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), packet.nMsgId, packet.GetBuffer(), packet.GetSize());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player info:{} drop msg:{} not handle", uid, packet.ToString());
    }

    return 0;
}

int NFCProxyClientModule::OnHandleEnterGameRsp(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::ClientEnterGameRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t uid = packet.nParam1;
    uint64_t cid = packet.nParam2;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(uid);
    if (pPlayerInfo)
    {
        if (xMsg.ret() == proto_ff::RET_SUCCESS)
        {
            pPlayerInfo->SetRoleId(cid);
        }
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), packet.nMsgId, packet.GetBuffer(), packet.GetSize());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player info:{} drop msg:{} not handle", uid, packet.ToString());
    }

    return 0;
}

int NFCProxyClientModule::OnHandleChangeServerBusId(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::WroldToProxyChangeServerBusId xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t uid = packet.nParam1;
    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(uid);
    if (pPlayerInfo)
    {
        for(int i = 0; i < (int)xMsg.server_info_size(); i++)
        {
            auto& serverInfo = xMsg.server_info(i);
            if (serverInfo.server_type() == NF_ST_LOGIC_SERVER)
            {
                pPlayerInfo->SetLogicBusId(serverInfo.bus_id());
            }
            else if (serverInfo.server_type() == NF_ST_GAME_SERVER)
            {
                pPlayerInfo->SetGameBusId(serverInfo.bus_id());
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player info:{} drop msg:{} not handle", uid, packet.ToString());
    }

    return 0;
}
