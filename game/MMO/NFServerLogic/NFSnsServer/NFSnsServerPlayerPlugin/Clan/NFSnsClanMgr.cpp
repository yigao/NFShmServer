// -------------------------------------------------------------------------
//    @FileName         :    NFSnsClanMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsClanMgr
//
// -------------------------------------------------------------------------

#include "NFSnsClanMgr.h"

NFSnsClanMgr::NFSnsClanMgr()
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

NFSnsClanMgr::~NFSnsClanMgr()
{
}

int NFSnsClanMgr::CreateInit()
{
    return 0;
}
    
int NFSnsClanMgr::ResumeInit()
{
    return 0;
}
