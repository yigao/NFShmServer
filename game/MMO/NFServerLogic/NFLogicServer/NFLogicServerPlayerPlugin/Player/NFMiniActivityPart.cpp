// -------------------------------------------------------------------------
//    @FileName         :    NFMIniActivity.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMIniActivity
//
// -------------------------------------------------------------------------

#include "NFMiniActivityPart.h"

NFMiniActivityPart::NFMiniActivityPart()
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

NFMiniActivityPart::~NFMiniActivityPart()
{
}

int NFMiniActivityPart::CreateInit()
{
    return 0;
}

int NFMiniActivityPart::ResumeInit()
{
    return 0;
}
