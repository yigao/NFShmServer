// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerObj.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTimerObj
//
// -------------------------------------------------------------------------

#include "NFRawShmObj.h"

NFRawShmObj::NFRawShmObj()
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

NFRawShmObj::~NFRawShmObj()
{
    DeleteAllTimer();
}

int NFRawShmObj::CreateInit()
{
    m_pShmObj = nullptr;
    return 0;
}

int NFRawShmObj::ResumeInit()
{
    return 0;
}

int NFRawShmObj::InitShmObj(NFShmObj* pShmObj)
{
    m_pShmObj = pShmObj;
    return 0;
}

NFShmObj* NFRawShmObj::GetShmObj()
{
    return m_pShmObj.GetPoint();
}

NFIPluginManager* NFRawShmObj::GetPluginManager()
{
    if (m_pShmObj)
    {
        return m_pShmObj->m_pObjPluginManager;
    }
    return nullptr;
}


int NFRawShmObj::OnTimer(int timeId, int callcount)
{
    return 0;
}