// -------------------------------------------------------------------------
//    @FileName         :    NFClanMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFClanMgr
//
// -------------------------------------------------------------------------

#include "NFClanMgr.h"

NFClanMgr::NFClanMgr()
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

NFClanMgr::~NFClanMgr()
{
}

int NFClanMgr::CreateInit()
{
    return 0;
}
    
int NFClanMgr::ResumeInit()
{
    return 0;
}
