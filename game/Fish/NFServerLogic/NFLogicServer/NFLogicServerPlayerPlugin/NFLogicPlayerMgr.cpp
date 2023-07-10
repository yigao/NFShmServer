// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFLogicPlayerMgr.h"
#include "NFLogicPlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include <map>

IMPLEMENT_IDCREATE_WITHTYPE(NFLogicPlayerMgr, EOT_WORLD_PLAYER_MGR_ID, NFShmObj)

NFLogicPlayerMgr::NFLogicPlayerMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFLogicPlayerMgr::~NFLogicPlayerMgr()
{
    if (m_playerTickTimer != INVALID_ID)
    {
        DeleteTimer(m_playerTickTimer);
        m_playerTickTimer = INVALID_ID;
    }
}

int NFLogicPlayerMgr::CreateInit() {
    m_playerTickTimer = SetTimer(1000, 0, 0, 0, 1, 0);
    return 0;
}


int NFLogicPlayerMgr::ResumeInit() {
    return 0;
}

int NFLogicPlayerMgr::OnTimer(int timeId, int callcount)
{
    if (m_playerTickTimer == timeId)
    {
        UserTick();
    }

    return 0;
}

int NFLogicPlayerMgr::UserTick()
{
    std::vector<uint64_t> willRemovePlayer;
    for(auto iter = NFLogicPlayer::Begin(m_pObjPluginManager); iter != NFLogicPlayer::End(m_pObjPluginManager); iter++)
    {
        NFLogicPlayer* pPlayer = &(*iter);
        pPlayer->Tick();
        if (pPlayer->GetStatus() == proto_ff::PLAYER_STATUS_DEAD)
        {
            willRemovePlayer.push_back(pPlayer->GetPlayerId());
        }
    }

    for(int i = 0; i < (int)willRemovePlayer.size(); i++)
    {
        NFLogicPlayer* pPlayer = GetPlayer(willRemovePlayer[i]);
        if (pPlayer)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player:{} be erase from memory", pPlayer->GetPlayerId());
            DeletePlayer(pPlayer);
        }
    }
    return 0;
}


NFLogicPlayer *NFLogicPlayerMgr::GetPlayer(uint64_t playerId)
{
    return dynamic_cast<NFLogicPlayer*>(NFLogicPlayer::GetObjByHashKey(m_pObjPluginManager, playerId));
}

NFLogicPlayer *NFLogicPlayerMgr::CreatePlayer(uint64_t playerId)
{
    NFLogicPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, palyerId:{}", playerId);

    pPlayer = dynamic_cast<NFLogicPlayer *>(NFLogicPlayer::CreateObjByHashKey(m_pObjPluginManager, playerId));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", playerId);

    pPlayer->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Player Success, playerId:{} globalId:{}", playerId,
              pPlayer->GetGlobalId());
    return pPlayer;
}

int NFLogicPlayerMgr::DeletePlayer(NFLogicPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetPlayerId(), pPlayer->GetGlobalId());

    NFLogicPlayer::DestroyObj(m_pObjPluginManager, pPlayer);

    return 0;
}