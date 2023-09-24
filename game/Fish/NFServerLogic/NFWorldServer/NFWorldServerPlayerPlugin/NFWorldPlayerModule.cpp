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
#include "Room/NFWorldRoomMgr.h"


NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFFishDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{

    ////////////////game room register//////////////////////////////
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_PTW_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCWorldPlayerModule::OnRpcServicePlayerLogin, true);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                             &NFCWorldPlayerModule::OnRpcServicePlayerReconnect,
                                                                                             true);

    /////////////////////////////////server msg, player disconnect logout////////////////////////////////////////////
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG);
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NF_LTW_PLAYER_LOGOUT_NOTIFY);

    //////////player enter game////////////////////////////////////


    return true;
}

int NFCWorldPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    return 0;
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
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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

int NFCWorldPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_PTWUserLoginReq &request, proto_ff::Proto_WTPPlayerLoginRsp &respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
    if (pPlayerInfo == nullptr)
    {
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
        NF_SHARE_PTR<NFServerData> pLogicData = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                                          pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
        else
        {
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



    if (pPlayerInfo->m_gameId > 0 || pPlayerInfo->m_roomId > 0) {
        auto pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
        if (pRoomInfo && pRoomInfo->m_busId > 0) {
            NFLogWarning(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "Force Player:{} Exit Game, gameid:{} roomId:{}", pPlayerInfo->GetPlayerId(), pPlayerInfo->m_gameId,
                         pPlayerInfo->m_roomId);

            proto_ff::ExitGameReq rpcReq;
            proto_ff::ExitGameRsp rpcRsp;
            int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_CS_MSG_ExitGameReq>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                                      pPlayerInfo->GetLogicId(), rpcReq, rpcRsp,
                                                                                                      pPlayerInfo->GetPlayerId());

            //check ptr
            pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
            CHECK_NULL(pPlayerInfo);
            pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            CHECK_NULL(pRoomInfo);

            //failed
            if (iRet != 0 || rpcRsp.exit_type() != 0)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player login, exit old game:{} room:{} failed", pPlayerInfo->m_gameId, pPlayerInfo->m_roomId)
            }
            else {
                NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player login, exit old game:{} room:{} success", pPlayerInfo->m_gameId, pPlayerInfo->m_roomId)

                pPlayerInfo->m_gameId = 0;
                pPlayerInfo->m_roomId = 0;
                pPlayerInfo->m_gameBusId = 0;
            }
        }
        else
        {
            pPlayerInfo->m_gameId = 0;
            pPlayerInfo->m_roomId = 0;
            pPlayerInfo->m_gameBusId = 0;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "palyerId:{} room error, room not exist, gameId:{}, roomId:{}", pPlayerInfo->GetPlayerId(),
                       pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
        }
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
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTL_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                                pPlayerInfo->GetLogicId(), reqLogicMsg, rspLogicMsg);
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
    reqSnsMsg.set_create_player_db_data(rspLogicMsg.create_player_db_data());
    *reqSnsMsg.mutable_detail_data() = *rspLogicMsg.mutable_detail_data();
    proto_ff::Proto_STWLoginRsp rspSnsMsg;
    iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTS_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, NF_ST_SNS_SERVER, 0, reqSnsMsg,
                                                                                            rspSnsMsg);
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
        respone.set_game_bus_id(pPlayerInfo->m_gameBusId);
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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::OnRpcServicePlayerReconnect(proto_ff::PTWPlayerReconnectReq &request, proto_ff::WTPPlayerReconnctRsp &respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (!pPlayerInfo)
    {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
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
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                                        pPlayerInfo->GetLogicId(), logicReqMsg,
                                                                                                        logicRspMsg);
    //check ptr
    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    CHECK_NULL(pPlayerInfo);

    if (iRet != 0 || logicRspMsg.result() != 0)
    {
        if (iRet != 0)
        {
            respone.set_result(iRet);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ Failed! iRet:{}", GetErrorStr(iRet));
        }
        else {
            respone.set_result(logicRspMsg.result());
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ Failed! logicRspMsg.result:{}",
                       GetErrorStr(logicRspMsg.result()));
        }
        if (pPlayerInfo->m_gameId > 0 || pPlayerInfo->m_roomId > 0) {
            NFWorldRoom *pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            if (pRoomInfo && pRoomInfo->m_busId > 0) {
                NFLogWarning(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "Force Player:{} Exit Game, gameid:{} roomId:{}", pPlayerInfo->GetPlayerId(), pPlayerInfo->m_gameId,
                             pPlayerInfo->m_roomId);

                proto_ff::ExitGameReq rpcReq;
                proto_ff::ExitGameRsp rpcRsp;
                iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_CS_MSG_ExitGameReq>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                                      pPlayerInfo->GetLogicId(), rpcReq, rpcRsp,
                                                                                                      pPlayerInfo->GetPlayerId());

                //check ptr
                pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
                CHECK_NULL(pPlayerInfo);
                pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
                CHECK_NULL(pRoomInfo);

                //failed
                if (iRet != 0 || rpcRsp.exit_type() != 0)
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player login, exit old game:{} room:{} failed", pPlayerInfo->m_gameId, pPlayerInfo->m_roomId)
                }
                else {
                    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player login, exit old game:{} room:{} success", pPlayerInfo->m_gameId, pPlayerInfo->m_roomId)

                    pPlayerInfo->m_gameId = 0;
                    pPlayerInfo->m_roomId = 0;
                    pPlayerInfo->m_gameBusId = 0;
                }
            } else {
                pPlayerInfo->m_gameId = 0;
                pPlayerInfo->m_roomId = 0;
                pPlayerInfo->m_gameBusId = 0;
                NFLogError(NF_LOG_SYSTEMLOG, 0, "palyerId:{} room error, room not exist, gameId:{}, roomId:{}", pPlayerInfo->GetPlayerId(),
                           pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            }
        }
        return 0;
    }

    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    if (!pPlayerInfo)
    {
        respone.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    proto_ff::WTSPlayerReconnectReq snsReqMsg;
    snsReqMsg.set_player_id(pPlayerInfo->GetPlayerId());
    snsReqMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    snsReqMsg.set_logic_bus_id(pPlayerInfo->GetLogicId());
    proto_ff::STWPlayerReconnectRsp snsRspMsg;
    iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ>(NF_ST_WORLD_SERVER, NF_ST_SNS_SERVER, 0,
                                                                                                    snsReqMsg, snsRspMsg);
    //check ptr
    pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.player_id());
    CHECK_NULL(pPlayerInfo);

    if (iRet != 0)
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    if (snsRspMsg.result() != 0)
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        respone.set_result(snsRspMsg.result());
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ Failed! snsRspMsg.result:{}",
                   GetErrorStr(snsRspMsg.result()));
        return 0;
    }

    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);

    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerInfo->GetPlayerId(), "player:{} reconnect success", pPlayerInfo->GetPlayerId());

    respone.set_result(0);
    respone.set_player_id(pPlayerInfo->GetPlayerId());
    respone.set_logic_bus_id(pPlayerInfo->GetLogicId());

    respone.set_game_id(pPlayerInfo->m_gameId);
    respone.set_room_id(pPlayerInfo->m_roomId);
    respone.set_game_bus_id(pPlayerInfo->m_gameBusId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerDisconnectMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

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
        FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId(),
                                                                   proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG, xMsg);
    }

    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, proto_ff::NF_WTS_PLAYER_DISCONNECT_MSG, xMsg);

    if (pPlayerInfo->m_gameId > 0 && pPlayerInfo->m_roomId > 0) {
        NFWorldRoom *pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
        if (!pRoomInfo) {
            pPlayerInfo->m_gameId = 0;
            pPlayerInfo->m_roomId = 0;
            pPlayerInfo->m_gameBusId = 0;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "palyerId:{} room error, room not exist, gameId:{}, roomId:{}",
                       pPlayerInfo->GetPlayerId(),
                       pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            return -1;
        }

        FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_WORLD_SERVER,
                                                      pRoomInfo->m_busId,
                                                      proto_ff::NF_WTG_PLAYER_DISCONNECT_MSG, xMsg);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandlePlayerLogoutNotify(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_LTWLogoutNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(xMsg.player_id());
    if (pPlayerInfo)
    {
        if (pPlayerInfo->GetStatus() != proto_ff::PLAYER_STATUS_LOGOUT)
        {
            pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            pPlayerInfo->SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, xMsg.player_id(), "logic notify world server logout, player:{} status:{} change to PLAYER_STATUS_LOGOUT",
                      xMsg.player_id(), pPlayerInfo->GetStatusName());
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, xMsg.player_id(), "logic notify world server, player:{} logout..............", xMsg.player_id());

    NotifySnsPlayerLogout(xMsg.player_id());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
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

