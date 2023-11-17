// -------------------------------------------------------------------------
//    @FileName         :    NFISaveDB.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFISaveDB
//
// -------------------------------------------------------------------------

#include "NFISaveDB.h"

#include "NFLogicCommon.h"

NFISaveDB::NFISaveDB()
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

NFISaveDB::~NFISaveDB()
{
}

int NFISaveDB::CreateInit()
{
    m_lastSavingDBTime = 0;
    m_saveDBTimer = INVALID_ID;
    return 0;
}


int NFISaveDB::ResumeInit()
{
    return 0;
}


bool NFISaveDB::IsNeedSave()
{
    if (IsUrgentNeedSave())
    {
        return true;
    }
    return true;
}

int NFISaveDB::SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
    return 0;
}

int NFISaveDB::SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason, bool bForce)
{
    if (IsNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB(iReason);
        }
    }
    return 0;
}

int NFISaveDB::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetAllSeq())
    {
        ClearAllSeq();
    }
    return 0;
}

uint32_t NFISaveDB::GetAllSeq()
{
    return GetCurSeq();
}

void NFISaveDB::ClearAllSeq()
{
    ClearUrgent();
}