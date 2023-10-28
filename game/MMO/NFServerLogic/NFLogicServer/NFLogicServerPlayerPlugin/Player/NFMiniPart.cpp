// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#include "NFMiniPart.h"

NFMiniPart::NFMiniPart()
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

NFMiniPart::~NFMiniPart()
{
}

int NFMiniPart::CreateInit()
{
    return 0;
}

int NFMiniPart::ResumeInit()
{
    return 0;
}
