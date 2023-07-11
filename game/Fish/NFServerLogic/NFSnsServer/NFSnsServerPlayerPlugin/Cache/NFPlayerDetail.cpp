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
    return 0;
}

int NFPlayerDetail::ResumeInit()
{
    return 0;
}

uint64_t NFPlayerDetail::GetRoleId() const
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

int NFPlayerDetail::Init(const proto_ff::tbFishSnsPlayerData &data)
{
    m_isInited = true;
    m_playerId = data.player_id();

    ResetCurSeq();
    m_isInited = true;

    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        NFSnsPart *pPart = CreatePart(i, data);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Player Init, Create Part Failed, roleId:{} part:{}", m_playerId, i);
            return -1;
        }

        m_pPart[i] = pPart->GetGlobalId();
    }

    return 0;
}

NFSnsPart *NFPlayerDetail::CreatePart(uint32_t partType, const proto_ff::tbFishSnsPlayerData &data)
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
        pPart->InitBase(this, partType);
        int iRet = pPart->Init(data);
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
    if (partType <= 0 || partType >= m_pPart.size())
    {
        return nullptr;
    }

    return dynamic_cast<NFSnsPart *>(FindModule<NFISharedMemModule>()->GetObjByGlobalId(EOT_SNS_PART_ID, m_pPart[partType], false));
}

NFPlayerSimple *NFPlayerDetail::GetRoleSimple() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleSimple(m_playerId);
}
