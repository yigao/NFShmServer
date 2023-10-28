// -------------------------------------------------------------------------
//    @FileName         :    NFEncylopediaPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEncylopediaPart
//
// -------------------------------------------------------------------------

#include "NFEncylopediaPart.h"

NFEncylopediaPart::NFEncylopediaPart()
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

NFEncylopediaPart::~NFEncylopediaPart()
{
}

int NFEncylopediaPart::CreateInit()
{
    return 0;
}

int NFEncylopediaPart::ResumeInit()
{
    return 0;
}
