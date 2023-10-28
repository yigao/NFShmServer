// -------------------------------------------------------------------------
//    @FileName         :    NFVipPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFVipPart
//
// -------------------------------------------------------------------------

#include "NFVipPart.h"

NFVipPart::NFVipPart()
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

NFVipPart::~NFVipPart()
{
}

int NFVipPart::CreateInit()
{
    return 0;
}

int NFVipPart::ResumeInit()
{
    return 0;
}
