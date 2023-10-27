// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#include "NFPlayerSimple.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "Trans/NFSnsTransSaveSimpleDB.h"
#include "Trans/NFSnsTransSaveDetailDB.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFCacheMgr.h"

NFPlayerSimple::NFPlayerSimple()
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

NFPlayerSimple::~NFPlayerSimple()
{
}

int NFPlayerSimple::CreateInit()
{
    m_isInited = false;
    m_lastSavingDBTime = 0;
    m_saveDBTimer = INVALID_ID;
    return 0;
}

bool NFPlayerSimple::IsInited() const
{
    return m_isInited;
}

void NFPlayerSimple::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFPlayerSimple::ResumeInit()
{
    return 0;
}

int NFPlayerSimple::OnTimer(int timeId, int callcount)
{
    if (timeId == m_saveDBTimer)
    {
        SaveToDB();
    }
    return 0;
}

uint64_t NFPlayerSimple::GetCid() const
{
    return m_data.cid;
}

void NFPlayerSimple::SetCid(uint64_t cid)
{
    m_data.cid = cid;
}

const proto_ff_s::RoleDBSnsSimple_s &NFPlayerSimple::GetBaseData() const
{
    return m_data;
}

void NFPlayerSimple::SetBaseData(const proto_ff_s::RoleDBSnsSimple_s &baseData)
{
    m_data = baseData;
}

void NFPlayerSimple::ReadFromPB(const proto_ff::RoleDBSnsSimple& dbData)
{
    m_data.read_from_pbmsg(dbData);
}

int NFPlayerSimple::OnLogin()
{
    return 0;
}

int NFPlayerSimple::OnLogout()
{
    return 0;
}

int NFPlayerSimple::OnDisconnect()
{
    return 0;
}

int NFPlayerSimple::OnReconnect()
{
    return 0;
}


bool NFPlayerSimple::CanDelete()
{
    if (NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(GetCid()))
    {
        return false;
    }

    if (FindModule<NFICoroutineModule>()->IsExistUserCo(GetCid()))
    {
        return false;
    }
    return true;
}

int NFPlayerSimple::Init(const proto_ff::RoleDBSnsSimple &dbData)
{
    m_isInited = true;
    LoadFromDB(dbData);
    InitConfig(dbData);

    /**
     * @brief
     */
    uint32_t startMS = NFRandInt(1000, LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000);
    m_saveDBTimer = SetTimer(LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000, 0, 0, 0, 0, startMS);
    return 0;
}

int NFPlayerSimple::UnInit()
{
    return 0;
}

int NFPlayerSimple::SaveToDB(bool bForce)
{
    if (IsUrgentNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB();
        }
    }
    return 0;
}

int NFPlayerSimple::SendTransToDB()
{
/*    NFSnsTransSaveSimpleDB* pSave = (NFSnsTransSaveSimpleDB*) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE);
    CHECK_EXPR(pSave, -1, "Create Trans:NFSnsTransSaveSimpleDB Failed! ");

    int iRet = pSave->SaveDB(this);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }

    return iRet;*/
    m_lastSavingDBTime = 0;
    ClearUrgent();
    return 0;
}

int NFPlayerSimple::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetCurSeq())
    {
        ClearUrgent();
    }
    return 0;
}

int NFPlayerSimple::LoadFromDB(const proto_ff::RoleDBSnsSimple &dbData)
{
    m_data.read_from_pbmsg(dbData);
    return 0;
}

int NFPlayerSimple::SaveDB(proto_ff::RoleDBSnsSimple &dbData)
{
    m_data.write_to_pbmsg(dbData);
    return 0;
}

int NFPlayerSimple::InitConfig(const proto_ff::RoleDBSnsSimple &dbData)
{
    m_data.read_from_pbmsg(dbData);
    return 0;
}
