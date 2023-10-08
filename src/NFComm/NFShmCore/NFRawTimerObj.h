// -------------------------------------------------------------------------
//    @FileName         :    NFRawTimerObj.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFRawTimerObj
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFRawShmObj.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"

template<size_t MAX_TIMER_NUM>
class NFRawTimerObj : public NFRawShmObj
{
public:
    NFRawTimerObj()
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

    virtual ~NFRawTimerObj()
    {
        DeleteAllTimer();
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
public:
public:
    //delete objid
    virtual int DeleteTimer(int timeObjId)
    {
        CHECK_NULL(m_pShmObj);
        m_timerIdMap.erase(timeObjId);
        return m_pShmObj->DeleteTimer(timeObjId);
    }

    virtual int DeleteAllTimer()
    {
        CHECK_NULL(m_pShmObj);
        for (auto iter = m_timerIdMap.begin(); iter != m_timerIdMap.end();)
        {
            m_pShmObj->DeleteTimer(*iter);
            iter = m_timerIdMap.erase(iter);
        }
        m_timerIdMap.clear();
        return 0;
    }

    ////注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    virtual int SetTimer(int hour, int minutes, int second, int microSec)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetTimer(hour, minutes, second, microSec, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    virtual int SetCalender(int hour, int minutes, int second)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetCalender(hour, minutes, second, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    virtual int SetCalender(uint64_t timestamp)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetCalender(timestamp, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    virtual int SetTimer(int interval, int callcount, int hour, int minutes, int second, int microSec)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetTimer(interval, callcount, hour, minutes, second, microSec, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual  int SetDayTime(int callcount, int hour, int minutes, int second, int microSec)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetDayTime(callcount, hour, minutes, second, microSec, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    virtual  int SetDayCalender(int callcount, int hour, int minutes, int second)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetDayCalender(callcount, hour, minutes, second, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetWeekTime(int callcount, int hour, int minutes, int second, int microSec)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetWeekTime(callcount, hour, minutes, second, microSec, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    virtual int SetWeekCalender(int callcount, int weekDay, int hour, int minutes, int second)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetWeekCalender(callcount, weekDay, hour, minutes, second, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    virtual int SetMonthTime(int callcount, int hour, int minutes, int second, int microSec)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetMonthTime(callcount, hour, minutes, second, microSec, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }

    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    virtual int SetMonthCalender(int callcount, int day, int hour, int minutes, int second)
    {
        CHECK_NULL(m_pShmObj);
        CHECK_EXPR(m_timerIdMap.size() < m_timerIdMap.max_size(), -1, "m_timerIdMap space not enough");
        int timerId = m_pShmObj->SetMonthCalender(callcount, day, hour, minutes, second, this);
        if (timerId != INVALID_ID)
        {
            m_timerIdMap.insert(timerId);
        }
        return timerId;
    }
public:
    NFShmHashSet<int, MAX_TIMER_NUM> m_timerIdMap;
};