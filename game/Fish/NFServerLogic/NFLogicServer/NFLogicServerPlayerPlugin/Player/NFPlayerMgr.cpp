// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFPlayerMgr.h"
#include "NFPlayer.h"
#include "NFComm/NFPluginModule/NFError.h"

NFPlayerMgr::NFPlayerMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFPlayerMgr::~NFPlayerMgr()
{
    if (m_playerTickTimer != INVALID_ID)
    {
        DeleteTimer(m_playerTickTimer);
        m_playerTickTimer = INVALID_ID;
    }
}

int NFPlayerMgr::CreateInit() {
    m_playerTickTimer = SetTimer(100, 0, 0, 0, 1, 0);
    m_dayTickTimer = SetDayCalender(0, 0, 0, 0);
    m_weekTickTimer = SetWeekCalender(0, 1, 0, 0, 0);
    m_monthTickTimer = SetMonthCalender(0, 1, 0, 0, 0);
    return 0;
}


int NFPlayerMgr::ResumeInit() {
    return 0;
}

int NFPlayerMgr::OnTimer(int timeId, int callcount)
{
    if (m_playerTickTimer == timeId)
    {
        Tick();
    }
    else if (m_dayTickTimer == timeId)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "time:{}", NFTime::Now().GetFormatTime());
        DailyZeroUpdate();
    }
    else if (m_weekTickTimer == timeId)
    {
        WeekZeroUpdate();
    }
    else if (m_monthTickTimer == timeId)
    {
        MonthZeroUpdate();
    }

    return 0;
}

int NFPlayerMgr::Tick()
{
    std::vector<uint64_t> willRemovePlayer;
    for(auto iter = NFPlayer::Begin(m_pObjPluginManager); iter != NFPlayer::End(m_pObjPluginManager); iter++)
    {
        NFPlayer* pPlayer = &(*iter);
        pPlayer->Tick();
        if (pPlayer->GetStatus() == proto_ff::PLAYER_STATUS_DEAD)
        {
            willRemovePlayer.push_back(pPlayer->GetPlayerId());
        }
    }

    for(int i = 0; i < (int)willRemovePlayer.size(); i++)
    {
        NFPlayer* pPlayer = GetPlayer(willRemovePlayer[i]);
        if (pPlayer)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "player:{} be erase from memory", pPlayer->GetPlayerId());
            DeletePlayer(pPlayer);
        }
    }
    return 0;
}


NFPlayer *NFPlayerMgr::GetPlayer(uint64_t playerId)
{
    return dynamic_cast<NFPlayer*>(NFPlayer::GetObjByHashKey(m_pObjPluginManager, playerId));
}

NFPlayer *NFPlayerMgr::CreatePlayer(uint64_t playerId, const proto_ff::tbFishPlayerData& dbData, bool bCreatePlayer)
{
    NFPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, palyerId:{}", playerId);

    pPlayer = dynamic_cast<NFPlayer *>(NFPlayer::CreateObjByHashKey(m_pObjPluginManager, playerId));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", playerId);

    pPlayer->SetPlayerId(playerId);
    int iRet = pPlayer->Init(dbData, bCreatePlayer);
    if (iRet != 0)
    {
        NFPlayer::DestroyObj(m_pObjPluginManager, pPlayer);
        NFLogInfo(NF_LOG_SYSTEMLOG, playerId, "Create Player Failed,  playerId:{} Init Failed, iRet:{}", playerId, GetErrorStr(iRet));
        return NULL;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Create Player Success, playerId:{} globalId:{}", playerId,
              pPlayer->GetGlobalId());
    return pPlayer;
}

int NFPlayerMgr::DeletePlayer(NFPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetPlayerId(), pPlayer->GetGlobalId());

    NFPlayer::DestroyObj(m_pObjPluginManager, pPlayer);

    return 0;
}

int NFPlayerMgr::DailyZeroUpdate()
{
    for(auto iter = NFPlayer::Begin(m_pObjPluginManager); iter != NFPlayer::End(m_pObjPluginManager); iter++)
    {
        NFPlayer* pPlayer = &(*iter);
        pPlayer->DailyZeroUpdate();
    }
    return 0;
}

int NFPlayerMgr::WeekZeroUpdate()
{
    for(auto iter = NFPlayer::Begin(m_pObjPluginManager); iter != NFPlayer::End(m_pObjPluginManager); iter++)
    {
        NFPlayer* pPlayer = &(*iter);
        pPlayer->WeekZeroUpdate();
    }
    return 0;
}

int NFPlayerMgr::MonthZeroUpdate()
{
    for(auto iter = NFPlayer::Begin(m_pObjPluginManager); iter != NFPlayer::End(m_pObjPluginManager); iter++)
    {
        NFPlayer* pPlayer = &(*iter);
        pPlayer->MonthZeroUpdate();
    }
    return 0;
}
