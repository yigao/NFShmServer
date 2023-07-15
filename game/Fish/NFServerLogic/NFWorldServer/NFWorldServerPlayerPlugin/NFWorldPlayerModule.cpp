// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerModule.h"

#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "ServerInternalCmd.pb.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCWorldPlayerModule::~NFCWorldPlayerModule() {
}

bool NFCWorldPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_PTW_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCWorldPlayerModule::OnRpcServicePlayerLogin, true);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCWorldPlayerModule::OnRpcServicePlayerReconnect, true);

    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG);
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_PLAYER_LOGOUT_NOTIFY);

    //////////player enter game////////////////////////////////////
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

int NFCWorldPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
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
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCWorldPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
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
        case proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG:
        {
            OnHandlePlayerDisconnectMsg(unLinkId, packet);
            break;
        }
        case proto_ff::NF_LTW_PLAYER_LOGOUT_NOTIFY:
        {
            OnHandlePlayerLogoutNotify(unLinkId, packet);
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

int NFCWorldPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_PTWUserLoginReq& request, proto_ff::Proto_WTPPlayerLoginRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
    if (pPlayerInfo == nullptr) {
        if (NFWorldPlayer::GetFreeCount(m_pObjPluginManager) > 0)
        {
            pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->CreatePlayer(request.user_id());
            if (pPlayerInfo == NULL)
            {
                respone.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);
                NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "CreatePlayer Failed!, user id:{} Login Failed!", respone.user_id());
                return 0;
            }
        }
        else
        {
            respone.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);

            NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "player online count than max player count, user id:{} Login Failed!", request.user_id());
            return 0;
        }
    }
    CHECK_NULL(pPlayerInfo);

    pPlayerInfo->SetPlayerId(request.user_id());
    pPlayerInfo->SetProxyId(request.proxy_bus_id());
    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
        else {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

            NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "can't find the logic server, user id:{} Login Failed! ", request.user_id());
            return 0;
        }
    }

    if (pPlayerInfo->GetLogicId() <= 0 || FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId()) == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

        NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "can't find the logic server, user id:{} Login Failed! ", request.user_id());
        return 0;
    }

    //notify logic server player login
    proto_ff::Proto_WorldToLogicLoginReq reqLogicMsg;
    reqLogicMsg.set_user_id(pPlayerInfo->GetPlayerId());
    reqLogicMsg.set_game_id(pPlayerInfo->m_gameId);
    reqLogicMsg.set_room_id(pPlayerInfo->m_roomId);
    reqLogicMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    reqLogicMsg.mutable_ext_data()->CopyFrom(request.ext_data());
    reqLogicMsg.set_client_ip(request.client_ip());

    proto_ff::Proto_LogicToWorldLoginRsp rspLogicMsg;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTL_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetLogicId(), reqLogicMsg, rspLogicMsg);
    if (iRet != 0)
    {
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_LOGIN_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    proto_ff::Proto_WTSLoginReq reqSnsMsg;
    reqSnsMsg.set_user_id(pPlayerInfo->GetPlayerId());
    reqSnsMsg.set_game_id(pPlayerInfo->m_gameId);
    reqSnsMsg.set_room_id(pPlayerInfo->m_roomId);
    reqSnsMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    reqSnsMsg.set_client_ip(request.client_ip());
    reqSnsMsg.set_logic_bus_id(pPlayerInfo->GetLogicId());
    *reqSnsMsg.mutable_sns_sync() = rspLogicMsg.sns_sync();
    proto_ff::Proto_STWLoginRsp rspSnsMsg;
    iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTS_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, NF_ST_SNS_SERVER, 0, reqSnsMsg, rspSnsMsg);
    if (iRet != 0)
    {
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_LOGIN_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    /**
     * @brief must find playerInfo again, the playerinfo maybe not exist
     */
    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
    if (pPlayerInfo == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the player after the rpc");
        return 0;
    }

    if (rspLogicMsg.result() == 0)
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);

        respone.set_result(0);
        respone.set_user_id(pPlayerInfo->GetPlayerId());
        respone.set_game_id(pPlayerInfo->m_gameId);
        respone.set_room_id(pPlayerInfo->m_roomId);
        respone.set_logic_bus_id(pPlayerInfo->GetLogicId());
        respone.mutable_detail_data()->CopyFrom(rspLogicMsg.detail_data());
    }
    else
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        respone.set_user_id(pPlayerInfo->GetPlayerId());
        respone.set_result(rspLogicMsg.result());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnRpcServicePlayerReconnect(proto_ff::PTWPlayerReconnectReq& request, proto_ff::WTPPlayerReconnctRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (!pPlayerInfo) {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    if (pPlayerInfo->GetProxyId() != request.proxy_bus_id())
    {

    }

    pPlayerInfo->SetProxyId(request.proxy_bus_id());
    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    proto_ff::WTLPlayerReconnectReq logicReqMsg;
    logicReqMsg.set_player_id(pPlayerInfo->GetPlayerId());
    logicReqMsg.set_game_id(pPlayerInfo->m_gameId);
    logicReqMsg.set_room_id(pPlayerInfo->m_roomId);
    logicReqMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    proto_ff::LTWPlayerReconnectRsp logicRspMsg;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetLogicId(), logicReqMsg, logicRspMsg);
    if (iRet != 0)
    {
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (logicRspMsg.result() != 0)
    {
        respone.set_result(logicRspMsg.result());
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ Failed! logicRspMsg.result:{}", GetErrorStr(logicRspMsg.result()));
        return 0;
    }

    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (!pPlayerInfo) {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    proto_ff::WTSPlayerReconnectReq snsReqMsg;
    snsReqMsg.set_player_id(pPlayerInfo->GetPlayerId());
    snsReqMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    snsReqMsg.set_logic_bus_id(pPlayerInfo->GetLogicId());
    proto_ff::STWPlayerReconnectRsp snsRspMsg;
    iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, NF_ST_SNS_SERVER, 0, snsReqMsg, snsRspMsg);
    if (iRet != 0)
    {
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (snsRspMsg.result() != 0)
    {
        respone.set_result(snsRspMsg.result());
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ Failed! snsRspMsg.result:{}", GetErrorStr(snsRspMsg.result()));
        return 0;
    }

    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (!pPlayerInfo) {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);

    respone.set_result(0);
    respone.set_player_id(pPlayerInfo->GetPlayerId());
    respone.set_game_id(pPlayerInfo->m_gameId);
    respone.set_room_id(pPlayerInfo->m_roomId);
    respone.set_logic_bus_id(pPlayerInfo->GetLogicId());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerDisconnectMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayerInfo, -1, "disconnect, can't find player pInfo, playerId:{}",
                      xMsg.player_id());

    NFLogInfo(NF_LOG_SYSTEMLOG, xMsg.player_id(), "player:{} disconnect..............", xMsg.player_id());

    pPlayerInfo->SetProxyId(0);
    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() > 0)
    {
        FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(), proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG, xMsg);
    }

    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, proto_ff::NF_WTS_PLAYER_DISCONNECT_MSG, xMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerLogoutNotify(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_LTWLogoutNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(xMsg.player_id());
    if (pPlayerInfo)
    {
        if (pPlayerInfo->GetStatus() != proto_ff::PLAYER_STATUS_LOGOUT)
        {
            pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            pPlayerInfo->SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, xMsg.player_id(), "logic notify world server logout, player:{} status:{} change to PLAYER_STATUS_LOGOUT", xMsg.player_id(), pPlayerInfo->GetStatusName());
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, xMsg.player_id(), "logic notify world server, player:{} logout..............", xMsg.player_id());

    NotifySnsPlayerLogout(xMsg.player_id());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::NotifySnsPlayerLogout(uint64_t playerId)
{
    proto_ff::Proto_WTSLogoutNotify notify;
    notify.set_player_id(playerId);
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, proto_ff::NF_WTS_PLAYER_LOGOUT_NOTIFY, notify);
    return 0;
}

int NFCWorldPlayerModule::NotifyLogicPlayerLogout(uint64_t playerId)
{
    proto_ff::Proto_WTLLogoutNotify notify;
    notify.set_player_id(playerId);
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, proto_ff::NF_WTL_PLAYER_LOGOUT_NOTIFY, notify);
    return 0;
}