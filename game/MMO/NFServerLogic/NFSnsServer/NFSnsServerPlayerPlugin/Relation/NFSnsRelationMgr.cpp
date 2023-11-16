// -------------------------------------------------------------------------
//    @FileName         :    NFSnsRelationMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsRelationMgr
//
// -------------------------------------------------------------------------

#include "NFSnsRelationMgr.h"

NFSnsRelationMgr::NFSnsRelationMgr()
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

NFSnsRelationMgr::~NFSnsRelationMgr()
{
}

int NFSnsRelationMgr::CreateInit()
{
    return 0;
}
    
int NFSnsRelationMgr::ResumeInit()
{
    return 0;
}
