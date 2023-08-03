// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDesk.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDesk
//
// -------------------------------------------------------------------------

#include "NFIGameDesk.h"

NFIGameDesk::NFIGameDesk()
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

NFIGameDesk::~NFIGameDesk()
{
}

int NFIGameDesk::CreateInit()
{
    return 0;
}

int NFIGameDesk::ResumeInit()
{
    return 0;
}
