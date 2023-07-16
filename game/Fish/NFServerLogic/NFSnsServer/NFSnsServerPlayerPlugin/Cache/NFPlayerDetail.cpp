// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#include "NFPlayerDetail.h"
#include "Part/NFSnsPart.h"
#include "NFCacheMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "Trans/NFSnsTransSaveDetailDB.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerDetail, EOT_SNS_ROLE_DETAIL_ID, NFShmObj)

NFPlayerDetail::NFPlayerDetail() : NFShmObj()
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

NFPlayerDetail::~NFPlayerDetail()
{
}

int NFPlayerDetail::CreateInit()
{
    m_playerId = 0;
    m_pPart.resize(SNS_PART_MAX);
    m_lastSavingDBTime = 0;
    return 0;
}

int NFPlayerDetail::ResumeInit()
{
    return 0;
}

uint64_t NFPlayerDetail::GetPlayerId() const
{
    return m_playerId;
}

void NFPlayerDetail::SetPlayerId(uint64_t roleId)
{
    m_playerId = roleId;
}

bool NFPlayerDetail::CanDelete()
{
    return true;
}

bool NFPlayerDetail::IsInited() const
{
    return m_isInited;
}

void NFPlayerDetail::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFPlayerDetail::Init(const proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer)
{
    m_isInited = true;
    m_playerId = data.player_id();

    ResetCurSeq();
    m_isInited = true;

    if (bCreatePlayer)
    {
        InitConfig(data);
    }
    else {
        LoadFromDB(data);
    }

    std::vector<NFSnsPart*> vec;
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        m_pPart[i] = CreatePart(i, data, bCreatePlayer);
        if (nullptr == m_pPart[i])
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Player Init, Create Part Failed, roleId:{} part:{}", m_playerId, i);
            for(int i = 0; i < (int)vec.size(); i++)
            {
                FindModule<NFISharedMemModule>()->DestroyObj(vec[i]);
            }
            return -1;
        }
        vec.push_back(m_pPart[i].GetPoint());
    }

    return 0;
}

int NFPlayerDetail::UnInit()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            RecylePart(m_pPart[i]);
        }
    }

    return 0;
}

NFSnsPart* NFPlayerDetail::CreatePart(NFIPluginManager* pObjPluginManager, uint32_t partType)
{
    NFSnsPart *pPart = NULL;
    switch (partType)
    {
        default:
        {
            break;
        }
    }

    if (pPart)
    {
        pPart->SetPartType(partType);
    }
    return pPart;
}

NFSnsPart *NFPlayerDetail::CreatePart(uint32_t partType, const proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer)
{
    NFSnsPart *pPart = NULL;
    switch (partType)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Create Part Failed, partType Not Handle:{}", partType);
            break;
        }
    }

    if (pPart)
    {
        int iRet = pPart->Init(this, partType, data, bCreatePlayer);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}::Init Failed", pPart->GetClassName());
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
            return NULL;
        }
    }
    return pPart;
}

int NFPlayerDetail::RecylePart(NFSnsPart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

NFSnsPart *NFPlayerDetail::GetPart(uint32_t partType)
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }

    return NULL;
}

NFPlayerSimple *NFPlayerDetail::GetRoleSimple() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_playerId);
}

int NFPlayerDetail::OnLogin()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin();
        }
    }
    return 0;
}

int NFPlayerDetail::OnLogout()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogout();
        }
    }
    return 0;
}

int NFPlayerDetail::OnDisconnect()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnDisconnect();
        }
    }
    return 0;
}

int NFPlayerDetail::OnReconnect()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnReconnect();
        }
    }
    return 0;
}

int NFPlayerDetail::LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    return 0;
}

int NFPlayerDetail::SaveDB(proto_ff::tbFishSnsPlayerDetailData &data)
{
    data.set_player_id(GetPlayerId());
    return 0;
}

int NFPlayerDetail::InitConfig(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    return 0;
}

int NFPlayerDetail::Update()
{
    return 0;
}

int NFPlayerDetail::SaveToDB(bool bForce)
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

int NFPlayerDetail::SendTransToDB()
{
    NFSnsTransSaveDetailDB* pSave = (NFSnsTransSaveDetailDB*) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_SAVE_PLAYER_DETAIL);
    CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveDB Failed! ");

    int iRet = pSave->SaveDB(this);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }

    return iRet;
}

int NFPlayerDetail::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetAllSeq())
    {
        ClearAllSeq();
    }
    return 0;
}

uint32_t NFPlayerDetail::GetAllSeq()
{
    uint32_t seq = GetCurSeq();
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            seq += m_pPart[i]->GetCurSeq();
        }
    }
    return seq;
}

void NFPlayerDetail::ClearAllSeq()
{
    ClearUrgent();
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->ClearUrgent();
        }
    }
}

int NFPlayerDetail::DailyZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->DailyZeroUpdate();
        }
    }
    return 0;
}

int NFPlayerDetail::WeekZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->WeekZeroUpdate();
        }
    }
    return 0;
}

int NFPlayerDetail::MonthZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->MonthZeroUpdate();
        }
    }
    return 0;
}


