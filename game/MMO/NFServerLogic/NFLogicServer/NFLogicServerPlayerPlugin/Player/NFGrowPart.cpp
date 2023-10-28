// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#include "NFGrowPart.h"

NFGrowPart::NFGrowPart()
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

NFGrowPart::~NFGrowPart()
{
}

int NFGrowPart::CreateInit()
{
    return 0;
}

int NFGrowPart::ResumeInit()
{
    return 0;
}
