// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomIDHashTable.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoomIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFGameRoomMgr.h"
#include "NFGameRoom.h"
#include "NFGameSessionMgr.h"
#include "NFGameSession.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRoomMgr, EOT_GAME_ROOM_ID_HASH_TABLE_ID, NFShmObj)

NFGameRoomMgr::NFGameRoomMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGameRoomMgr::~NFGameRoomMgr()
{

}

int NFGameRoomMgr::CreateInit() {
    return 0;
}


int NFGameRoomMgr::ResumeInit() {
    return 0;
}

NFGameRoom *NFGameRoomMgr::GetGameRoom(uint32_t gameId, uint32_t roomId)
{
    uint64_t indexId = GetIndexId(gameId, roomId);
	return dynamic_cast<NFGameRoom*>(NFShmMgr::Instance()->GetObjFromHashKey(indexId, EOT_GAME_ROOM_ID));
}

NFGameRoom *NFGameRoomMgr::CreateGameRoom(uint32_t gameId, uint32_t roomId)
{
	uint64_t indexId = GetIndexId(gameId, roomId);
    NFGameRoom *pRoomInfo = GetGameRoom(gameId, roomId);
	CHECK_EXPR(pRoomInfo == NULL, pRoomInfo, "CreateGameRoom Failed, room has exist! gameId:{} roomId:{}", gameId, roomId);

	pRoomInfo = dynamic_cast<NFGameRoom *>(NFShmMgr::Instance()->CreateObj(indexId, EOT_GAME_ROOM_ID));
	CHECK_EXPR(pRoomInfo, NULL, "CreateGameRoom  Failed, gameId:{}, roomId:{}", gameId, roomId);

	pRoomInfo->m_gameId = gameId;
	pRoomInfo->m_roomId = roomId;
	NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Add Game Room Info gameId:{}, roomId:{} GlobalID:{}", gameId, roomId, pRoomInfo->GetGlobalID());

	pRoomInfo = GetGameRoom(gameId, roomId);
	CHECK_EXPR(pRoomInfo, NULL, "GetGameRoom  Failed, gameId:{}, roomId:{}", gameId, roomId);

    return pRoomInfo;
}

int NFGameRoomMgr::DeleteGameRoom(NFGameRoom *pRoomInfo)
{
    CHECK_NULL(pRoomInfo);

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete Game Room Info, gameId:{}, roomId:{}, gloablId:{}", pRoomInfo->m_gameId, pRoomInfo->m_roomId, pRoomInfo->GetGlobalID());


	NFShmMgr::Instance()->DestroyObj(pRoomInfo);

    return 0;
}

uint64_t NFGameRoomMgr::GetIndexId(uint32_t gameId, uint32_t tableId)
{
    return MAKE_UINT64(gameId, tableId);
}

std::vector<NFGameRoom*> NFGameRoomMgr::GetAllRoom()
{
    std::vector<NFGameRoom*> vec;
    NFGameRoom* pRoomInfo = (NFGameRoom *) NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROOM_ID);
    while (pRoomInfo)
    {
        vec.push_back(pRoomInfo);
        pRoomInfo = (NFGameRoom *) NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROOM_ID, pRoomInfo);
    }
    return vec;
}

int NFGameRoomMgr::ClearIdleUser(uint64_t playerId)
{
    NFGameRoom* pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROOM_ID);
    while (pRoomInfo)
    {
        int iRet = pRoomInfo->ClearIdleUser(playerId);
        if (iRet == 0)
        {
            NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer) {
                pPlayer->ClearGameData();
            }
        }
        pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROOM_ID, pRoomInfo);
    }
    return 0;
}

int NFGameRoomMgr::ClearTimeOutUser(uint64_t playerId)
{
	NFGameRoom* pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROOM_ID);
	while (pRoomInfo)
	{
		int iRet = pRoomInfo->ClearTimeOutUser(playerId);
        if (iRet == 0)
        {
            NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer) {
                pPlayer->ClearGameData();
            }
        }
		pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROOM_ID, pRoomInfo);
	}
	return 0;
}

int NFGameRoomMgr::ClearOfflineUser(uint64_t playerId)
{
	NFGameRoom* pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROOM_ID);
	while (pRoomInfo)
	{
		int iRet = pRoomInfo->ClearOfflineUser(playerId);
		if (iRet == 0)
        {
            NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer) {
                pPlayer->ClearGameData();
            }
        }
		pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROOM_ID, pRoomInfo);
	}
	return 0;
}

int NFGameRoomMgr::ClearDirtyData(uint64_t playerId)
{
	NFGameRoom* pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROOM_ID);
	while (pRoomInfo)
	{
		int iRet = pRoomInfo->ClearDirtyData(playerId);
        if (iRet == 0)
        {
            NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer) {
                pPlayer->ClearGameData();
            }
        }
		pRoomInfo = (NFGameRoom *)NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROOM_ID, pRoomInfo);
	}
	return 0;
}

bool NFGameRoomMgr::IsPlayGame(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId)
{
	NFGameRoom* pRoom = GetGameRoom(gameId, roomId);
	CHECK_EXPR(pRoom, false, "room is not exist, gameId:{} roomId:{}", gameId, roomId);

	return pRoom->IsPlayGame(deskId, chairId);
}

bool NFGameRoomMgr::IsPlayGameCanLeave(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId)
{
	NFGameRoom* pRoom = GetGameRoom(gameId, roomId);
	CHECK_EXPR(pRoom, false, "room is not exist, gameId:{} roomId:{}", gameId, roomId);

	return pRoom->IsPlayGameCanLeave(deskId, chairId);
}

//------------------------------------------------------------------------------------------------------------
//游戏中获得金币，消耗金币，调用接口
int	NFGameRoomMgr::ModifyGameMoney(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(moneyChange > 0, -1, "moneyChange error:{}", moneyChange);

	NFGameRoom *pGameRoom = GetGameRoom(gameId, roomId);
	CHECK_EXPR(pGameRoom, -1, "ModifyGameMoney, Get Game Room Failed, gameId:{}, roomId:{}, deskId:{} playerId:{} changeType:{} moneyChange:{}", gameId, roomId, deskId, playerId, changeType, moneyChange);

	int iRetCode = pGameRoom->UpdateUserMoney(deskId, playerId, changeType, moneyChange);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFGameRoomMgr::SetUserManagerInfo(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (pUserManagerData == NULL) return 0;

    NFGameRoom *pGameRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pGameRoom, -1, "ModifyGameMoney, Get Game Room Failed, gameId:{}, roomId:{}, deskId:{}", gameId, roomId, deskId);

    int iRetCode = pGameRoom->SetUserManagerInfo(deskId, playerId, pUserManagerData);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFGameRoomMgr::SetGmCtrlGiveData(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (pGmCtrlGiveDta == NULL) return 0;

    NFGameRoom *pGameRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pGameRoom, -1, "ModifyGameMoney, Get Game Room Failed, gameId:{}, roomId:{}, deskId:{}", gameId, roomId, deskId);

    int iRetCode = pGameRoom->SetGmCtrlGiveData(deskId, playerId, pGmCtrlGiveDta);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

void NFGameRoomMgr::OnTimer(int timeId, int callcount)
{

}

int NFGameRoomMgr::UpdateUserInfo(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (pUserDetailInfo == NULL) return 0;

    NFGameRoom *pGameRoom = GetGameRoom(gameId, roomId);
    CHECK_EXPR(pGameRoom, -1, "ModifyGameMoney, Get Game Room Failed, gameId:{}, roomId:{}, deskId:{}", gameId, roomId, deskId);

    int iRetCode = pGameRoom->UpdateUserInfo(deskId, playerId, pUserDetailInfo);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}
