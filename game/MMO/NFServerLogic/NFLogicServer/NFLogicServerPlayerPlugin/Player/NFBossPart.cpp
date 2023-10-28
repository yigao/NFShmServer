// -------------------------------------------------------------------------
//    @FileName         :    NFBossPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBossPart
//
// -------------------------------------------------------------------------

#include "NFBossPart.h"

NFBossPart::NFBossPart()
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

NFBossPart::~NFBossPart()
{
}

int NFBossPart::CreateInit()
{
    return 0;
}

int NFBossPart::ResumeInit()
{
    return 0;
}
