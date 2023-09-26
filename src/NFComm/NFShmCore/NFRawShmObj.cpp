// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerObj.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTimerObj
//
// -------------------------------------------------------------------------

#include "NFRawShmObj.h"

NFRawShmObj::NFRawShmObj():NFObject(NULL)
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
}

int NFRawShmObj::CreateInit()
{
    m_shmObj = nullptr;
    return 0;
}

int NFRawShmObj::ResumeInit()
{
    return 0;
}

int NFRawShmObj::Init(NFShmObj* pShmObj)
{
    m_shmObj = pShmObj;
    m_pObjPluginManager = pShmObj->m_pObjPluginManager;
    return 0;
}

int NFRawShmObj::OnTimer(int timeId, int callcount)
{
    return 0;
}