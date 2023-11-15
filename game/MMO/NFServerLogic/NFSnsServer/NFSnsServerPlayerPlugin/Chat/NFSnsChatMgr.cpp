// -------------------------------------------------------------------------
//    @FileName         :    NFSnsChatMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsChatMgr
//
// -------------------------------------------------------------------------

#include "NFSnsChatMgr.h"

NFSnsChatMgr::NFSnsChatMgr()
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

NFSnsChatMgr::~NFSnsChatMgr()
{
}

int NFSnsChatMgr::CreateInit()
{
    m_virForbidFlag = false;
    return 0;
}

int NFSnsChatMgr::ResumeInit()
{
    return 0;
}

bool NFSnsChatMgr::IsVirForbid(uint64_t cid)
{
    return m_setVirForbidCid.find(cid) != m_setVirForbidCid.end();
}
