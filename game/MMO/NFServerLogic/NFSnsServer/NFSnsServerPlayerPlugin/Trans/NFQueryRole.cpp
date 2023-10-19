// -------------------------------------------------------------------------
//    @FileName         :    NFQueryRole.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFQueryRole
//
// -------------------------------------------------------------------------

#include "NFQueryRole.h"

NFQueryRole::NFQueryRole()
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

NFQueryRole::~NFQueryRole()
{
}

int NFQueryRole::CreateInit()
{
    m_queryedNum = 0;
    m_roleId = 0;
    m_queryedDetailNum = 0;
    return 0;
}

int NFQueryRole::ResumeInit()
{
    return 0;
}

int NFQueryRole::Add(uint64_t roleId)
{
    if (roleId == 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "query role:{} failed, ownerId:{}", roleId, m_roleId);
        return -1;
    }

    if (m_queryRoleList.size() >= m_queryRoleList.max_size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "query role list full, add role:{} failed, ownerId:{}", roleId, m_roleId);
        return -1;
    }

    if (m_roleId == 0)
    {
        m_roleId = roleId;
    }

    m_queryRoleList.push_back(roleId);
    return 0;
}
