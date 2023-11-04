// -------------------------------------------------------------------------
//    @FileName         :    NFSoulPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFSoulPart
//
// -------------------------------------------------------------------------

#include "NFSoulPart.h"

NFSoulPart::NFSoulPart()
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

NFSoulPart::~NFSoulPart()
{
}

int NFSoulPart::CreateInit()
{
    return 0;
}

int NFSoulPart::ResumeInit()
{
    return 0;
}
