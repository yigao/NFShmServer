// -------------------------------------------------------------------------
//    @FileName         :    NFGamePlayerIDHashTable.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGamePlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFGameSessionMgr.h"
#include "NFGameSession.h"
#include "NFGameRoomMgr.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameSessionMgr, EOT_GAME_PLAYER_HASH_TABLE_ID, NFShmObj)

NFGameSessionMgr::NFGameSessionMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGameSessionMgr::~NFGameSessionMgr()
{
	if (m_clearOfflineTimer != INVALID_ID)
	{
		DeleteTimer(m_clearOfflineTimer);
		m_clearOfflineTimer = INVALID_ID;
	}
}

int NFGameSessionMgr::CreateInit() {
	m_clearOfflineTimer = SetTimer(1000, 0, 0, 0, 10, 0);
    return 0;
}


int NFGameSessionMgr::ResumeInit() {
    return 0;
}

NFGameSession *NFGameSessionMgr::GetPlayer(uint64_t playerId)
{
	return dynamic_cast<NFGameSession*>(NFShmMgr::Instance()->GetObjFromHashKey(playerId, EOT_GAME_PLAYER_ID));
}

NFGameSession *NFGameSessionMgr::CreatePlayer(uint64_t playerId)
{
    NFGameSession *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer == NULL, pPlayer, "Create player Failed, player exist, palyerId:{}", playerId);

	pPlayer = dynamic_cast<NFGameSession *>(NFShmMgr::Instance()->CreateObj(playerId, EOT_GAME_PLAYER_ID));;
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", playerId);

    pPlayer->m_playerId = playerId;
    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Add Player Success, playerId:{} globalId:{}", playerId,
              pPlayer->GetGlobalID());

	pPlayer = GetPlayer(playerId);
	CHECK_EXPR(pPlayer, NULL, "GetPlayer player Failed, palyerId:{}", playerId);

    return pPlayer;
}

int NFGameSessionMgr::DeletePlayer(NFGameSession *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->m_playerId, pPlayer->GetGlobalID());;

    NFShmMgr::Instance()->DestroyObj(pPlayer);

    return 0;
}

std::vector<NFGameSession*> NFGameSessionMgr::GetAllPlayer()
{
    std::vector<NFGameSession*> vec;
    NFGameSession* pPlayer = dynamic_cast<NFGameSession *>(NFShmMgr::Instance()->GetHeadObj(EOT_GAME_PLAYER_ID));
    while (pPlayer)
    {
        vec.push_back(pPlayer);
        pPlayer = dynamic_cast<NFGameSession *>(NFShmMgr::Instance()->GetNextObj(EOT_GAME_PLAYER_ID, pPlayer));
    }
    return vec;
}

uint32_t NFGameSessionMgr::GetPlayerCount()
{
    return (uint32_t)NFGameSession::GetUsedCount();
}

int NFGameSessionMgr::CheckOfflineUser()
{
	uint32_t nowTime = NFTime::Now().UnixSec();
	std::vector<NFGameSession*> vecGamePlayer = GetAllPlayer();
	for (int i = 0; i < (int)vecGamePlayer.size(); i++)
	{
		NFGameSession* pPlayer = vecGamePlayer[i];
		if (pPlayer)
		{
			if (pPlayer->IsOnline() == false)
			{
				if (pPlayer->GetOfflineTime() > 0 && nowTime - pPlayer->GetOfflineTime() >= PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME)
				{
					if (pPlayer->IsInGame())
					{
						if (NFGameRoomMgr::GetInstance()->IsPlayGame(pPlayer->GetGameId(), pPlayer->GetRoomId(), pPlayer->GetDeskId(), pPlayer->GetChairId()) && 
							!NFGameRoomMgr::GetInstance()->IsPlayGameCanLeave(pPlayer->GetGameId(), pPlayer->GetRoomId(), pPlayer->GetDeskId(), pPlayer->GetChairId()))
						{
							continue;
						}
						else
						{
							NFGameRoomMgr::GetInstance()->ClearOfflineUser(pPlayer->m_playerId);
							DeletePlayer(pPlayer);
							continue;
						}
					}
					else
					{
						NFGameRoomMgr::GetInstance()->ClearOfflineUser(pPlayer->m_playerId);
						DeletePlayer(pPlayer);
						continue;
					}
				}
			}
			else if (pPlayer->IsIdle())
            {
                NFGameRoomMgr::GetInstance()->ClearIdleUser(pPlayer->m_playerId);
                DeletePlayer(pPlayer);
                continue;
            }
			else
			{
				if (nowTime - pPlayer->GetLastMsgTime() >= PLAYER_MAX_NO_MSG_TIME)
				{
					NFGameRoomMgr::GetInstance()->ClearTimeOutUser(pPlayer->m_playerId);
					DeletePlayer(pPlayer);
					continue;
				}
			}
		}
	}

	return 0;
}

int NFGameSessionMgr::ClearAllGamePlayer()
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ClearAllGamePlayer............");
    std::vector<NFGameSession*> vecGamePlayer = GetAllPlayer();
    for (int i = 0; i < (int)vecGamePlayer.size(); i++)
    {
        NFGameSession* pPlayer = vecGamePlayer[i];
        if (pPlayer)
        {
            if (pPlayer->m_isRobot == false && pPlayer->IsOnline() == false)
            {
                NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
                DeletePlayer(pPlayer);
            }
        }
    }

    return 0;
}

void NFGameSessionMgr::OnTimer(int timeId, int callcount)
{
	if (m_clearOfflineTimer == timeId)
	{
		CheckOfflineUser();
	}
}


