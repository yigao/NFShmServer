// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include "NFProxyClientModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFServer/NFCommHead/NFIProxyServerModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"

NFCProxyClientModule::NFCProxyClientModule(NFIPluginManager* p):NFIProxyClientModule(p)
{
	m_proxyClientLinkId = 0;
}

NFCProxyClientModule::~NFCProxyClientModule()
{
}

bool NFCProxyClientModule::Awake()
{
    //////来自客户端的协议////////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_AccountLoginReq, this,
                                                       &NFCProxyClientModule::OnHandleAccountLoginFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_RegisterAccountReq, this,
                                                       &NFCProxyClientModule::OnHandleAccountRegisterFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq, this,
                                                       &NFCProxyClientModule::OnHandleLoginServerPhoneAutoCodeFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_LoginServer_CheckPhoneCodeReq, this,
                                                 &NFCProxyClientModule::OnHandleLoginServerCheckPhoneCodeFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ, this,
                                                 &NFCProxyClientModule::OnHandleChangePasswordFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_MSG_UserLoginReq, this,
                                                 &NFCProxyClientModule::OnHandleUserLoginFromClient);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_Msg_HeartBeat_REQ, this,
                                                 &NFCProxyClientModule::OnHandleHeartBeat);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, proto_login::NF_CS_Msg_ReConnect_REQ, this,
                                                 &NFCProxyClientModule::OnHandleReconnectFromClient);
    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_LoginServer_PhoneAutoCodeRsp, this,
                                                       &NFCProxyClientModule::OnHandleLoginServerPhoneAutoCodeFromLoginServer);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp, this,
                                                       &NFCProxyClientModule::OnHandleLoginServerCheckPhoneCodeFromLoginServer);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_CHANGE_PASSWORD_RESP, this,
                                                       &NFCProxyClientModule::OnHandleChangePasswordFromLoginServer);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_AccountLoginRsp, this,
		&NFCProxyClientModule::OnHandleAccountLoginFromLoginServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_RegisterAccountRsp, this,
                                                       &NFCProxyClientModule::OnHandleAccountRegisterFromLoginServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_login::NF_SC_MSG_LoginServer_NotifyPhoneCheck, this,
                                                 &NFCProxyClientModule::OnHandleNotifyPhoneCheckFromLoginServer);
    /////来自World Server返回的协议////////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_WTP_PLAYER_LOGIN_MSG_RSP, this,
                                                       &NFCProxyClientModule::OnHandleLoginRspFromWorldServer);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_WTP_PLAYER_RECONNECT_MSG_RSP,
                                                       this,
                                                       &NFCProxyClientModule::OnHandleReconnectRspFromWorldServer);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig) {
        if (!m_pPluginManager->IsLoadAllServer()) {
            if (pConfig->mServerType != NF_ST_PROXY_SERVER) {
                NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->mExternalServerIp, pConfig->mExternalServerPort);
        int64_t extern_unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_PROXY_SERVER_FOR_CLIENT, externUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum,
                                                                             pConfig->mParseType);
        if (extern_unlinkId >= 0) {
            /*
            注册服务器事件
            */
            m_proxyClientLinkId = (uint64_t) extern_unlinkId;
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnProxyClientSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnHandleProxyClientOtherMessage);
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mExternalServerIp, pConfig->mExternalServerPort);
        } else {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mExternalServerIp, pConfig->mExternalServerPort);
            return false;
        }
    }
	else
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
	NFMessageMgr::Instance()->CloseLinkId(m_proxyClientLinkId);
	return true;
}

void NFCProxyClientModule::OnTimer(uint32_t nTimerID)
{
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, , "");

    std::vector<uint64_t> vec;
    auto pPlayerInfo = mPlayerLinkInfo.First();
    while(pPlayerInfo)
    {
         if (pPlayerInfo->mOnline == false) {
             if (NFTime::Now().UnixSec() - pPlayerInfo->mDisconnectTime >= PLAYER_MAX_DISCONNECT_EXIST_TIME) {
                 vec.push_back(pPlayerInfo->mPlayerId);
             }

             if (pPlayerInfo->mIsLogin)
             {
                 if (NFTime::Now().UnixSec() - pPlayerInfo->mDisconnectTime >= PLAYER_MAX_DISCONNECT_RECONNECT_TIME)
                 {
                     pPlayerInfo->mIsLogin = false;
                     NFLogError(NF_LOG_SYSTEMLOG, 0, "player disconnect 60s, islogin = false:{}", pPlayerInfo->mPlayerId);
                 }
             }
         }
        pPlayerInfo = mPlayerLinkInfo.Next();
    }

    for(int i = 0; i < (int)vec.size(); i++)
    {
        mPlayerLinkInfo.RemoveElement(vec[i]);
    }

    auto pClientLinkInfo = mClientLinkInfo.First();
    while(pClientLinkInfo)
    {
        if (pClientLinkInfo->mPlayerId <= 0 && pClientLinkInfo->mLastHeartBeatTime > 0 && NFTime::Now().UnixSec() - pClientLinkInfo->mLastHeartBeatTime >= pConfig->mHeartBeatTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check heart beat timeout........., disconnect link:{}", pClientLinkInfo->mLinkId);
            NFMessageMgr::Instance()->CloseLinkId(pClientLinkInfo->mLinkId);
        }

        if (pClientLinkInfo->mPlayerId > 0 && pClientLinkInfo->mLastHeartBeatTime > 0 && NFTime::Now().UnixSec() - pClientLinkInfo->mLastHeartBeatTime >= pConfig->mClientKeepAliveTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check playerId keep alive timeout........., disconnect link:{}", pClientLinkInfo->mLinkId);
            NFMessageMgr::Instance()->CloseLinkId(pClientLinkInfo->mLinkId);
        }

        pClientLinkInfo = mClientLinkInfo.Next();
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
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} linkId:{} connected proxy server success!", ip, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->mLinkId = unLinkId;
            pLinkInfo->mIPAddr = ip;
            mClientLinkInfo.AddElement(unLinkId, pLinkInfo);
        }
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} link:{} disconnected proxy server!", ip, unLinkId);
		OnHandleClientDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyClientModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId,
                                                          const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == nullptr) {
        proto_login::Proto_SCKetPlayerNotify kitMsg;
        kitMsg.set_result(0);
        NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "can't find the link, ip:{} msg:{}",
                     ip, nMsgId);

        NFMessageMgr::Instance()->CloseLinkId(unLinkId);
        return 0;
    }

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->mPlayerId);
    if (pPlayerInfo == nullptr) {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "can't find the player:{} info, ip:{} msg:{}", pLinkInfo->mPlayerId, ip, nMsgId);

        return 0;
    }

    if (!pPlayerInfo->mIsLogin) {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "ip:{} not login,send msg:{}, the msg will not send",
                     ip, nMsgId);

        return 0;
    }

    if (pPlayerInfo->mLogicBusId > 0) {
        NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->mPlayerId, "recv nMsgId = {}, transfer to logic server", nMsgId);
        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mLogicBusId, nMsgId, msg, nLen,
                                                 pPlayerInfo->mPlayerId);
    }
    else
    {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->mPlayerId, "recv nMsgId = {}, not transfer to logic server", nMsgId);
        proto_login::Proto_SCKetPlayerNotify kitMsg;
        kitMsg.set_result(0);
        NFMessageMgr::Instance()->Send(pPlayerInfo->mLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

        NFMessageMgr::Instance()->CloseLinkId(unLinkId);
    }

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleHeartBeat(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_login::Proto_CSHeartBeatReq cgMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo)
    {
        pLinkInfo->mLastHeartBeatTime = NFTime::Now().UnixSec();
    }

	proto_login::Proto_SCHeartBeatRsp gcMsg;
	gcMsg.set_result(0);
	NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_Msg_HeartBeat_RSP, gcMsg, 0);
	return 0;
}

int NFCProxyClientModule::OnHandleUserLoginFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CSUserLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    uint64_t now = NFTime::Now().UnixSec();
    if (now - cgMsg.login_time() >= 30)
    {
        proto_login::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_TOKEN_TIMEOUT);
        NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_MSG_UserLoginRsp, rspMsg);

        NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "account user:{} token timeout", cgMsg.account(), cgMsg.user_id())
        return 0;
    }

    std::string token = NFCommLogic::GetLoginToken(cgMsg.account(), cgMsg.user_id(), cgMsg.login_time(), LOGIN_TOKEN);
    if (cgMsg.token() != token)
    {
        proto_login::Proto_SCUserLoginRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_TOKEN_ERROR);
        NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_MSG_UserLoginRsp, rspMsg);

        NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "account user:{} token:{} error, real token:{}", cgMsg.account(), cgMsg.user_id(), cgMsg.token(), token);
        return 0;
    }

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(cgMsg.user_id());
    if (pPlayerInfo == nullptr) {
        pPlayerInfo = NF_SHARE_PTR<NFProxyPlayerInfo>(NF_NEW NFProxyPlayerInfo());

        pPlayerInfo->mLinkId = unLinkId;
        pPlayerInfo->mIPAddr = pLinkInfo->mIPAddr;
        pPlayerInfo->mIsLogin = true;
        pPlayerInfo->mAccount = cgMsg.account();
        pPlayerInfo->mPlayerId = cgMsg.user_id();

        mPlayerLinkInfo.AddElement(pPlayerInfo->mPlayerId, pPlayerInfo);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create player:{} link:{}............", pPlayerInfo->mPlayerId, unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->mPlayerId, unLinkId);
    }
    else {
        if (pPlayerInfo->mLinkId > 0 && pPlayerInfo->mLinkId != unLinkId) {
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerInfo->mLinkId);
            if (pOtherInfo) {
                proto_login::Proto_SCKetPlayerNotify kitMsg;
                kitMsg.set_result(proto_ff::ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT);
                NFMessageMgr::Instance()->Send(pPlayerInfo->mLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

                pOtherInfo->mPlayerId = 0;
            }
            NFMessageMgr::Instance()->CloseLinkId(pPlayerInfo->mLinkId);
        }

        pPlayerInfo->mLinkId = unLinkId;
        pPlayerInfo->mIPAddr = pLinkInfo->mIPAddr;
        pPlayerInfo->mIsLogin = true;
        pPlayerInfo->mAccount = cgMsg.account();
        pPlayerInfo->mPlayerId = cgMsg.user_id();

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo->mPlayerId, unLinkId);
    }

    pPlayerInfo->mOnline = true;

    pLinkInfo->mPlayerId = cgMsg.user_id();

    if (pPlayerInfo->mWorldBusId == 0) {
        auto pServerData = NFMessageMgr::Instance()->GetFirstServerByServerType(NF_ST_PROXY_SERVER,
            NF_ST_WORLD_SERVER);
        if (pServerData) {
            pPlayerInfo->mWorldBusId = pServerData->mServerInfo.bus_id();
        }
        else {
            NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get World Bus Id Failed!");
        }
    }

    proto_ff::Proto_PTWUserLoginReq loginReq;
    loginReq.set_user_id(pPlayerInfo->mPlayerId);
    loginReq.set_account(pPlayerInfo->mAccount);
    loginReq.set_client_ip(pLinkInfo->mIPAddr);
    loginReq.mutable_ext_data()->CopyFrom(cgMsg.ext_data());

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        loginReq.set_proxy_bus_id(pConfig->mBusId);
    }

    NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mWorldBusId,
                                                   proto_ff::NF_PTW_PLAYER_LOGIN_MSG, loginReq,
                                                   pPlayerInfo->mPlayerId);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleAccountRegisterFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CSRegisterAccountReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);

    auto pServerData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, cgMsg.account());
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();

        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, loginId, nMsgId, cgMsg, unLinkId);
    } else {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get Login Server Bus Id Failed");
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleLoginServerPhoneAutoCodeFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_LoginServer_PhoneAutoCodeReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string account = NFCommon::tostr(cgMsg.phone_num());

    auto pServerData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, account);
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();

        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, loginId, nMsgId, cgMsg, unLinkId);
    } else {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get Login Server Bus Id Failed");
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleAccountLoginFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CSAccountLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);

    auto pServerData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                  NF_ST_LOGIN_SERVER, cgMsg.account());
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();

        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, loginId, nMsgId, cgMsg, unLinkId);
    } else {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get Login Server Bus Id Failed");
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleLoginServerPhoneAutoCodeFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_SC_LoginServer_PhoneAutoCodeRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    uint64_t clientLinkId = value;
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
        return 0;
    }

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
};

int NFCProxyClientModule::OnHandleAccountRegisterFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_SCRegisterAccountRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    uint64_t clientLinkId = value;
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
        return 0;
    }

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleAccountLoginFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
	proto_login::Proto_SCAccountLoginRsp gcMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

	uint64_t clientLinkId = value;
	NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
	if (pLinkInfo == nullptr)
	{
		NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
		return 0;
	}

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyClientModule::OnHandleLoginRspFromWorldServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId,
                                                          const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_WTPPlayerLoginRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerLinkInfo = mPlayerLinkInfo.GetElement(xMsg.user_id());
    CHECK_PLAYER_EXPR(xMsg.user_id(), pPlayerLinkInfo, -1,
                      "Player:{} login rsp form world server failed, can't find playerinfo in the proxy server",
                      xMsg.user_id());

    pPlayerLinkInfo->mIsLogin = true;
    pPlayerLinkInfo->mGameId = xMsg.game_id();
    pPlayerLinkInfo->mRoomId = xMsg.room_id();
    pPlayerLinkInfo->mGameBusId = xMsg.game_bus_id();
    pPlayerLinkInfo->mLogicBusId = xMsg.logic_bus_id();

    NF_SHARE_PTR<NFServerData> pLogicServer = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, pPlayerLinkInfo->mLogicBusId);
    if (pLogicServer == NULL || pLogicServer->mUnlinkId <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->mPlayerId, "proxy donot connect logic server:{}",pPlayerLinkInfo->mLogicBusId);
    }

    proto_login::Proto_SCUserLoginRsp rspMsg;
    rspMsg.set_result(xMsg.result());
	rspMsg.set_user_id(xMsg.user_id());
    if (xMsg.result() == 0)
    {
        rspMsg.mutable_detail_data()->CopyFrom(xMsg.detail_data());
    }

    NFMessageMgr::Instance()->Send(pPlayerLinkInfo->mLinkId, proto_login::NF_SC_MSG_UserLoginRsp, rspMsg);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleReconnectRspFromWorldServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_ff::NotifyPlayerReconnctRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerLinkInfo = mPlayerLinkInfo.GetElement(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayerLinkInfo, -1,
                      "Player:{} reconnect rsp form wolrd server failed, can't find playerinfo in the proxy server, playerId:{}",
                      xMsg.player_id(), xMsg.player_id());

    pPlayerLinkInfo->mIsLogin = true;
    pPlayerLinkInfo->mGameId = xMsg.game_id();
    pPlayerLinkInfo->mRoomId = xMsg.room_id();
    pPlayerLinkInfo->mGameBusId = xMsg.game_bus_id();
    pPlayerLinkInfo->mLogicBusId = xMsg.logic_bus_id();

    NF_SHARE_PTR<NFServerData> pLogicServer = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, pPlayerLinkInfo->mLogicBusId);
    if (pLogicServer == NULL || pLogicServer->mUnlinkId <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayerLinkInfo->mPlayerId, "proxy donot connect logic server:{}",pPlayerLinkInfo->mLogicBusId);
    }

    proto_login::Proto_SCReconnectRsp gcMsg;
    gcMsg.set_result(xMsg.result());
    NFMessageMgr::Instance()->Send(pPlayerLinkInfo->mLinkId, proto_login::NF_SC_Msg_ReConnect_RSP, gcMsg, xMsg.player_id());
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleClientRspFromWorldServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");


	uint64_t clientPlayerId = value;
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientPlayerId = {}", clientPlayerId);
	
	NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(clientPlayerId);
	if (pPlayerInfo == nullptr || !pPlayerInfo->mIsLogin) 
	{
		NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientPlayerId:{} not login, recv msg:{}", clientPlayerId, nMsgId);
		return 0;
	}

	NFMessageMgr::Instance()->Send(pPlayerInfo->mLinkId, nMsgId, msg, nLen, 0);

	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyClientModule::OnHandleReconnectFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg,
                                                  uint32_t nLen) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CSReconnectReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerLinkInfo = mPlayerLinkInfo.GetElement(cgMsg.userid());
    if (pPlayerLinkInfo == nullptr) {
        NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, cgMsg.userid(), "Player:{} reconnect proxy server, reconnect failed!",
                  cgMsg.userid());
        proto_login::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(-1);
        NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->mIsLogin == false)
    {
        NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, cgMsg.userid(), "Player:{} reconnect proxy server, islogin == false, reconnect failed!",
                  cgMsg.userid());
        proto_login::Proto_SCReconnectRsp gcMsg;
        gcMsg.set_result(-1);
        NFMessageMgr::Instance()->Send(unLinkId, proto_login::NF_SC_Msg_ReConnect_RSP, gcMsg, cgMsg.userid());
        return 0;
    }

    if (pPlayerLinkInfo->mLinkId > 0) {
        if (pPlayerLinkInfo->mLinkId == unLinkId) {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, cgMsg.userid(),
                      "Player:{} reconnect proxy server, but unlink not change! some wrong!", cgMsg.userid());
        } else {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, cgMsg.userid(), "Player:{} reconnect proxy server, but unlink exist",
                      cgMsg.userid());
            auto pOtherInfo = mClientLinkInfo.GetElement(pPlayerLinkInfo->mLinkId);
            if (pOtherInfo) {
                proto_login::Proto_SCKetPlayerNotify kitMsg;
                kitMsg.set_result(proto_ff::ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT);
                NFMessageMgr::Instance()->Send(pPlayerLinkInfo->mLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

                //disconnect, but new connect first, close old connect
                pOtherInfo->mPlayerId = 0;
                NFMessageMgr::Instance()->CloseLinkId(pPlayerLinkInfo->mLinkId);
            }
        }
    }

    pPlayerLinkInfo->mLinkId = unLinkId;
	pPlayerLinkInfo->mIPAddr = ip;
    pPlayerLinkInfo->mOnline = true;

    pLinkInfo->mPlayerId = pPlayerLinkInfo->mPlayerId;
    pLinkInfo->mIPAddr = ip;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} reconnect success!", pPlayerLinkInfo->mPlayerId);

    proto_ff::NotifyPlayerReconnectReq reconnectReq;
    reconnectReq.set_player_id(pPlayerLinkInfo->mPlayerId);
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    {
        reconnectReq.set_proxy_bus_id(pConfig->mBusId);
    }
    NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerLinkInfo->mWorldBusId,
                                                   proto_ff::NF_PTW_PLAYER_RECONNECT_MSG, reconnectReq,
                                                   pPlayerLinkInfo->mPlayerId);
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleClientDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo) {
        if (pLinkInfo->mPlayerId > 0) {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->mPlayerId);
            if (pPlayerInfo) {
                pPlayerInfo->mLinkId = 0;
                pPlayerInfo->mGameId = 0;
                pPlayerInfo->mRoomId = 0;
                pPlayerInfo->mGameBusId = 0;
                pPlayerInfo->mLogicBusId = 0;
                pPlayerInfo->mOnline = false;
                pPlayerInfo->mDisconnectTime = NFTime::Now().UnixSec();

                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} link:{} disconenct.........", pLinkInfo->mPlayerId, unLinkId);

                proto_ff::NotifyPlayerDisconnect xMsg;
                xMsg.set_player_id(pPlayerInfo->mPlayerId);

                if (pPlayerInfo->mWorldBusId > 0) {
                    NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mWorldBusId,
                                                                   proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG,
                                                                   xMsg, pLinkInfo->mPlayerId);
                }
            }
		}
		mClientLinkInfo.RemoveElement(unLinkId);
	}

	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyClientModule::OnHandleOtherServerOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t busId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    auto pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, busId);
    if (pServerData)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, playerId, "proxy trans other server:{} msg:{} to client", pServerData->mServerInfo.server_name(), nMsgId);
        NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
        if (pPlayerInfo)
        {
            NFMessageMgr::Instance()->Send(pPlayerInfo->mLinkId, nMsgId, msg, nLen, 0);
        }
        else
        {
            NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "other server msg:{} not handle", nMsgId);
        }
    }

	return 0;
}

int NFCProxyClientModule::OnHandleChangePasswordFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_ChangePasswordReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    auto pServerData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, cgMsg.account());
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();

        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, loginId, nMsgId, cgMsg, unLinkId);
    } else {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get Login Server Bus Id Failed");
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleLoginServerCheckPhoneCodeFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_LoginServer_CheckPhoneCodeReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, cgMsg);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    CHECK_NULL(pLinkInfo);

    std::string account = NFCommon::tostr(cgMsg.phone_num());

    auto pServerData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_PROXY_SERVER,
                                                                                 NF_ST_LOGIN_SERVER, account);
    if (pServerData)
    {
        uint32_t loginId = pServerData->mServerInfo.bus_id();

        NFMessageMgr::Instance()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, loginId, nMsgId, cgMsg, unLinkId);
    } else {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "Get Login Server Bus Id Failed");
    }
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleNotifyPhoneCheckFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_SC_LoginServer_NotifyPhoneCheck gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    uint64_t clientLinkId = value;
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
        return 0;
    }

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleChangePasswordFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_SC_ChangePasswordRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    uint64_t clientLinkId = value;
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
        return 0;
    }

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleLoginServerCheckPhoneCodeFromLoginServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    uint64_t clientLinkId = value;
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(clientLinkId);
    if (pLinkInfo == nullptr)
    {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "clientLinkId:{} not exist, client maybe disconnect!", clientLinkId);
        return 0;
    }

    NFMessageMgr::Instance()->Send(clientLinkId, nMsgId, msg, nLen, 0);

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}