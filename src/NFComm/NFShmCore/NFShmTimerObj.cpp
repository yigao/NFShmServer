// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerObj.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmTimerObj.h"
#include "NFShmMgr.h"

NFShmTimerObj::NFShmTimerObj()
{
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
	{
		CreateInit();
	}
	else
	{
		ResumeInit();
	}
}


NFShmTimerObj::~NFShmTimerObj()
{

}

int NFShmTimerObj::CreateInit()
{
#ifdef NF_DEBUG_MODE
    m_shmTimerCount = 0;
#endif
	return 0;
}

int NFShmTimerObj::DeleteTimer(int timeObjId)
{
	int iRet = NFShmMgr::Instance()->DeleteTimer(this, timeObjId);
    if (iRet == 0)
    {
#ifdef NF_DEBUG_MODE
        if (m_shmTimerCount > 0)
        {
            m_shmTimerCount--;
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "error delete timer, m_shmTimerCount = 0");
        }
#endif
    }
    return iRet;
}

//注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
int NFShmTimerObj::SetTimer(int hour, int minutes, int second, int microSec)
{
	int timerId = NFShmMgr::Instance()->SetTimer(this, hour, minutes, second, microSec);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
int NFShmTimerObj::SetCalender(int hour, int minutes, int second)
{
    int timerId = NFShmMgr::Instance()->SetCalender(this, hour, minutes, second);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
int NFShmTimerObj::SetCalender(uint64_t timestamp)
{
    int timerId = NFShmMgr::Instance()->SetCalender(this, timestamp);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
int NFShmTimerObj::SetTimer(int interval, int callcount, int hour, int minutes, int second, int microSec)
{
    int timerId = NFShmMgr::Instance()->SetTimer(this, interval, callcount, hour, minutes, second, microSec);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmTimerObj::SetDayTime(int callcount, int hour, int minutes, int second, int microSec)
{
    int timerId = NFShmMgr::Instance()->SetDayTime(this, callcount, hour, minutes, second, microSec);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
int NFShmTimerObj::SetDayCalender(int callcount, int hour, int minutes, int second)
{
    int timerId = NFShmMgr::Instance()->SetDayCalender(this, callcount, hour, minutes, second);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmTimerObj::SetWeekTime(int callcount, int hour, int minutes, int second, int microSec)
{
    int timerId = NFShmMgr::Instance()->SetWeekTime(this, callcount, hour, minutes, second, microSec);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
int NFShmTimerObj::SetWeekCalender(int callcount, int weekDay, int hour, int minutes, int second)
{
    int timerId = NFShmMgr::Instance()->SetWeekCalender(this, callcount, weekDay, hour, minutes, second);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
int NFShmTimerObj::SetMonthTime(int callcount, int hour, int minutes, int second, int microSec)
{
    int timerId = NFShmMgr::Instance()->SetMonthTime(this, callcount, hour, minutes, second, microSec);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}

//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
int NFShmTimerObj::SetMonthCalender(int callcount, int day, int hour, int minutes, int second)
{
    int timerId = NFShmMgr::Instance()->SetMonthCalender(this, callcount, day, hour, minutes, second);
    if (timerId >= 0)
    {
#ifdef NF_DEBUG_MODE
        m_shmTimerCount++;
        if (m_shmTimerCount >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "m_shmTimerCount:{}, the obj has too much timer", m_shmTimerCount);
        }
#endif
    }
    return timerId;
}