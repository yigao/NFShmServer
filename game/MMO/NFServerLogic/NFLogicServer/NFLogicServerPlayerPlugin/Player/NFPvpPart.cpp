// -------------------------------------------------------------------------
//    @FileName         :    NFPvpPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFPvpPart
//
// -------------------------------------------------------------------------

#include "NFPvpPart.h"

NFPvpPart::NFPvpPart()
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

NFPvpPart::~NFPvpPart()
{
}

int NFPvpPart::CreateInit()
{
    return 0;
}

int NFPvpPart::ResumeInit()
{
    return 0;
}
