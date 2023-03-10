// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerMgr
//
// -------------------------------------------------------------------------

#include "NFPlayerMgr.h"
#include "NFPlayer.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include <map>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFComm/NFCore/NFServerTime.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "ServerInternal2.pb.h"
#include "ServerInternalCmd2.pb.h"
#include "Scene.pb.h"
#include "ClientServerCmd.pb.h"
#include "Move.pb.h"
#include "Trans/NFTransEnterScene.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerMgr, EOT_LOGIC_PLAYER_MGR_ID, NFShmObj)

NFPlayerMgr::NFPlayerMgr() : NFShmObj()
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

NFPlayerMgr::~NFPlayerMgr()
{
    m_dayZeroTimer = INVALID_ID;
    m_weekZeroTimer = INVALID_ID;
}

int NFPlayerMgr::CreateInit()
{
    m_dayZeroTimer = SetDayCalender(INVALID_ID, 0, 0, 0);
    m_weekZeroTimer = SetWeekCalender(INVALID_ID, 1, 0, 0, 0);
    return 0;
}

int NFPlayerMgr::ResumeInit()
{
    return 0;
}

int NFPlayerMgr::Execute()
{
    TickNow(m_pObjPluginManager->GetCurFrameCount());
    return 0;
}

int NFPlayerMgr::SavePlayerRoleDetail(NFPlayer *pPlayer, TRANS_SAVE_ROLE_DETAIL_REASON iReason)
{
    int iRetCode = 0;

    CHECK_NULL(pPlayer);

    if (NFTransSaveRoleDetail::GetUsedCount(m_pObjPluginManager) >= NFTransSaveRoleDetail::GetItemCount(m_pObjPluginManager))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFTransSaveRoleDetail Count Not Enough!");
        return 0;
    }

    NFTransSaveRoleDetail *pTrans = dynamic_cast<NFTransSaveRoleDetail *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_SAVE_ROLE));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransSaveRoleDetail failed!");
    pTrans->Init(pPlayer);

    iRetCode = pTrans->SaveRoleDetail(iReason);
    CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "uid:{} roleId:{} SaveRoleDetail Failed", pPlayer->GetUid(), pPlayer->GetRoleId());

    pPlayer->SetRoleDetailSavingDBTime(NFTime::Now().UnixSec());
    return 0;
}

NFPlayer *NFPlayerMgr::GetPlayer(uint64_t roleId)
{
    return dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(roleId, EOT_LOGIC_PLAYER_ID));
}

NFPlayer *NFPlayerMgr::GetPlayerByUid(uint64_t uid)
{
    return dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetObjByIndexKey(PLAYER_UID_INDEX, uid, EOT_LOGIC_PLAYER_ID));
}

NFPlayer *NFPlayerMgr::CreatePlayer(uint64_t roleId, uint64_t uid, const ::proto_ff::RoleDBData &dbData)
{
    NFPlayer *pPlayer = GetPlayer(roleId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, roleId:{}", roleId);

    pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(roleId, EOT_LOGIC_PLAYER_ID));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, roleId:{}", roleId);

    pPlayer->SetRoleId(roleId);
    pPlayer->SetUid(uid);

    NFPlayer *pUidPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->CreateIndexToHashKey(PLAYER_UID_INDEX, uid, roleId,
                                                                                                           EOT_LOGIC_PLAYER_ID));
    if (!(pUidPlayer && pUidPlayer == pPlayer))
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "CreateIndexToHashKey Failed, roleId:{}, uid:{}", roleId, uid);
        DeletePlayer(pPlayer);
        return NULL;
    }

    pUidPlayer = NULL;
    pUidPlayer = GetPlayerByUid(uid);
    if (!(pUidPlayer && pUidPlayer == pPlayer))
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "GetPlayerByUid Failed, roleId:{}, uid:{}", roleId, uid);
        DeletePlayer(pPlayer);
        return NULL;
    }

    int iRet = pPlayer->Init(dbData);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Player Init Data From DB Rsp Failed! dbData:{}", dbData.DebugString());
        DeletePlayer(pPlayer);
        return NULL;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, roleId, "Add Player Success, roleId:{} uid:{} globalId:{}", roleId, uid, pPlayer->GetGlobalID());
    return pPlayer;
}

int NFPlayerMgr::DeletePlayer(NFPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, roleId:{}, uid:{}, gloablId:{}", pPlayer->GetRoleId(), pPlayer->GetUid(),
              pPlayer->GetGlobalID());

    FindModule<NFISharedMemModule>()->DelIndexKey(PLAYER_UID_INDEX, pPlayer->GetUid(), EOT_LOGIC_PLAYER_ID);

    FindModule<NFISharedMemModule>()->DestroyObj(pPlayer);

    return 0;
}

int NFPlayerMgr::OnLoad(NFPlayer *pPlayer, bool isLoadDB)
{
    return 0;
}

int NFPlayerMgr::OnLogin(NFPlayer *pPlayer, bool isLoadDB)
{
    OnEventLogLogin(pPlayer, isLoadDB);
    return 0;
}

int NFPlayerMgr::OnEventLogLogin(NFPlayer *pPlayer, bool isLoadDB)
{
    return 0;
}

int NFPlayerMgr::OnLogout(NFPlayer *pPlayer)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "player:{}, cid:{} status change to PLAYER_STATUS_LOGOUT, will be erase from memory", pPlayer->GetUid(),
              pPlayer->GetRoleId());

    DeletePlayer(pPlayer);

    return 0;
}

int NFPlayerMgr::OnDisconnect(NFPlayer *pPlayer)
{
    return 0;
}

int NFPlayerMgr::OnReconnect(NFPlayer *pPlayer)
{
    return 0;
}

int NFPlayerMgr::DoTick(uint32_t dwCurRunIndex, bool bIsTickAll)
{
    int iPerTickNumThisTime = m_iNumPerTick;

    while (m_iTickedNum < iPerTickNumThisTime || bIsTickAll)
    {
        if (FindModule<NFISharedMemModule>()->IsEnd(EOT_LOGIC_PLAYER_ID, m_iLastTickIndex))
        {
            m_iLastTickIndex = 0;
            m_bIsTickFinished = true;
            break;
        }

        /**
         * @brief 这样写的好处，可以在循环里删除玩家信息
         */
        NFPlayer *pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetObj(EOT_LOGIC_PLAYER_ID, m_iLastTickIndex));
        if (pPlayer)
        {
            pPlayer->Tick();
            m_iTickedNum++;
        }

        m_iLastTickIndex++;
    }

    return 0;
}

int NFPlayerMgr::EnterGame(uint64_t roleId, const CharLoginInfo &loginInfo)
{
    NFPlayer *pPlayer = GetPlayer(roleId);
    CHECK_NULL(pPlayer);

    return pPlayer->LoginGame(loginInfo, true);
}

int NFPlayerMgr::DailyUpdate(uint64_t unixSec)
{
    NFPlayer *pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->DailyUpdate(unixSec);
        pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_LOGIC_PLAYER_ID, pPlayer));
    }
    return 0;
}

int NFPlayerMgr::WeekUpdate(uint64_t unixSec)
{
    NFPlayer *pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->WeekUpdate(unixSec);
        pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_LOGIC_PLAYER_ID, pPlayer));
    }
    return 0;
}

int NFPlayerMgr::DailyZeroUpdate(uint64_t unixSec)
{
    NFPlayer *pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->DailyZeroUpdate(unixSec);
        pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_LOGIC_PLAYER_ID, pPlayer));
    }
    return 0;
}

int NFPlayerMgr::WeekZeroUpdate(uint64_t unixSec)
{
    NFPlayer *pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->WeekZeroUpdate(unixSec);
        pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_LOGIC_PLAYER_ID, pPlayer));
    }
    return 0;
}

int NFPlayerMgr::OnTimer(int timeId, int callcount)
{
    uint64_t nowTime = NFServerTime::Instance()->UnixSec();
    if (m_dayZeroTimer == timeId)
    {
        DailyUpdate(nowTime);
        DailyZeroUpdate(nowTime);
    }
    else if (m_weekZeroTimer == timeId)
    {
        WeekUpdate(nowTime);
        WeekZeroUpdate(nowTime);
    }
    return 0;
}
