// -------------------------------------------------------------------------
//    @FileName         :    NFLoginQueue.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/13
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginQueue
//
// -------------------------------------------------------------------------

#include "NFLoginQueue.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

NFLoginQueue::NFLoginQueue()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFLoginQueue::~NFLoginQueue()
{
}

int NFLoginQueue::CreateInit()
{
    m_uid = 0;
    m_lastReqTime = 0;
    return 0;
}

int NFLoginQueue::ResumeInit()
{
    return 0;
}

uint64_t NFLoginQueue::GetUid() const
{
    return m_uid;
}

void NFLoginQueue::SetUid(uint64_t playerId)
{
    m_uid = playerId;
}

uint64_t NFLoginQueue::GetLastReqTime() const
{
    return m_lastReqTime;
}

void NFLoginQueue::SetLastReqTime(uint64_t lastReqTime)
{
    m_lastReqTime = lastReqTime;
}
