// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/ResMeta.pb.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIWorldPlayerModule(p) {

}

NFCWorldPlayerModule::~NFCWorldPlayerModule() {
}

bool NFCWorldPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_PTW_PLAYER_LOGIN_MSG, this,
                                                       &NFCWorldPlayerModule::OnHandlePlayerLogin);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_PLAYER_LOGIN_RSP, this,
                                                       &NFCWorldPlayerModule::OnHandleLogicServerLoginRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_PTW_PLAYER_RECONNECT_MSG, this,
                                                       &NFCWorldPlayerModule::OnHandlePlayerReconnect);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_PLAYER_RECONNECT_MSG_RSP, this,
                                                       &NFCWorldPlayerModule::OnHandleLogicServerReconnectRsp);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG, this,
                                                       &NFCWorldPlayerModule::OnHandlePlayerDisConnect);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_WORLD_ROUTER_CMD_TO_SUIT_LOGIC, this,
                                                    &NFCWorldPlayerModule::OnHandleRouteToSuitLogicServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_REGISTER_USER_TO_WORLD_REQ, this,
                                                       &NFCWorldPlayerModule::OnHandleRegisterUserFromLoginServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_PLAYER_LOGOUT_REQ, this,
                                                 &NFCWorldPlayerModule::OnHandleLogoutUserFromLoginServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY, this,
                                                 &NFCWorldPlayerModule::OnHnadleChangeDeviceFromLoginServer);

    return true;
}

bool NFCWorldPlayerModule::Execute()
{
	return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
	return true;
}

int NFCWorldPlayerModule::OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t proxyBusId, uint32_t nMsgId, const char *msg,
                                              uint32_t nLen) {
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_PTWUserLoginReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.user_id());
    if (pPlayerInfo == nullptr) {
        if (NFWorldPlayer::GetFreeCount() > 0)
        {
            pPlayerInfo = NFWorldPlayerMgr::GetInstance()->CreatePlayer(xMsg.user_id());
            if (pPlayerInfo == NULL)
            {
                proto_ff::Proto_WTPPlayerLoginRsp rspMsg;
                rspMsg.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);

                NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, xMsg.proxy_bus_id(),
                                                               proto_ff::NF_WTP_PLAYER_LOGIN_MSG_RSP, rspMsg,
                                                               xMsg.user_id());

                NFLogError(NF_LOG_SYSTEMLOG, xMsg.user_id(), "CreatePlayer Failed!, user id:{} Login Failed!", xMsg.user_id());
                return 0;
            }
        }
        else
        {
            proto_ff::Proto_WTPPlayerLoginRsp rspMsg;
            rspMsg.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, xMsg.proxy_bus_id(),
                                                           proto_ff::NF_WTP_PLAYER_LOGIN_MSG_RSP, rspMsg,
                                                           xMsg.user_id());

            NFLogError(NF_LOG_SYSTEMLOG, xMsg.user_id(), "player online count than max player count, user id:{} Login Failed!", xMsg.user_id());
            return 0;
        }
    }
    CHECK_NULL(pPlayerInfo);

    if (proxyBusId != xMsg.proxy_bus_id())
    {
        NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, xMsg.user_id(),
                   "playerId:{} login world server , busid is not right, busid:{} != busid:{}", xMsg.user_id(),
                   proxyBusId, xMsg.proxy_bus_id());

        xMsg.set_proxy_bus_id(proxyBusId);
    }

    pPlayerInfo->SetPlayerId(xMsg.user_id());
    pPlayerInfo->SetProxyId(proxyBusId);
    pPlayerInfo->SetStatus(PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
    }

	//notify logic server player login
	proto_ff::Proto_WorldToLogicLoginReq rspLogicMsg;
	rspLogicMsg.set_user_id(pPlayerInfo->GetPlayerId());
	rspLogicMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
	rspLogicMsg.mutable_ext_data()->CopyFrom(xMsg.ext_data());
	rspLogicMsg.set_client_ip(xMsg.client_ip());

	NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), proto_ff::NF_WTL_PLAYER_LOGIN_REQ, rspLogicMsg);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleLogicServerReconnectRsp(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTWNotifyPlayerReconnectRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    uint32_t logicBusId = GetServerIndexFromUnlinkId(value);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.player_id());
    CHECK_NULL(pPlayerInfo);
    if (pPlayerInfo->GetLogicId() != logicBusId)
    {
        pPlayerInfo->SetLogicId(logicBusId);
        NFLogError(NF_LOG_SYSTEMLOG, xMsg.player_id(), "pPlayerInfo->m_logicId:{} != logicBusId:{}", pPlayerInfo->GetLogicId(), logicBusId);
    }

    proto_ff::NotifyPlayerReconnctRsp rspMsg;
    if (xMsg.result() != 0)
    {
        pPlayerInfo->SetStatus(PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        NFLogError(NF_LOG_SYSTEMLOG, xMsg.player_id(), "player reconnect logic server failed!");
        rspMsg.set_result(xMsg.result());
    }
    else
    {
        pPlayerInfo->SetStatus(PLAYER_STATUS_ONLINE);

        rspMsg.set_result(0);
        rspMsg.set_player_id(pPlayerInfo->GetPlayerId());
        rspMsg.set_logic_bus_id(pPlayerInfo->GetLogicId());
    }

    NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(),
                                                         proto_ff::NF_WTP_PLAYER_RECONNECT_MSG_RSP, rspMsg,
                                                         pPlayerInfo->GetPlayerId());

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleLogicServerLoginRsp(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::Proto_LogicToWorldLoginRsp xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

	uint32_t logicBusId = GetServerIndexFromUnlinkId(value);

	NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.user_id());
	CHECK_NULL(pPlayerInfo);
    if (pPlayerInfo->GetLogicId() != 0 && pPlayerInfo->GetLogicId() != logicBusId)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pPlayerInfo->m_logicId:{} != logicBusId:{}", pPlayerInfo->GetLogicId(), logicBusId);
    }
    pPlayerInfo->SetLogicId(logicBusId);

	proto_ff::Proto_WTPPlayerLoginRsp rspMsg;
    if (xMsg.result() == 0)
    {
        pPlayerInfo->SetStatus(PLAYER_STATUS_ONLINE);

        rspMsg.set_result(0);
        rspMsg.set_user_id(pPlayerInfo->GetPlayerId());
        rspMsg.set_logic_bus_id(pPlayerInfo->GetLogicId());
        rspMsg.mutable_detail_data()->CopyFrom(xMsg.detail_data());
    }
    else
    {
        pPlayerInfo->SetStatus(PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        rspMsg.set_user_id(pPlayerInfo->GetPlayerId());
        rspMsg.set_result(xMsg.result());
    }

    if (pPlayerInfo->GetProxyId() > 0)
    {
        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(),
                                                       proto_ff::NF_WTP_PLAYER_LOGIN_MSG_RSP, rspMsg,
                                                       pPlayerInfo->GetPlayerId());
    }

	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t proxyBusId, uint32_t nMsgId, const char *msg,
                                                  uint32_t nLen) {
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::NotifyPlayerReconnectReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.player_id());
    if (!pPlayerInfo) {
		proto_ff::NotifyPlayerReconnctRsp rspMsg;
		rspMsg.set_result(-1);
		NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, xMsg.proxy_bus_id(),
			proto_ff::NF_WTP_PLAYER_RECONNECT_MSG_RSP, rspMsg,
			xMsg.player_id());
		return 0;
    }

    if (proxyBusId!= xMsg.proxy_bus_id()) {
        NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, xMsg.player_id(),
                   "playerId:{} reconnct world server , busid is not right, busid:{} != busid:{}", xMsg.player_id(),
                   proxyBusId, xMsg.proxy_bus_id());

        xMsg.set_proxy_bus_id(proxyBusId);
    }

    pPlayerInfo->SetProxyId(proxyBusId);
    pPlayerInfo->SetStatus(PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        proto_ff::NotifyPlayerReconnctRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(),
                                                             proto_ff::NF_WTP_PLAYER_RECONNECT_MSG_RSP, rspMsg,
                                                             pPlayerInfo->GetPlayerId());
        return 0;
    }

    proto_ff::WTLNotifyPlayerReconnectReq rspMsg;
    rspMsg.set_player_id(pPlayerInfo->GetPlayerId());
    rspMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());

    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), proto_ff::NF_WTL_PLAYER_RECONNECT_MSG,
                                                    rspMsg);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg,
                                                   uint32_t nLen) {
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayerInfo, -1, "disconnect, can't find player pInfo, playerId:{}",
                     xMsg.player_id());

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, xMsg.player_id(), "userid:{} disconnect..............", xMsg.player_id());

    pPlayerInfo->SetProxyId(0);
    pPlayerInfo->SetStatus(PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() > 0)
    {
        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG, xMsg);
    }

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleRouteToSuitLogicServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.disp_info().user_id());
    if (pPlayerInfo == NULL)
    {
        pPlayerInfo = NFWorldPlayerMgr::GetInstance()->CreatePlayer(xMsg.disp_info().user_id());
        CHECK_PLAYER_EXPR(xMsg.disp_info().user_id(), pPlayerInfo, -1, "playerHashTable Create Player Failed! playerId:{}",
                          xMsg.disp_info().user_id());
    }

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = NFMessageMgr::Instance()->GetFirstServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER);
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
    }

    if (pPlayerInfo->GetLogicId() > 0)
    {
        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), xMsg.msg_id(), xMsg.msg_data().data(), xMsg.msg_data().length());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, xMsg.disp_info().user_id(), "route msg faled, can't find logic!");
    }

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHnadleChangeDeviceFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTLPlayerDeviceChangeNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, loginLinkId, msg, nLen, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.user_id());

    if (pPlayerInfo == NULL)
    {
        pPlayerInfo = NFWorldPlayerMgr::GetInstance()->CreatePlayer(xMsg.user_id());
        CHECK_PLAYER_EXPR(xMsg.user_id(), pPlayerInfo, -1, "playerHashTable Create Player Failed! playerId:{}",
                          xMsg.user_id());
    }

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
    }

    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), nMsgId, xMsg);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleRegisterUserFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_LTWRegisterUserReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, loginLinkId, msg, nLen, xMsg);

    uint32_t loginBusId = GetServerIndexFromUnlinkId(loginLinkId);
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.user_id());
    CHECK_NULL(pPlayerInfo == NULL);

    pPlayerInfo = NFWorldPlayerMgr::GetInstance()->CreatePlayer(xMsg.user_id());
    if (pPlayerInfo == NULL)
    {
        proto_ff::Proto_LTLRegisterUserRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_user_id(xMsg.user_id());

        NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_WORLD_SERVER, loginBusId, proto_ff::NF_LTL_REGISTER_USER_TO_LOGIN_RSP, rspMsg, 0, reqTransId);
    }

    CHECK_PLAYER_EXPR(xMsg.user_id(), pPlayerInfo, -1, "playerHashTable Create Player Failed! playerId:{}",
                      xMsg.user_id());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = NFMessageMgr::Instance()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
    }

    proto_ff::Proto_WTLRegisterUserReq reqMsg;
    reqMsg.set_user_id(xMsg.user_id());
    reqMsg.set_nick_name(xMsg.nick_name());
    reqMsg.set_phone_num(xMsg.phone_num());
    reqMsg.mutable_ext_data()->CopyFrom(xMsg.ext_data());
    reqMsg.set_login_bus_id(loginBusId);
    reqMsg.set_req_trans_id(reqTransId);

    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ, reqMsg);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}



int NFCWorldPlayerModule::OnHandleLogoutUserFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_LogicToWorldLogoutReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, loginLinkId, msg, nLen, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance()->GetPlayer(xMsg.player_id());
    if (pPlayerInfo)
    {
        if (pPlayerInfo->GetStatus() < PLAYER_STATUS_LOGOUT)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player:{} status:{} change to PLAYER_STATUS_LOGOUT", pPlayerInfo->GetPlayerId(), pPlayerInfo->GetStatus());
            pPlayerInfo->SetStatus(PLAYER_STATUS_LOGOUT);
            pPlayerInfo->SetLastLogtouTime(NFTime::Now().UnixSec());
        }
    }

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

