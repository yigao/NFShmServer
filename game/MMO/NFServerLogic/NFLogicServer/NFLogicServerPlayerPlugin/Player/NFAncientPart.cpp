// -------------------------------------------------------------------------
//    @FileName         :    NFAncientPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAncientPart
//
// -------------------------------------------------------------------------

#include "NFAncientPart.h"

NFAncientPart::NFAncientPart()
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

NFAncientPart::~NFAncientPart()
{
}

int NFAncientPart::CreateInit()
{
    return 0;
}

int NFAncientPart::ResumeInit()
{
    return 0;
}
