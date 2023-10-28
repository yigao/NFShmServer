// -------------------------------------------------------------------------
//    @FileName         :    NFDragonSoulPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDragonSoulPart
//
// -------------------------------------------------------------------------

#include "NFDragonSoulPart.h"

NFDragonSoulPart::NFDragonSoulPart()
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

NFDragonSoulPart::~NFDragonSoulPart()
{
}

int NFDragonSoulPart::CreateInit()
{
    return 0;
}

int NFDragonSoulPart::ResumeInit()
{
    return 0;
}
