// -------------------------------------------------------------------------
//    @FileName         :    NFGamePlayerMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGamePlayerMgr
//
// -------------------------------------------------------------------------

#include "NFGamePlayerMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "Room/NFGameRoomMgr.h"

NFGamePlayerMgr::NFGamePlayerMgr()
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

NFGamePlayerMgr::~NFGamePlayerMgr()
{
	m_clearOfflineTimer = INVALID_ID;
}

int NFGamePlayerMgr::CreateInit()
{
	m_clearOfflineTimer = SetTimer(1000, 0, 0, 0, 10, 0);
	return 0;
}

int NFGamePlayerMgr::ResumeInit()
{
	return 0;
}

NFGamePlayer* NFGamePlayerMgr::GetPlayer(uint64_t playerId)
{
	return NFGamePlayer::GetObjByHashKey(m_pObjPluginManager, playerId);
}

NFGamePlayer* NFGamePlayerMgr::CreatePlayer(uint64_t playerId)
{
	NFGamePlayer* pPlayer = GetPlayer(playerId);
	CHECK_EXPR(pPlayer == NULL, pPlayer, "Create player Failed, player exist, palyerId:{}", playerId);

	pPlayer = NFGamePlayer::CreateObjByHashKey(m_pObjPluginManager, playerId);
	CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", playerId);

	pPlayer->m_playerId = playerId;
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Player Success, playerId:{} globalId:{}", playerId,
			  pPlayer->GetGlobalId());

	pPlayer = GetPlayer(playerId);
	CHECK_EXPR(pPlayer, NULL, "GetPlayer player Failed, palyerId:{}", playerId);

	return pPlayer;
}

int NFGamePlayerMgr::DeletePlayer(NFGamePlayer* pPlayer)
{
	CHECK_NULL(pPlayer);

	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->m_playerId, pPlayer->GetGlobalId());;

	NFGamePlayer::DestroyObj(m_pObjPluginManager, pPlayer);

	return 0;
}

int NFGamePlayerMgr::CheckOfflineUser()
{
	std::vector<NFGamePlayer *> willDestroy;
	uint32_t nowTime = NFTime::Now().UnixSec();
	for (auto iter = NFGamePlayer::Begin(m_pObjPluginManager); iter != NFGamePlayer::End(m_pObjPluginManager); iter++)
	{
		NFGamePlayer* pPlayer = &(*iter);
		if (pPlayer)
		{
			if (pPlayer->IsOnline() == false)
			{
				if (pPlayer->GetOfflineTime() > 0 && nowTime - pPlayer->GetOfflineTime() >= PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME)
				{
					if (pPlayer->IsInGame())
					{
						if (NFGameRoomMgr::GetInstance(m_pObjPluginManager)->IsPlayGame(pPlayer->GetGameId(), pPlayer->GetRoomId(), pPlayer->GetDeskId(), pPlayer->GetChairId()) &&
							!NFGameRoomMgr::GetInstance(m_pObjPluginManager)->IsPlayGameCanLeave(pPlayer->GetGameId(), pPlayer->GetRoomId(), pPlayer->GetDeskId(), pPlayer->GetChairId()))
						{
							continue;
						}
						else
						{
							NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearOfflineUser(pPlayer->m_playerId);
							willDestroy.push_back(pPlayer);
							continue;
						}
					}
					else
					{
						NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearOfflineUser(pPlayer->m_playerId);
						willDestroy.push_back(pPlayer);
						continue;
					}
				}
			}
			else if (pPlayer->IsIdle())
			{
				NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearIdleUser(pPlayer->m_playerId);
				willDestroy.push_back(pPlayer);
				continue;
			}
			else
			{
				if (nowTime - pPlayer->GetLastMsgTime() >= PLAYER_MAX_NO_MSG_TIME)
				{
					NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearTimeOutUser(pPlayer->m_playerId);
					willDestroy.push_back(pPlayer);
					continue;
				}
			}
		}
	}

	for (auto iter = willDestroy.begin(); iter != willDestroy.end(); iter++)
	{
		DeletePlayer(*iter);
	}

	return 0;
}

int NFGamePlayerMgr::ClearAllGamePlayer()
{
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ClearAllGamePlayer............");
	std::vector<NFGamePlayer *> willDestroy;
	for (auto iter = NFGamePlayer::Begin(m_pObjPluginManager); iter != NFGamePlayer::End(m_pObjPluginManager); iter++)
	{
		NFGamePlayer* pPlayer = &(*iter);
		if (pPlayer)
		{
			if (pPlayer->m_isRobot == false && pPlayer->IsOnline() == false)
			{
				NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(pPlayer->m_playerId);
				willDestroy.push_back(pPlayer);
			}
		}
	}

	for (auto iter = willDestroy.begin(); iter != willDestroy.end(); iter++)
	{
		DeletePlayer(*iter);
	}

	return 0;
}

int NFGamePlayerMgr::OnTimer(int timeId, int callcount)
{
	if (m_clearOfflineTimer == timeId)
	{
		CheckOfflineUser();
	}

	return 0;
}
