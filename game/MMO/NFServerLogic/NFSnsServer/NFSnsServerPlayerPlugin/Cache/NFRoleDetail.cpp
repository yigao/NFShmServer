// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#include "NFRoleDetail.h"

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
    m_roleId = 0;
    return 0;
}

int NFRoleDetail::ResumeInit()
{
    return 0;
}

uint64_t NFRoleDetail::GetRoleId() const
{
    return m_roleId;
}

void NFRoleDetail::SetRoleId(uint64_t roleId)
{
    m_roleId = roleId;
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
    return 0;
}
