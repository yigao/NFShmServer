// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTeamMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTeamMgr
//
// -------------------------------------------------------------------------

#include "NFSnsTeamMgr.h"

NFSnsTeamMgr::NFSnsTeamMgr()
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

NFSnsTeamMgr::~NFSnsTeamMgr()
{
}

int NFSnsTeamMgr::CreateInit()
{
    return 0;
}
    
int NFSnsTeamMgr::ResumeInit()
{
    return 0;
}
