// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include "NFProxyPlayerModule.h"
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "Login.pb.h"
#include "ServerInternalCmd.pb.h"

NFCProxyPlayerModule::NFCProxyPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{
}

NFCProxyPlayerModule::~NFCProxyPlayerModule()
{
}

bool NFCProxyPlayerModule::Awake()
{
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::CLIENT_PING_REQ);
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_CLIENT, proto_ff::CLIENT_PING_RSP);

    m_packetConfig.LoadConfig(m_pObjPluginManager->GetConfigPath() + "/Server", "ProxyServer");
    SetTimer(NF_PROXY_CLIENT_TIMER_ID, NF_PROXY_CLIENT_INTERVAL_TIME);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////来自客户端的协议////////////////////////////////////////
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_LOGIN_REQ, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_PING_REQ);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_RECONNECT_REQ, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_CREATE_ROLE_REQ, true);
    RegisterClientMessage(NF_ST_PROXY_SERVER, proto_ff::CLIENT_ENTER_GAME_REQ, true);


    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
    RegisterServerMessage(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NOTIFY_GATE_LEAVE_GAME>(NF_ST_PROXY_SERVER, this,
                                                                                              &NFCProxyPlayerModule::OnRpcServicePlayerLeaveGame);
    return true;
}

bool NFCProxyPlayerModule::Init()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        uint64_t proxyClientLinkId = FindModule<NFIMessageModule>()->GetClientLinkId(NF_ST_PROXY_SERVER);
        if (proxyClientLinkId > 0)
        {
            /*
            注册服务器事件
            */
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId, this,
                                                             &NFCProxyPlayerModule::OnProxyClientSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId, this,
                                                             &NFCProxyPlayerModule::OnHandleProxyClientOtherMessage);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get NF_ST_PROXY_SERVER ClientLinkId Failed!");
            return false;
        }

        uint64_t proxyServerLinkId = FindModule<NFIMessageModule>()->GetServerLinkId(NF_ST_PROXY_SERVER);
        if (proxyServerLinkId > 0)
        {
            /*
            注册服务器事件
            */
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, proxyServerLinkId, this,
                                                             &NFCProxyPlayerModule::OnHandleOtherServerToClientMsg);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get NF_ST_PROXY_SERVER ClientLinkId Failed!");
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

bool NFCProxyPlayerModule::Execute()
{
    return true;
}

bool NFCProxyPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCProxyPlayerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == NF_PROXY_CLIENT_TIMER_ID)
    {
        HandleProxyClientTick();
        HandlePlayerTick();
    }
    return 0;
}

int NFCProxyPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_PROXY_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
    if (pLinkInfo)
    {
        int count = 0;
        int interval = 0;
        uint64_t roleID = 0;
        pLinkInfo->AddPkgStatistic(packet.nMsgId, pLinkInfo->GetUid(), unLinkId);
        int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, packet.nMsgId, count, interval);
        if (ret != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check and kick player:{} linkId:{} count:{} interval:{} ret:{} packet:{}", roleID, unLinkId, count,
                       interval, ret, packet.ToString());
            return 0;
        }
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
            OnHandlePlayerLoginFromClient(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_CREATE_ROLE_REQ:
        {
            OnHandleCreateRoleFromClient(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_ENTER_GAME_REQ:
        {
            OnHandleEnterGameReq(unLinkId, packet);
            break;
        }
        case proto_ff::CLIENT_RECONNECT_REQ:
        {
            OnHandlePlayerReconnectFromClient(unLinkId, packet);
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


int NFCProxyPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_PROXY_SERVER))
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
        case proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD:
        {
            OnHandleRedirectMsg(unLinkId, packet);
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
int NFCProxyPlayerModule::OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} linkId:{} connected proxy server success!", ip, port, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
        CHECK_EXPR_ASSERT(pLinkInfo == NULL, -1, "unLinkId:{} Exist", unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->SetLinkId(unLinkId);
            pLinkInfo->SetIpAddr(ip);
            pLinkInfo->SetPort(port);
            pLinkInfo->SetLastActiveTime(NFTime::Now().UnixSec());
            mSessionMap.AddElement(unLinkId, pLinkInfo);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        uint32_t port = FindModule<NFIMessageModule>()->GetPort(unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} link:{} disconnected proxy server!", ip, port, unLinkId);
        OnHandleClientDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyPlayerModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "can't find the link, ip:{} packet:{}",
                     ip, packet.ToString());

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return 0;
    }

    NF_SHARE_PTR<NFProxyAccount> pAccount= mAccountMap.GetElement(pLinkInfo->GetUid());
    if (pAccount == nullptr)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the clientId:{} 's playerId:{}, drop msg:{}", unLinkId, pLinkInfo->GetUid(), packet.ToString());
        return 0;
    }

    pAccount->SetOnline(true);

    uint32_t msgId = packet.nMsgId;

    int count = 0;
    int interval = 0;
    pLinkInfo->AddPkgStatistic(msgId, pLinkInfo->GetUid(), unLinkId);
    int ret = pLinkInfo->CheckPkgRate(&m_packetConfig, msgId, count, interval);
    if (ret != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pkg check player:{} linkId:{} count:{} interval:{} ret:{} packet:{}", pLinkInfo->GetUid(), unLinkId, count,
                   interval, ret, packet.ToString());
        return 0;
    }

    if (!pAccount->IsLogin())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "the clientId:{} 's uid:{} not login, drop msg:{}", unLinkId, pLinkInfo->GetUid(),
                   packet.ToString());
        return 0;
    }

    uint32_t serverType = FindModule<NFIProxyServerModule>()->GetClientMsgServer(msgId);
    if (serverType == NF_ST_WORLD_SERVER)
    {
        if (pAccount->GetWorldBusId() > 0)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv packet = {}, transfer to world server", packet.ToString());
            FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pAccount->GetWorldBusId(),
                                                                      NF_MODULE_CLIENT, msgId,
                                                                      packet.GetBuffer(), packet.GetSize(), pAccount->GetUid(),
                                                                      0);
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
        if (pAccount->GetLogicBusId() > 0)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv packet = {}, transfer to logic server", packet.ToString());
            FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pAccount->GetLogicBusId(), NF_MODULE_CLIENT,
                                                                      msgId,
                                                                      packet.GetBuffer(), packet.GetSize(), pAccount->GetUid(),
                                                                      0);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv nMsgId = {}, not transfer to logic server", packet.ToString());
        }
    }
    else if (serverType == NF_ST_GAME_SERVER)
    {
        if (pAccount->GetGameBusId() > 0)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv packet = {}, transfer to game server", packet.ToString());
            FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pAccount->GetGameBusId(), NF_MODULE_CLIENT,
                                                                      msgId,
                                                                      packet.GetBuffer(), packet.GetSize(), pAccount->GetUid(),
                                                                      0);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv nMsgId = {}, not transfer to game server", packet.ToString());
        }
    }
    else if (serverType == NF_ST_SNS_SERVER)
    {
        NF_SHARE_PTR<NFServerData> pSnsServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                                          NF_ST_SNS_SERVER,
                                                                                                          pAccount->GetUid());
        if (pSnsServer)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "recv packet = {}, transfer to sns server", packet.ToString());
            FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pSnsServer->mServerInfo.bus_id(), NF_MODULE_CLIENT,
                                                                      msgId,
                                                                      packet.GetBuffer(), packet.GetSize(), pAccount->GetUid(),
                                                                      0);
        }
        else
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, pLinkInfo->GetUid(),
                         "can't find the player:{} info, the cmd don't find the trans to sns server, sns server not exist, ip:{} packet:{}",
                         pLinkInfo->GetUid(), ip, packet.ToString());
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "no server handle the msg, drop msg:{}", packet.ToString());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleClientDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
    if (pLinkInfo)
    {
        if (pLinkInfo->GetUid() > 0)
        {
            NF_SHARE_PTR<NFProxyAccount> pPlayerInfo = mAccountMap.GetElement(pLinkInfo->GetUid());
            if (pPlayerInfo)
            {
                if (pPlayerInfo->GetLinkId() == unLinkId)
                {
                    NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
                }
                else if (pPlayerInfo->GetLinkId() > 0)
                {
                    NF_SHARE_PTR<NFProxySession> pOtherLinkInfo = mSessionMap.GetElement(pPlayerInfo->GetLinkId());
                    if (pOtherLinkInfo == NULL)
                    {
                        NotifyPlayerDisconnect(unLinkId, pPlayerInfo);
                    }
                }
            }
        }
        mSessionMap.RemoveElement(unLinkId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleClientHeartBeat(uint64_t unLinkId, NFDataPackage &packet)
{
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
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

int NFCProxyPlayerModule::HandleProxyClientTick()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pProxyClient = mSessionMap.First();
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

        pProxyClient = mSessionMap.Next();
    }
    return 0;
}

int NFCProxyPlayerModule::OnHandleOtherServerToClientMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.nParam1;
    NF_SHARE_PTR<NFProxyAccount> pPlayerInfo = mAccountMap.GetElement(playerId);
    if (pPlayerInfo)
    {
        NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(pPlayerInfo->GetLinkId());
        if (pLinkInfo == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
            return -1;
        }

        uint32_t srcBusId = packet.nSrcId;
        auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, srcBusId);
        if (pServerData)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetUid(), "trans {} msg to client, packet:{}", pServerData->mServerInfo.server_name(),
                      packet.ToString());
        }

        FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), NF_MODULE_CLIENT, packet.nMsgId, (const char*)packet.GetBuffer(), (uint32_t)packet.GetSize());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info or clientId change, other server msg:{} not handle", playerId, packet.ToString());
    }

    return 0;
}

int NFCProxyPlayerModule::OnHandleRedirectMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    const ::proto_ff::Proto_RedirectInfo &redirectInfo = xMsg.redirect_info();
    for (int i = 0; i < (int) redirectInfo.id_size(); i++)
    {
        uint64_t playerId = redirectInfo.id(i);
        NF_SHARE_PTR<NFProxyAccount> pPlayerInfo = mAccountMap.GetElement(playerId);
        if (pPlayerInfo)
        {
            NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(pPlayerInfo->GetLinkId());
            if (pLinkInfo == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, unLinkId, "can't find player linkId, player disconnect:{}", unLinkId);
                return -1;
            }

            FindModule<NFIMessageModule>()->Send(pPlayerInfo->GetLinkId(), (uint32_t) xMsg.msg_id(), xMsg.msg_data());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find player:{} info, other server msg:{} not handle", playerId, packet.ToString());
        }
    }

    return 0;
}

int NFCProxyPlayerModule::HandlePlayerTick()
{
    std::vector<uint64_t> vec;
    auto pPlayerInfo = mAccountMap.First();
    while (pPlayerInfo)
    {
        if (pPlayerInfo->IsOnline() == false)
        {
/*            if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_EXIST_TIME)
            {
                vec.push_back(pPlayerInfo->GetUid());
            }

            if (pPlayerInfo->IsLogin())
            {
                if (NFTime::Now().UnixSec() - pPlayerInfo->GetDisconnectTime() >= PLAYER_MAX_DISCONNECT_RECONNECT_TIME)
                {
                    pPlayerInfo->SetIsLogin(false);
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "player disconnect 60s, islogin = false:{}", pPlayerInfo->GetUid());
                }
            }*/
        }
        pPlayerInfo = mAccountMap.Next();
    }

    for (int i = 0; i < (int) vec.size(); i++)
    {
        mAccountMap.RemoveElement(vec[i]);
    }
    return 0;
}

int NFCProxyPlayerModule::KickPlayer(uint64_t unLinkId, int reason)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "kick linkId:{}", unLinkId);
    proto_ff::ClientLogoutNotify rsp;
    rsp.set_reason(reason);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_LOGOUT_NOTIFY, rsp);
    FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
    return 0;
}

int NFCProxyPlayerModule::OnHandlePlayerLoginFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::ClientLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    NF_SHARE_PTR<NFProxySession> pSession = mSessionMap.GetElement(unLinkId);
    CHECK_NULL(pSession);

    NF_SHARE_PTR<NFProxyAccount> pAccount = mAccountMap.GetElement(cgMsg.uid());
    if (pAccount == nullptr) {
        pAccount = NF_SHARE_PTR<NFProxyAccount>(NF_NEW NFProxyAccount());

        pAccount->SetLinkId(unLinkId);
        pAccount->SetIpAddr(pSession->GetIpAddr());
        pAccount->SetIsLogin(true);
        pAccount->SetUid(cgMsg.uid());

        mAccountMap.AddElement(pAccount->GetUid(), pAccount);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create new link, uid:{} link:{}............", pAccount->GetUid(), unLinkId);
    }
    else {
        if (pAccount->GetLinkId() > 0 && pAccount->GetLinkId() != unLinkId) {
            auto pOtherInfo = mSessionMap.GetElement(pAccount->GetLinkId());
            if (pOtherInfo) {
                KickPlayer(pAccount->GetLinkId());
            }
        }

        pAccount->SetLinkId(unLinkId);
        pAccount->SetIpAddr(pSession->GetIpAddr());
        pAccount->SetIsLogin(true);
        pAccount->SetUid(cgMsg.uid());

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, uid:{} link:{}............", pAccount->GetUid(), unLinkId);
    }

    pAccount->SetOnline(true);

    pSession->SetUid(cgMsg.uid());

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_NULL(pConfig);

    NF_SHARE_PTR<NFServerData> pWorldServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, cgMsg.uid());
    CHECK_NULL(pWorldServer);

    pAccount->SetWorldBusId(pWorldServer->mServerInfo.bus_id());
    cgMsg.set_ip(pSession->GetIpAddr());
    proto_ff::ClientLoginRsp rspMsg;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::CLIENT_LOGIN_REQ>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pAccount->GetWorldBusId(), cgMsg, rspMsg, pConfig->GetBusId(), unLinkId);
    /**
     * @brief 异步后需要重新查找
     */
    pAccount = mAccountMap.GetElement(cgMsg.uid());
    CHECK_NULL(pAccount);

    if (iRet != 0)
    {
        rspMsg.set_ret(iRet);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_LOGIN_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_PTW_PLAYER_LOGIN_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (rspMsg.ret() != proto_ff::RET_SUCCESS)
    {
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_LOGIN_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_PTW_PLAYER_LOGIN_REQ result:{}!", GetErrorStr(rspMsg.ret()));
        return 0;
    }

    pAccount->SetIsLogin(true);
    pAccount->SetUid(cgMsg.uid());

    NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "Uid:{} Login World Success!", pAccount->GetUid());

    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_LOGIN_RSP, rspMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleCreateRoleFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::ClientCreateRoleReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    proto_ff::ClientCreateRoleRsp rspMsg;
    rspMsg.set_result(proto_ff::RET_SUCCESS);

    NF_SHARE_PTR<NFProxySession> pSession = mSessionMap.GetElement(unLinkId);
    CHECK_NULL(pSession);

    NF_SHARE_PTR<NFProxyAccount> pAccount = mAccountMap.GetElement(pSession->GetUid());
    if (pAccount == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "Can't find the uid:{} account info, create role failed!", pSession->GetUid());
        rspMsg.set_result(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }

    if (pAccount->GetLinkId() != unLinkId)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "the uid:{} account client change, create role failed!", pSession->GetUid());
        rspMsg.set_result(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }

    if (!pAccount->IsLogin() || pAccount->GetWorldBusId() <= 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "account is not login, create role failed!", pSession->GetUid());
        rspMsg.set_result(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }

    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::CLIENT_CREATE_ROLE_REQ>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pAccount->GetWorldBusId(), cgMsg, rspMsg, pAccount->GetUid());
    pSession = mSessionMap.GetElement(unLinkId);
    CHECK_NULL(pSession);
    pAccount = mAccountMap.GetElement(pSession->GetUid());
    CHECK_NULL(pAccount);

    if (iRet != 0)
    {
        rspMsg.set_result(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::CLIENT_CREATE_ROLE_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (rspMsg.result() != proto_ff::RET_SUCCESS)
    {
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::CLIENT_CREATE_ROLE_REQ result:{}!", GetErrorStr(rspMsg.result()));
        return 0;
    }

    NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "Uid:{} Create Role Cid:{} Success!", pAccount->GetUid(), rspMsg.info().cid());

    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_CREATE_ROLE_RSP, rspMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandleEnterGameReq(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::ClientEnterGameReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    proto_ff::ClientEnterGameRsp rspMsg;
    rspMsg.set_ret(proto_ff::RET_SUCCESS);

    NF_SHARE_PTR<NFProxySession> pSession = mSessionMap.GetElement(unLinkId);
    CHECK_NULL(pSession);

    NF_SHARE_PTR<NFProxyAccount> pAccount = mAccountMap.GetElement(pSession->GetUid());
    if (pAccount == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "Can't find the uid:{} account info, enter game failed!", pSession->GetUid());
        rspMsg.set_ret(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }

    if (pAccount->GetLinkId() != unLinkId)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "the uid:{} account client change, enter game failed!", pSession->GetUid());
        rspMsg.set_ret(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }

    if (!pAccount->IsLogin() || pAccount->GetWorldBusId() <= 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetUid(), "account is not login, enter game failed!", pSession->GetUid());
        rspMsg.set_ret(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

        KickPlayer(unLinkId);
        return 0;
    }
    
    proto_ff::ClientEnterGameInternalRsp respone;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::CLIENT_ENTER_GAME_RSP>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pAccount->GetWorldBusId(), cgMsg, respone, pAccount->GetUid());
    pSession = mSessionMap.GetElement(unLinkId);
    CHECK_NULL(pSession);
    pAccount = mAccountMap.GetElement(pSession->GetUid());
    CHECK_NULL(pAccount);

    if (iRet != 0)
    {
        rspMsg.set_ret(proto_ff::RET_FAIL);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::CLIENT_ENTER_GAME_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }
    
    rspMsg.set_ret(respone.ret_code());

    if (respone.ret_code() != proto_ff::RET_SUCCESS)
    {
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

        KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::CLIENT_ENTER_GAME_REQ result:{}!", GetErrorStr(rspMsg.ret()));
        return 0;
    }

    pAccount->SetCid(cgMsg.cid());
    pSession->SetCid(cgMsg.cid());
    pAccount->SetLogicBusId(respone.logic_id());
    pAccount->SetGameBusId(respone.game_id());
    pAccount->SetSnsBusId(respone.sns_id());

    NFLogError(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "Uid:{} Cid:{} Enter Game Success!", pAccount->GetUid(), pAccount->GetCid());

    //FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnHandlePlayerReconnectFromClient(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
/*
    proto_ff::Proto_CSReconnectReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgMsg);

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    NF_SHARE_PTR<NFProxyAccountInfo> pPlayerLinkInfo = mAccountInfo.GetElement(cgMsg.userid());
    if (pPlayerLinkInfo == nullptr) {
        NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, reconnect failed!",
                  cgMsg.userid());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->IsLogin() == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, islogin == false, reconnect failed!",
                  cgMsg.userid());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->GetLinkId() > 0) {
        if (pPlayerLinkInfo->GetLinkId() == unLinkId) {
            NFLogError(NF_LOG_SYSTEMLOG, cgMsg.userid(),
                      "Player:{} reconnect proxy server, but unlink not change! some wrong!", cgMsg.userid());
        } else {
            NFLogInfo(NF_LOG_SYSTEMLOG, cgMsg.userid(), "Player:{} reconnect proxy server, but unlink exist",
                      cgMsg.userid());
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerLinkInfo->GetLinkId());
            if (pOtherInfo) {
                //disconnect, but new connect first, close old connect
                pOtherInfo->SetUid(0);

                KickPlayer(pPlayerLinkInfo->GetLinkId(), proto_ff::ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT);
            }
        }
    }

    pPlayerLinkInfo->SetLinkId(unLinkId);
    pPlayerLinkInfo->SetIpAddr(ip);
    pPlayerLinkInfo->SetOnline(true);

    pLinkInfo->SetUid(pPlayerLinkInfo->GetUid());
    pLinkInfo->SetIpAddr(ip);

    proto_ff::PTWPlayerReconnectReq reconnectReq;
    reconnectReq.set_player_id(pPlayerLinkInfo->GetUid());
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    {
        reconnectReq.set_proxy_bus_id(pConfig->GetBusId());
    }

    proto_ff::WTPPlayerReconnctRsp respone;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ>(NF_ST_PROXY_SERVER, NF_ST_WORLD_SERVER, pPlayerLinkInfo->GetWorldBusId(), reconnectReq, respone);
    if (iRet != 0)
    {
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(iRet);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (respone.result() != 0)
    {
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(respone.result());
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    pPlayerLinkInfo = mAccountInfo.GetElement(respone.player_id());
    if (pPlayerLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, respone.player_id(), "Player:{} reconnect rsp form wolrd server failed, can't find player info in the proxy server",
                   respone.player_id());

        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(respone.result());
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());

        KickPlayer(unLinkId, 0);
        return 0;
    }

    pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, respone.player_id(), "Player:{} reconnect rsp form wolrd server failed, can't find player link:{} in the proxy server",
                   respone.player_id(), unLinkId);

        NotifyPlayerDisconnect(unLinkId, pPlayerLinkInfo);
        return 0;
    }


    pPlayerLinkInfo->SetIsLogin(true);
    pPlayerLinkInfo->SetGameBusId(respone.game_bus_id());
    pPlayerLinkInfo->SetLogicBusId(respone.logic_bus_id());

    NF_SHARE_PTR<NFServerData> pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, pPlayerLinkInfo->GetLogicBusId());
    if (pLogicServer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->GetUid(), "proxy donot connect logic server:{}", pPlayerLinkInfo->GetLogicBusId());
        proto_ff::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(-1);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());

        KickPlayer(unLinkId, 0);
        return 0;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->GetUid(), "player:{} reconnect success", pPlayerLinkInfo->GetUid());

    proto_ff::Proto_SCReconnectRsp gcMsg;
    gcMsg.set_result(0);
    FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
*/

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCProxyPlayerModule::OnRpcServicePlayerLeaveGame(proto_ff::NotifyGateLeaveGame2 &request, proto_ff::EmptyMessage &respone)
{
    uint64_t unLinkId = request.clientid();
    proto_ff::LOGOUT_TYPE leaveFlag = request.leave_flag();

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mSessionMap.GetElement(unLinkId);
    if (pLinkInfo)
    {
        if (leaveFlag == proto_ff::LOGOUT_REPLACE)
        {
            KickPlayer(unLinkId, leaveFlag);
        }
        else {
            FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        }
        pLinkInfo->SetUid(0);
        pLinkInfo->SetCid(0);
    }

    return 0;
}

int NFCProxyPlayerModule::NotifyPlayerDisconnect(uint64_t unLinkId, NF_SHARE_PTR<NFProxyAccount> pPlayerInfo)
{
    return 0;
}

