// -------------------------------------------------------------------------
//    @FileName         :    NFSnsUserSimpleHashTable.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsUserSimpleHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFSnsUserSimpleMgr.h"
#include "NFSnsUserSimple.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsUserSimpleMgr, EOT_SNS_USER_SIMPLE_HASH_TABLE_ID, NFShmObj)

NFSnsUserSimpleMgr::NFSnsUserSimpleMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFSnsUserSimpleMgr::~NFSnsUserSimpleMgr()
{
	if (m_saveDBTimer != INVALID_ID)
	{
		DeleteTimer(m_saveDBTimer);
		m_saveDBTimer = INVALID_ID;
	}

    if (m_dayTick != INVALID_ID)
    {
        DeleteTimer(m_dayTick);
        m_dayTick = INVALID_ID;
    }

    if (m_weekTick != INVALID_ID)
    {
        DeleteTimer(m_weekTick);
        m_weekTick = INVALID_ID;
    }

    if (m_monthTick != INVALID_ID)
    {
        DeleteTimer(m_monthTick);
        m_monthTick = INVALID_ID;
    }
}

int NFSnsUserSimpleMgr::CreateInit() {
    m_saveDBTimer = INVALID_ID;
    m_dayTick = INVALID_ID;
    m_weekTick = INVALID_ID;
    m_monthTick = INVALID_ID;
    return 0;
}

int NFSnsUserSimpleMgr::Init()
{
    if (m_saveDBTimer == INVALID_ID)
    {
        m_saveDBTimer = SetTimer(SNSSVR_USER_SIMPLE_SAVE_TIME, 0, 0, 0, 10, 0);
    }

    if (m_dayTick == INVALID_ID)
    {
        m_dayTick = SetDayCalender(0, 0, 0, 0);
    }

    if (m_weekTick == INVALID_ID)
    {
        m_weekTick = SetWeekCalender(0, 1, 0, 0, 0);
    }

    if (m_monthTick == INVALID_ID)
    {
        m_monthTick = SetMonthCalender(0, 1, 0, 0, 0);
    }
    return 0;
}


int NFSnsUserSimpleMgr::ResumeInit() {
    return 0;
}

NFSnsUserSimple *NFSnsUserSimpleMgr::GetUser(uint64_t userId)
{
	return dynamic_cast<NFSnsUserSimple*>(NFShmMgr::Instance()->GetObjFromHashKey(userId, EOT_SNS_USER_SIMPLE_ID));
}

NFSnsUserSimple *NFSnsUserSimpleMgr::CreateUser(uint64_t userId)
{
    NFSnsUserSimple *pPlayer = GetUser(userId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create User Simple Failed, player exist, palyerId:{}", userId);

	if (NFSnsUserSimple::GetItemCount() - NFSnsUserSimple::GetUsedCount() <= NFSnsUserSimple::GetItemCount()*0.1)
	{
		ReleaseCount(NFSnsUserSimple::GetItemCount()*0.1);
	}

    pPlayer = dynamic_cast<NFSnsUserSimple *>(NFShmMgr::Instance()->CreateObj(userId, EOT_SNS_USER_SIMPLE_ID));
    CHECK_EXPR(pPlayer, NULL, "Create User Simple Obj Failed, playerID:{}", userId);

    pPlayer->m_userData.userid = userId;
    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Add User Simple Success, userId:{} globalId:{}", userId,
              pPlayer->GetGlobalID());
    return pPlayer;
}

int NFSnsUserSimpleMgr::DeleteUser(NFSnsUserSimple *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete Simple Info, UserId:{}, gloablId:{}", pPlayer->m_userData.userid, pPlayer->GetGlobalID());

    NFShmMgr::Instance()->DestroyObj(pPlayer);

    return 0;
}

void NFSnsUserSimpleMgr::OnTimer(int timeId, int callcount)
{
	if (m_saveDBTimer == timeId)
	{
		SaveUserSimpleToDB();
	}
	else if (m_dayTick == timeId)
    {
	    DayTick();
    }
	else if (m_weekTick == timeId)
    {
	    WeekTick();
    }
	else if (m_monthTick == timeId)
    {
	    MonthTick();
    }
}

int NFSnsUserSimpleMgr::SaveUserSimpleToDB()
{
    NFSnsUserSimple *pUser = dynamic_cast<NFSnsUserSimple*>(NFShmMgr::Instance()->GetHeadObj(EOT_SNS_USER_SIMPLE_ID));
    while(pUser)
    {
        pUser->SaveToDB(false);
        pUser = dynamic_cast<NFSnsUserSimple*>(NFShmMgr::Instance()->GetNextObj(EOT_SNS_USER_SIMPLE_ID, pUser));
    }
	return 0;
}

int NFSnsUserSimpleMgr::ReleaseCount(int num)
{
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "rolesimple release count :{} maxcount :{} usecount :{}", num, NFSnsUserSimple::GetItemCount(), NFSnsUserSimple::GetUsedCount());
	NFShmMgr::Instance()->DestroyObjAutoErase(EOT_SNS_USER_SIMPLE_ID, NFSnsUserSimple::GetItemCount() >= num ? NFSnsUserSimple::GetItemCount() - num : 0, [](NFShmObj* pObj) -> bool {
        NFSnsUserSimple *pUser = dynamic_cast<NFSnsUserSimple*>(pObj);
        if (pUser)
        {
            if (pUser->CanDelete())
            {
                return true;
            }
        }
        return false;
    });
	return 0;
}

int NFSnsUserSimpleMgr::DayTick() {
    std::string sql = "update tbUserDetailData set today_win = 0, today_give = 0, today_recharge = 0, today_draw = 0;";

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                     proto_ff::E_STORESVR_C2S_EXECUTE, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", sql,
                                                     0, 0, 0);
    return 0;
}

int NFSnsUserSimpleMgr::WeekTick() {
    std::string sql = "update tbUserDetailData set week_win = 0, week_give = 0, week_recharge = 0, week_draw = 0;";

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                     proto_ff::E_STORESVR_C2S_EXECUTE, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", sql,
                                                     0, 0, 0);
    return 0;
}

int NFSnsUserSimpleMgr::MonthTick() {
    std::string sql = "update tbUserDetailData set month_win = 0, month_give = 0, month_recharge = 0, month_draw = 0;";

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                     proto_ff::E_STORESVR_C2S_EXECUTE, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", sql,
                                                     0, 0, 0);
    return 0;
}



