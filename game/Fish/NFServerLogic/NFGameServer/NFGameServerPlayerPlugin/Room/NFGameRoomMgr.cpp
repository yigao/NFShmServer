// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoomMgr
//
// -------------------------------------------------------------------------

#include "NFGameRoomMgr.h"
#include "Player/NFGamePlayer.h"
#include "Player/NFGamePlayerMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Config/NFGameConfig.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRoomMgr, EOT_NFGameRoomMgr_ID, NFShmObj)

NFGameRoomMgr::NFGameRoomMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFGameRoomMgr::~NFGameRoomMgr()
{
}

int NFGameRoomMgr::CreateInit()
{
    m_inited = false;
    m_registerRoomTimer = INVALID_ID;
    return 0;
}

int NFGameRoomMgr::ResumeInit()
{
    return 0;
}

int NFGameRoomMgr::OnTimer(int timeId, int callcount)
{
    if (m_registerRoomTimer == timeId)
    {
        RegisterAllRoomToWorldServer();
    }
    return 0;
}

int NFGameRoomMgr::ClearTimeOutUser(uint64_t playerId)
{
    for (auto iter = NFGameRoom::Begin(m_pObjPluginManager); iter != NFGameRoom::End(m_pObjPluginManager); iter++)
    {
        NFGameRoom *pRoom = &(*iter);
        if (pRoom)
        {
            int iRet = pRoom->ClearTimeOutUser(playerId);
            if (iRet == 0)
            {
                NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
                if (pPlayer)
                {
                    pPlayer->ClearGameData();
                }
            }
        }
    }
    return 0;
}

int NFGameRoomMgr::ClearOfflineUser(uint64_t playerId)
{
    for (auto iter = NFGameRoom::Begin(m_pObjPluginManager); iter != NFGameRoom::End(m_pObjPluginManager); iter++)
    {
        NFGameRoom *pRoom = &(*iter);
        if (pRoom)
        {
            int iRet = pRoom->ClearOfflineUser(playerId);
            if (iRet == 0)
            {
                NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
                if (pPlayer)
                {
                    pPlayer->ClearGameData();
                }
            }
        }
    }
    return 0;
}

int NFGameRoomMgr::ClearDirtyData(uint64_t playerId)
{
    for (auto iter = NFGameRoom::Begin(m_pObjPluginManager); iter != NFGameRoom::End(m_pObjPluginManager); iter++)
    {
        NFGameRoom *pRoom = &(*iter);
        if (pRoom)
        {
            int iRet = pRoom->ClearDirtyData(playerId);
            if (iRet == 0)
            {
                NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
                if (pPlayer)
                {
                    pPlayer->ClearGameData();
                }
            }
        }
    }
    return 0;
}

int NFGameRoomMgr::ClearIdleUser(uint64_t playerId)
{
    for (auto iter = NFGameRoom::Begin(m_pObjPluginManager); iter != NFGameRoom::End(m_pObjPluginManager); iter++)
    {
        NFGameRoom *pRoom = &(*iter);
        if (pRoom)
        {
            int iRet = pRoom->ClearIdleUser(playerId);
            if (iRet == 0)
            {
                NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
                if (pPlayer)
                {
                    pPlayer->ClearGameData();
                }
            }
        }
    }
    return 0;
}

bool NFGameRoomMgr::IsPlayGame(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId)
{
    NFGameRoom *pRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pRoom, false, "room is not exist, gameId:{} roomId:{}", gameId, roomId);

    return pRoom->IsPlayGame(deskId, chairId);
}

bool NFGameRoomMgr::IsPlayGameCanLeave(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId)
{
    NFGameRoom *pRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pRoom, false, "room is not exist, gameId:{} roomId:{}", gameId, roomId);

    return pRoom->IsPlayGameCanLeave(deskId, chairId);
}

int
NFGameRoomMgr::ModifyGameMoney(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, uint32_t unChageType, uint64_t un64MoneyChange)
{
    CHECK_EXPR(un64MoneyChange > 0, -1, "moneyChange error:{}", un64MoneyChange);

    NFGameRoom *pGameRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pGameRoom, -1, "ModifyGameMoney, Get Game Room Failed, gameId:{}, roomId:{}, deskId:{} playerId:{} changeType:{} moneyChange:{}",
               gameId, roomId, deskId, playerId, unChageType, un64MoneyChange);

    return pGameRoom->UpdateUserMoney(deskId, playerId, unChageType, un64MoneyChange);
}

NFGameRoom *NFGameRoomMgr::GetGameRoom(uint32_t gameId, uint32_t roomId)
{
    auto pConfig = RoomRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(gameId, roomId);
    if (pConfig)
    {
        return NFGameRoom::GetObjByHashKey(m_pObjPluginManager, pConfig->m_id);
    }
    return nullptr;
}

NFGameRoom *NFGameRoomMgr::CreateGameRoom(uint32_t gameId, uint32_t roomId)
{
    auto pDesc = RoomRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(gameId, roomId);
    CHECK_EXPR(pDesc, NULL, "GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc Failed, gameId:{} roomId:{}", gameId, roomId);

    NFGameRoom *pRoomInfo = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pRoomInfo == NULL, pRoomInfo, "CreateGameRoom Failed, room has exist! gameId:{} roomId:{}", gameId, roomId);

    pRoomInfo = NFGameRoom::CreateObjByHashKey(m_pObjPluginManager, pDesc->m_id);
    CHECK_EXPR(pRoomInfo, NULL, "CreateGameRoom  Failed, gameId:{}, roomId:{}", gameId, roomId);

    pRoomInfo->m_gameId = gameId;
    pRoomInfo->m_roomId = roomId;
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Game Room Info gameId:{}, roomId:{} GlobalID:{}", gameId, roomId, pRoomInfo->GetGlobalId());

    pRoomInfo = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pRoomInfo, NULL, "GetGameRoom  Failed, gameId:{}, roomId:{}", gameId, roomId);

    return pRoomInfo;
}

int NFGameRoomMgr::DeleteGameRoom(NFGameRoom *pRoomInfo)
{
    CHECK_NULL(pRoomInfo);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Game Room Info, gameId:{}, roomId:{}, gloablId:{}", pRoomInfo->m_gameId, pRoomInfo->m_roomId,
              pRoomInfo->GetGlobalId());

    NFGameRoom::DestroyObj(m_pObjPluginManager, pRoomInfo);
    return 0;
}

int NFGameRoomMgr::CreateAllRoom()
{
    if (m_inited) return 0;

    auto pGameConfig = FindModule<NFIGameConfig>()->GetConfig();
    CHECK_NULL(pGameConfig);

    for(int i = 0; i < (int)pGameConfig->Game.size(); i++)
    {
        uint32_t gameId = pGameConfig->Game[i].GameId;
        for(int j = 0; j < (int)pGameConfig->Game[i].RoomId.size(); j++)
        {
            uint32_t roomId = pGameConfig->Game[i].RoomId[j];
            NFGameRoom* pRoom = CreateGameRoom(gameId, roomId);
            if (!pRoom)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Create Game Room Info Failed! gameId:{} roomId:{}", gameId, roomId);
                return -1;
            }

            auto pDesc = RoomRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(gameId, roomId);
            CHECK_NULL(pDesc);

            int iRet = pRoom->Init(gameId, pDesc->m_gamename.ToString(), roomId, pDesc->m_roomname.ToString(), pDesc->m_deskcount, pDesc->m_sitenum, pDesc->m_maxpeople);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Init Game Room Failed! gameId:{} roomId:{}, deskCount:{}", gameId, roomId, pDesc->m_deskcount, pDesc->m_sitenum, pDesc->m_maxpeople);
                return iRet;
            }
        }
    }

    m_inited = true;
    return 0;
}

int NFGameRoomMgr::RegisterAllRoomToWorldServer()
{
    proto_ff::Proto_GTW_RegisterRoomInfoReq req;
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    NF_ASSERT(pConfig);
    auto pGameConfig = FindModule<NFIGameConfig>()->GetConfig();
    CHECK_NULL(pGameConfig);

    req.set_bus_id(pConfig->GetBusId());
    for(int i = 0; i < (int)pGameConfig->Game.size(); i++)
    {
        uint32_t gameId = pGameConfig->Game[i].GameId;
        auto pGamePB = req.add_game();
        pGamePB->set_gameid(gameId);
        for(int j = 0; j < (int)pGameConfig->Game[i].RoomId.size(); j++)
        {
            uint32_t roomId = pGameConfig->Game[i].RoomId[j];
            NFGameRoom* pRoom = GetGameRoom(gameId, roomId);
            CHECK_NULL(pRoom);

            pGamePB->add_roomid(roomId);
        }
    }

    if (m_registerRoomTimer != INVALID_ID)
    {
        m_registerRoomTimer = SetTimer(10000, 0, 0, 0, 3, 0);
    }

    int64_t rpcId = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_GTW_REGISTER_ROOM_INFO_RPC>(NF_ST_GAME_SERVER, NF_ST_WORLD_SERVER, 0, req, [req, this](int rpcRetCode, proto_ff::Proto_WTG_RegisterRoomInfoRsp &respone){
        if (rpcRetCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Register RoomInfo To World Server Failed! rpcRetCode:{}", GetErrorStr(rpcRetCode));
            return;
        }

        if (respone.result() != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Register RoomInfo To World Server Failed! req:{}", req.DebugString());
            return;
        }

        if (m_registerRoomTimer != INVALID_ID)
        {
            DeleteTimer(m_registerRoomTimer);
        }

        m_pObjPluginManager->FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER, APP_INIT_STATUS_SERVER_REGISTER);

        NFLogError(NF_LOG_SYSTEMLOG, 0, "Register RoomInfo To World Server Success, req:{}", req.DebugString());
    });

    if (rpcId == INVALID_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Register RoomInfo To World Server Failed! req:{}", req.DebugString());
    }

    return 0;
}

