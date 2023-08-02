// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomModule
//
// -------------------------------------------------------------------------

#include "NFWorldRoomModule.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "Room/NFWorldRoomMgr.h"

#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "DescStore/RoomRoomDesc.h"

NFWorldRoomModule::NFWorldRoomModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFWorldRoomModule::~NFWorldRoomModule()
{
}

bool NFWorldRoomModule::Awake()
{
    ////////////////game room register//////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_GTW_REGISTER_ROOM_INFO_RPC>(NF_ST_WORLD_SERVER, this,
                                                                                           &NFWorldRoomModule::OnRpcServiceRoomRegister);
    /////////////////////enter game, exit game////////////////////////////////////

    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::NF_CS_MSG_EnterGameReq, true);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::NF_CS_MSG_DeskListReq, true);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::NF_CS_Msg_Get_Room_Info_Req);

    Subscribe(NF_ST_WORLD_SERVER, proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    return true;
}

bool NFWorldRoomModule::Execute()
{
    return NFIModule::Execute();
}

bool NFWorldRoomModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int
NFWorldRoomModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH)
        {
            NFWorldRoomMgr::Instance(m_pObjPluginManager)->CreateRoom();
        }
    }
    return 0;
}

int NFWorldRoomModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
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
        case proto_ff::NF_CS_Msg_Get_Room_Info_Req:
        {
            OnHandleGetRoomInfoReq(msgId, packet, playerId, param2);
            break;
        }
        case proto_ff::NF_CS_MSG_DeskListReq:
        {
            OnHandleDeskListReq(msgId, packet, playerId, param2);
            break;
        }
        case proto_ff::NF_CS_MSG_EnterGameReq:
        {
            OnHandleEnterGameReq(msgId, packet, playerId, param2);
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

int NFWorldRoomModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFWorldRoomModule::OnRpcServiceRoomRegister(proto_ff::Proto_GTW_RegisterRoomInfoReq &request, proto_ff::Proto_WTG_RegisterRoomInfoRsp &respone)
{
    respone.set_result(-1);
    for (int i = 0; i < (int) request.game_size(); i++)
    {
        uint32_t gameId = request.game(i).gameid();
        for (int j = 0; j < (int) request.game(i).roomid_size(); j++)
        {
            uint32_t roomId = request.game(i).roomid(j);
            auto pRoom = NFWorldRoomMgr::Instance(m_pObjPluginManager)->GetRoom(gameId, roomId);
            CHECK_EXPR(pRoom, -1, "room not exist, {} register failed, gameId:{} roomId:{}", NFServerIDUtil::GetBusNameFromBusID(request.bus_id()),
                       gameId, roomId);
            CHECK_EXPR(pRoom->m_busId == 0 || pRoom->m_busId == request.bus_id(), -1, "room has registed, {} register failed, gameId:{} roomId:{}",
                       NFServerIDUtil::GetBusNameFromBusID(request.bus_id()), gameId, roomId);

            pRoom->m_busId = request.bus_id();

            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{} register gameId:{} roomId:{} success", NFServerIDUtil::GetBusNameFromBusID(request.bus_id()), gameId,
                      roomId);
        }
    }

    respone.set_result(0);
    return 0;
}

int NFWorldRoomModule::OnHandleGetRoomInfoReq(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::GetRoomInfoReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayerInfo, -1, "recv nMsgId:{} can't find player pInfo, playerId:{}", msgId,
                      playerId);

    proto_ff::GetRoomInfoRsp rsp;
    rsp.set_result(0);
    for(auto iter = NFWorldRoom::Begin(m_pObjPluginManager); iter != NFWorldRoom::End(m_pObjPluginManager); iter++)
    {
        NFWorldRoom* pRoomInfo = &(*iter);
        if (pRoomInfo && pRoomInfo->m_gameId == xMsg.game_id())
        {
            auto pRoomCfg = RoomRoomDesc::Instance(m_pObjPluginManager)->GetDesc(pRoomInfo->m_id);
            CHECK_EXPR_CONTINUE(pRoomCfg, "RoomRoomDesc Can't find the room:{} config", pRoomInfo->m_id);
            proto_ff::RoomStatusInfo* pProto = rsp.add_rooms();
            pProto->set_game_id((uint32_t)pRoomInfo->m_gameId);
            pProto->set_room_id((uint32_t)pRoomInfo->m_roomId);
            pProto->set_room_name(pRoomCfg->m_roomname.ToString());
            pProto->set_enter_min(pRoomCfg->m_enter_min);
            pProto->set_enter_max(pRoomCfg->m_enter_max);
            if (pRoomInfo->m_busId > 0)
            {
                pProto->set_status(1);
            }
            else
            {
                pProto->set_status(0);
            }
        }
    }

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(), proto_ff::NF_SC_Msg_Get_Room_Info_Rsp, rsp, playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");

    return 0;
}

int NFWorldRoomModule::OnHandleDeskListReq(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::DeskListReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFWorldPlayer *pPlayerInfo = NFWorldPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayerInfo, -1, "recv nMsgId:{} can't find player pInfo, playerId:{}", msgId,
                      playerId);

    if (pPlayerInfo->m_gameId > 0 || pPlayerInfo->m_roomId > 0)
    {
        if (pPlayerInfo->m_gameId != xMsg.game_id() || pPlayerInfo->m_roomId != xMsg.room_id())
        {
            auto pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            if (pRoomInfo && pRoomInfo->m_busId > 0)
            {
                NFLogWarning(NF_LOG_SYSTEMLOG, 0, "Force Player:{} Exit Game, gameid:{} roomId:{}", playerId, pPlayerInfo->m_gameId,
                             pPlayerInfo->m_roomId);
                proto_ff::ExitRoomReq exitMsg;
                FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_WORLD_SERVER,
                                                                          pRoomInfo->m_busId, proto_ff::NF_CS_MSG_ExitGameReq,
                                                                          exitMsg, playerId);
            }
            else
            {
                pPlayerInfo->m_gameId = 0;
                pPlayerInfo->m_roomId = 0;
                NFLogError(NF_LOG_SYSTEMLOG, 0, "palyerId:{} room error, room not exist, gameId:{}, roomId:{}", playerId,
                           pPlayerInfo->m_gameId, pPlayerInfo->m_roomId);
            }
        }
    }

    auto pRoomInfo = NFWorldRoomMgr::GetInstance(m_pObjPluginManager)->GetRoom(xMsg.game_id(), xMsg.room_id());
    if (pRoomInfo)
    {
        if (pRoomInfo->m_busId > 0 && pPlayerInfo->GetLogicId() > 0)
        {
            xMsg.set_game_bus_id(pRoomInfo->m_busId);
            proto_ff::DeskListRsp rspMsg;
            int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetLogicId(), xMsg, rspMsg);
            if (iRet != 0)
            {
                proto_ff::DeskListRsp rspMsg;
                rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
                FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(), proto_ff::NF_SC_MSG_DeskListRsp, rspMsg,
                                                                           pPlayerInfo->GetPlayerId());
                return 0;
            }

            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(), proto_ff::NF_SC_MSG_DeskListRsp, rspMsg,
                                                                       pPlayerInfo->GetPlayerId());
        }
        else
        {
            proto_ff::DeskListRsp rspMsg;
            rspMsg.set_result(proto_ff::ERR_CODE_GAME_ROOM_NOT_ONLINE);
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(), proto_ff::NF_SC_MSG_DeskListRsp, rspMsg,
                                                           pPlayerInfo->GetPlayerId());
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find room for: xMsg.game_id() = {} , xMsg.room_id() = {}", xMsg.game_id(), xMsg.room_id());

        proto_ff::DeskListRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_GAME_ROOM_NOT_EXIST);
        FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayerInfo->GetProxyId(), proto_ff::NF_SC_MSG_DeskListRsp, rspMsg,
                                                       pPlayerInfo->GetPlayerId());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");

    return 0;
}

int NFWorldRoomModule::OnHandleEnterGameReq(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    return 0;
}
