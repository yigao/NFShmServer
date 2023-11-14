// -------------------------------------------------------------------------
//    @FileName         :    NFRunePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFRunePart
//
// -------------------------------------------------------------------------

#include "NFRunePart.h"

NFRunePart::NFRunePart()
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

NFRunePart::~NFRunePart()
{
}

int NFRunePart::CreateInit()
{
    return 0;
}

int NFRunePart::ResumeInit()
{
    return 0;
}
