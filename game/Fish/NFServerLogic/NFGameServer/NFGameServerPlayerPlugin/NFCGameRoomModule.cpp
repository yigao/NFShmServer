// -------------------------------------------------------------------------
//    @FileName         :    NFCGameRoomModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGameRoomModule
//
// -------------------------------------------------------------------------

#include "NFCGameRoomModule.h"
#include "Room/NFGameRoomMgr.h"
#include "Player/NFGamePlayerMgr.h"


NFCGameRoomModule::NFCGameRoomModule(NFIPluginManager* p): NFIGameRoomModule(p)
{

}

NFCGameRoomModule::~NFCGameRoomModule()
{
}

bool NFCGameRoomModule::Awake()
{
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleDeskListReq);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_ChairCheckReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleChairCheckReq);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_EnterGameReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleEnterGameReq, true);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_ExitGameReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleExitGameReq);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_ExitRoomReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleExitRoomReq);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_UserRecomeReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleRecomeReq);
    return true;
}

bool NFCGameRoomModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCGameRoomModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCGameRoomModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleDeskListReq(proto_ff::DeskListReq &request, proto_ff::DeskListRsp &respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    auto roomConfig = FishRoomDesc::Instance()->GetDescByGameidRoomid(request.game_id(), request.room_id());
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", request.game_id(), request.room_id());
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    uint32_t autoChairId = roomConfig->m_autoChair;// 1;// 1-显示桌子列表  0-不显示桌子列表

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "======> playerId = {} , autoChairId = {}", playerId, autoChairId);

    NFGameRoom *pRoom = NFGameRoomMgr::Instance(m_pObjPluginManager)->GetGameRoom(request.game_id(), request.room_id());
    CHECK_EXPR(pRoom, -1, "pRoom == NULL for game_id = {} , room_id = {}", request.game_id() , request.room_id());

    NFGamePlayer *pPlayer = NFGamePlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer)
    {
        if (pPlayer->GetGameId() == request.game_id() && pPlayer->GetRoomId() == request.room_id() && pPlayer->GetDeskId() >= 0 && pPlayer->GetChairId() >= 0)
        {
            respone.set_result(0);

            proto_ff::GameDeskInfo* pDeskInfo = respone.add_desks();
            pDeskInfo->set_desk_id(pPlayer->GetDeskId()+1);
            pDeskInfo->set_desk_name("deskName");
            pDeskInfo->set_desk_status(0);
            pDeskInfo->set_chair_count(1);

            //自动选一个座位并保留 todo

            proto_ff::GameChairInfo* pChairInfo = pDeskInfo->add_chairs();
            pChairInfo->set_chair_id(pPlayer->GetChairId()+1);
            pChairInfo->set_chair_status(0);

            return 0;
        }
    }
    else
    {
        if (autoChairId == 0)
        {
            pPlayer = NFGamePlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(playerId);
            CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Create Player Failed, playerId:{}", playerId);

            pPlayer->SetClearFlag(false);
            pPlayer->SetOnline(true);
            pPlayer->SetOfflineTime(0);
            pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());
        }
    }

    pRoom->OnHandleReqDeskList(playerId, autoChairId, respone);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleChairCheckReq(proto_ff::ChairCheckReq& request, proto_ff::ChairCheckRsp& respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    auto roomConfig = FishRoomDesc::Instance()->GetDescByGameidRoomid(request.game_id(), request.room_id());
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, playerId, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", request.game_id(), request.room_id());
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(request.game_id(), request.room_id());
    if (pRoom == NULL)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "gameId:{} roomId:{} not exist, player:{} enter game failed!", request.game_id(), request.room_id(), playerId);

        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    int32_t deskId  = (int32_t) request.desk_id()  /*- 1*/; //客户端传来时就是从1开始
    int32_t chairId = (int32_t) request.chair_id() /*- 1*/; //客户端传来时就是从1开始

    int iRet = pRoom->CheckDeskStation(playerId, deskId, chairId);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, playerId, "CheckDeskStation Failed, deskId:{} chairId:{}", deskId, chairId);
        respone.set_result(proto_ff::ERR_CODE_DESK_NOT_EXIST);
        return 0;
    }

    respone.set_result(0);
    NFLogInfo(NF_LOG_SYSTEMLOG, playerId, "Chair Check Success........");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleEnterGameReq(proto_ff::EnterGameReq& request, proto_ff::EnterGameRsp& respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    uint32_t gameId = request.game_id();
    uint32_t roomId = request.room_id();
    int32_t deskId  = (int32_t) request.desk_id()  /*- 1*/; //客户端传来时就是从1开始
    int32_t chairId = (int32_t) request.chair_id() /*- 1*/; //客户端传来时就是从1开始

    respone.set_result(0);
    respone.set_player_id(playerId);

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(gameId, roomId);
    if (pRoom == NULL)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "gameId:{} roomId:{} not exist, player:{} enter game failed!", gameId, roomId, playerId);

        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "player enter game, gameId = {} , roomId = {} , deskId = {} , chairId = {}", gameId, roomId, deskId, chairId);

    //这里传过来的deskId是0，应该是1才对
    //deskId += 1;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!这个要客户端年看看

    CHECK_PLAYER_EXPR(playerId, gameId > 0 && roomId > 0 && deskId > 0 && chairId > 0, -1, "param error:{}", request.DebugString());

    //从客户端发来的roomId/deskId/chairId都是从1开始，这里把deskId/chairId减1，
    //从这里以后，后台的deskId/chairId所有处理都是从0开始，只是在发给客户端时，会加1；
    int32_t deskIndex  = deskId - 1;
    int32_t chairIndex = chairId - 1;

    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    if (!pPlayer)
    {
        pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->CreatePlayer(playerId);
        CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Create Player Failed, playerId:{}", playerId);
    }

    pPlayer->SetClearFlag(false);
    pPlayer->SetProxyId(request.proxy_id());
    pPlayer->SetLogicId(request.logic_id());
    pPlayer->SetOnline(true);
    pPlayer->SetOfflineTime(0);
    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    pPlayer->m_reservedTime = 0;
    pPlayer->m_reservedDeskId = 0;
    pPlayer->m_reservedChairId = 0;

    if (pPlayer->m_gameId > 0 && pPlayer->m_roomId > 0)
    {
        if (pPlayer->m_gameId != gameId || pPlayer->m_roomId != roomId || pPlayer->m_deskId != deskIndex || pPlayer->m_chairId != chairIndex)
        {
            if (pPlayer->m_gameId == gameId && pPlayer->m_roomId == roomId && pPlayer->m_deskId == deskIndex)
            {
                if (pPlayer->m_chairId != chairIndex)
                {
                    chairIndex = pPlayer->m_chairId;
                }
            }
            else
            {
                int iRet = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(pPlayer->m_playerId);
                if (iRet != 0)
                {
                    respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                    return 0;
                }
            }
        }
    }

    proto_ff::Proto_QueryCoinBalanceReq rpcReq;
    proto_ff::Proto_QueryCoinBalanceRsp rpcRes;
    int rpcRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_GTL_COIN_QUERY_BALANCE_RPC>(NF_ST_GAME_SERVER, NF_ST_LOGIC_SERVER, pPlayer->GetLogicId(), rpcReq, rpcRes, playerId);
    //check ptr
    pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_NULL(pPlayer);
    pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(gameId, roomId);
    CHECK_NULL(pRoom);

    if (rpcRet != 0)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService NF_GTL_COIN_QUERY_BALANCE_RPC error:{}, player:{} enter game:{} room:{} failed!", GetErrorStr(rpcRet), playerId, gameId, roomId);

        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    if (rpcRes.result() != 0)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService NF_GTL_COIN_QUERY_BALANCE_RPC result:{}, player:{} enter game:{} room:{} failed!", GetErrorStr(rpcRes.result()), playerId, gameId, roomId);

        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    proto_ff_s::GamePlayerDetailData_s playerDetail;
    playerDetail.read_from_pbmsg(rpcRes.player_detail());

    int iRet = pRoom->EnterGame(playerId, deskIndex, chairIndex, playerDetail);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Room EnterGame failed, result:{}, player:{} enter game:{} room:{} failed!", GetErrorStr(iRet), playerId, gameId, roomId);
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        respone.set_result(iRet);
        return 0;
    }

    pPlayer->m_gameId = gameId;
    pPlayer->m_roomId = roomId;
    pPlayer->m_deskId = deskIndex;
    pPlayer->m_chairId = chairIndex;

    respone.set_result(0);
    respone.set_chair_count(4);
    respone.set_my_chair_id(chairIndex+1);
    respone.set_game_id(gameId);
    respone.set_room_id(roomId);
    respone.set_player_id(pPlayer->m_playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int  NFCGameRoomModule::OnHandleRecomeReq(proto_ff::UserRecomeReq& request, proto_ff::UserRecomeRsp& respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

    respone.set_result(0);

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    pPlayer->SetOnline(true);
    pPlayer->SetOfflineTime(0);
    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    int iRet = pRoom->RecomeGame(playerId, pPlayer->m_deskId);
    if (iRet == 0)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "player recome success, gameId = {} , roomId = {} , deskId = {} , chairId = {}", pPlayer->m_gameId, pPlayer->m_roomId, pPlayer->m_deskId, pPlayer->m_chairId);
    }
    else {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "player recome failed, gameId = {} , roomId = {} , deskId = {} , chairId = {}", pPlayer->m_gameId, pPlayer->m_roomId, pPlayer->m_deskId, pPlayer->m_chairId);
    }

    respone.set_result(iRet);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleExitRoomReq(proto_ff::ExitRoomReq& request, proto_ff::ExitRoomRsp& respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    if (!pPlayer)
    {
        NFGameRoomMgr::Instance(m_pObjPluginManager)->ClearDirtyData(playerId);
        respone.set_result(0);
        return 0;
    }

    respone.set_result(0);
    if (pPlayer->m_gameId > 0 || pPlayer->m_roomId > 0)
    {
        NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
        if (!pRoom)
        {
            NFGameRoomMgr::Instance(m_pObjPluginManager)->ClearDirtyData(playerId);
            respone.set_result(0);
            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleExitGameReq(proto_ff::ExitGameReq& request, proto_ff::ExitGameRsp& respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

    respone.set_exit_type(0);
    if (pPlayer->m_gameId > 0 || pPlayer->m_roomId > 0)
    {
        NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
        if (pRoom)
        {
            int iRet = pRoom->ExitGame(playerId);
            if (iRet != 0)
            {
                respone.set_exit_type(iRet);
                return 0;
            }
        }

        pPlayer->m_gameId = 0;
        pPlayer->m_roomId = 0;
        pPlayer->m_deskId = 0;
        pPlayer->m_chairId = 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::RegisterCreateDeskFunction(uint32_t gameId, const CreateDeskFunction& createFunc)
{
    auto iter = m_deskCreateMap.find(gameId);
    if (iter == m_deskCreateMap.end())
    {
        m_deskCreateMap[gameId] = createFunc;
        return 0;
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "gameId:{} desk create function exist, some wrong...........", gameId);
        NF_ASSERT(false);
    }

    return 0;
}

NFIGameDeskImpl* NFCGameRoomModule::CreateDesk(uint32_t gameId)
{
    auto iter = m_deskCreateMap.find(gameId);
    if (iter != m_deskCreateMap.end())
    {
        auto func = iter->second;
        if (func)
        {
            return func(m_pObjPluginManager, gameId);
        }
    }

    return NULL;
}

bool NFCGameRoomModule::RegisterClientMessage(uint32_t msgId)
{
    return FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_GAME_SERVER, NF_MODULE_CLIENT, msgId, this,
                                                              &NFCGameRoomModule::OnHandleRoomClientMessage);
}

bool NFCGameRoomModule::RegisterServerMessage(uint32_t msgId)
{
    return FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_GAME_SERVER, msgId, this,
                                                              &NFCGameRoomModule::OnHandleRoomServerMessage);
}

int NFCGameRoomModule::OnHandleRoomClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.GetParam1();

    NFGamePlayer* pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    NFGameRoom* pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    CHECK_PLAYER_EXPR(playerId, pRoom, -1, "Get Player Game Room Failed, playerId:{}, gameId:{}, roomId:{}", playerId, pPlayer->m_gameId, pPlayer->m_roomId);

    pRoom->OnHandleClientMessage(pPlayer->m_deskId, pPlayer->m_playerId, packet);
    return 0;
}

int NFCGameRoomModule::OnHandleRoomServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    uint64_t playerId = packet.GetParam1();

    NFGamePlayer* pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    NFGameRoom* pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    CHECK_PLAYER_EXPR(playerId, pRoom, -1, "Get Player Game Room Failed, playerId:{}, gameId:{}, roomId:{}", playerId, pPlayer->m_gameId, pPlayer->m_roomId);

    pRoom->OnHandleServerMessage(pPlayer->m_deskId, pPlayer->m_playerId, packet);
    return 0;
}

