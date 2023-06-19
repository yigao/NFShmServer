// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#include "NFRoleDetail.h"
#include "Part/NFSnsPart.h"
#include "NFCacheMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRoleDetail, EOT_SNS_ROLE_DETAIL_ID, NFShmObj)

NFRoleDetail::NFRoleDetail() : NFShmObj()
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

NFRoleDetail::~NFRoleDetail()
{
}

int NFRoleDetail::CreateInit()
{
    m_cid = 0;
    m_pPart.resize(SNS_PART_MAX);
    return 0;
}

int NFRoleDetail::ResumeInit()
{
    return 0;
}

uint64_t NFRoleDetail::GetRoleId() const
{
    return m_cid;
}

void NFRoleDetail::SetRoleId(uint64_t roleId)
{
    m_cid = roleId;
}

bool NFRoleDetail::CanDelete()
{
    return true;
}

bool NFRoleDetail::IsInited() const
{
    return m_isInited;
}

void NFRoleDetail::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFRoleDetail::Init(const proto_ff::RoleDBSnsDetail &data)
{
    m_isInited = true;
    m_cid = data.cid();

    ResetCurSeq();
    m_isInited = true;

    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        NFSnsPart *pPart = CreatePart(i, data);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Create Part Failed, roleId:{} part:{}", m_cid, i);
            return -1;
        }

        m_pPart[i] = pPart->GetGlobalID();
    }

    return 0;
}

NFSnsPart *NFRoleDetail::CreatePart(uint32_t partType, const proto_ff::RoleDBSnsDetail &data)
{
    NFSnsPart *pPart = NULL;
    switch (partType)
    {
        case SNS_PART_RELATION:
        {
            pPart = dynamic_cast<NFSnsPart *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_SNS_RelationPart_ID));
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Create Part Failed, partType Not Handle:{}", partType);
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

int NFRoleDetail::RecylePart(NFSnsPart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

NFSnsPart *NFRoleDetail::GetPart(uint32_t partType)
{
    if (partType <= 0 || partType >= m_pPart.size())
    {
        return nullptr;
    }

    return dynamic_cast<NFSnsPart *>(FindModule<NFISharedMemModule>()->GetObjByGlobalID(EOT_SNS_PART_ID, m_pPart[partType], false));
}

NFRoleSimple *NFRoleDetail::GetRoleSimple() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleSimple(m_cid);
}
