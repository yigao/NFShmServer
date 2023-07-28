// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoomMgr
//
// -------------------------------------------------------------------------

#include "NFGameRoomMgr.h"
#include "DescStoreEx/GameRoomDescEx.h"
#include "Player/NFGamePlayer.h"
#include "Player/NFGamePlayerMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

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
    return 0;
}

int NFGameRoomMgr::ResumeInit()
{
    return 0;
}

int NFGameRoomMgr::OnTimer(int timeId, int callcount)
{
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
    uint32_t id = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDescId(gameId, roomId);
    return NFGameRoom::GetObjByHashKey(m_pObjPluginManager, id);
}

NFGameRoom *NFGameRoomMgr::CreateGameRoom(uint32_t gameId, uint32_t roomId)
{
    auto pDesc = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(gameId, roomId);
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


