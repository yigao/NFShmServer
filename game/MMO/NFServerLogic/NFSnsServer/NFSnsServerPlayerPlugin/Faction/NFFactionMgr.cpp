// -------------------------------------------------------------------------
//    @FileName         :    NFFactionMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFFactionMgr
//
// -------------------------------------------------------------------------

#include "NFFactionMgr.h"

NFSnsFactionMgr::NFSnsFactionMgr()
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

NFSnsFactionMgr::~NFSnsFactionMgr()
{
}

int NFSnsFactionMgr::CreateInit()
{
    return 0;
}
    
int NFSnsFactionMgr::ResumeInit()
{
    return 0;
}
