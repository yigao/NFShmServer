// -------------------------------------------------------------------------
//    @FileName         :    NFFestMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestMgr
//
// -------------------------------------------------------------------------

#include "NFFestMgr.h"

NFFestMgr::NFFestMgr()
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

NFFestMgr::~NFFestMgr()
{
}

int NFFestMgr::CreateInit()
{
    m_lasttime = 0;
    m_checkTimer = SetTimer(3000, 0, 0, 0, 3, 0);
    return 0;
}

int NFFestMgr::ResumeInit()
{
    return 0;
}

int NFFestMgr::OnTimer(int timeId, int callcount)
{
    if (timeId == m_checkTimer)
    {
        OnCheckTimer();
    }
    return 0;
}

int NFFestMgr::OnCheckTimer()
{
    return 0;
}
