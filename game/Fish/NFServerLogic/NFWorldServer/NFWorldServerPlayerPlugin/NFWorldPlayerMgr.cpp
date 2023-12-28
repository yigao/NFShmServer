// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include <map>

NFWorldPlayerMgr::NFWorldPlayerMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFWorldPlayerMgr::~NFWorldPlayerMgr()
{
    if (m_playerTickTimer != INVALID_ID)
    {
        DeleteTimer(m_playerTickTimer);
        m_playerTickTimer = INVALID_ID;
    }
}

int NFWorldPlayerMgr::CreateInit() {
    m_playerTickTimer = SetTimer(1000, 0, 0, 0, 1, 0);
    return 0;
}


int NFWorldPlayerMgr::ResumeInit() {
    return 0;
}

int NFWorldPlayerMgr::OnTimer(int timeId, int callcount)
{
    if (m_playerTickTimer == timeId)
    {
        UserTick();
    }

    return 0;
}

int NFWorldPlayerMgr::UserTick()
{
    std::vector<uint64_t> willRemovePlayer;
    for(auto iter = NFWorldPlayer::Begin(m_pObjPluginManager); iter != NFWorldPlayer::End(m_pObjPluginManager); iter++)
    {
        NFWorldPlayer* pPlayer = &(*iter);
        pPlayer->Tick();
        if (pPlayer->GetStatus() == proto_ff::PLAYER_STATUS_DEAD)
        {
            willRemovePlayer.push_back(pPlayer->GetPlayerId());
        }
    }

    for(int i = 0; i < (int)willRemovePlayer.size(); i++)
    {
        NFWorldPlayer* pPlayer = GetPlayer(willRemovePlayer[i]);
        if (pPlayer)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player:{} be erase from memory", pPlayer->GetPlayerId());
            DeletePlayer(pPlayer);
        }
    }
    return 0;
}


NFWorldPlayer *NFWorldPlayerMgr::GetPlayer(uint64_t playerId)
{
    return dynamic_cast<NFWorldPlayer*>(NFWorldPlayer::GetObjByHashKey(m_pObjPluginManager, playerId));
}

NFWorldPlayer *NFWorldPlayerMgr::CreatePlayer(uint64_t playerId)
{
    NFWorldPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, palyerId:{}", playerId);

    pPlayer = dynamic_cast<NFWorldPlayer *>(NFWorldPlayer::CreateObjByHashKey(m_pObjPluginManager, playerId));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", playerId);

    pPlayer->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Player Success, playerId:{} globalId:{}", playerId,
              pPlayer->GetGlobalId());
    return pPlayer;
}

int NFWorldPlayerMgr::DeletePlayer(NFWorldPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetPlayerId(), pPlayer->GetGlobalId());

    NFWorldPlayer::DestroyObj(m_pObjPluginManager, pPlayer);

    return 0;
}