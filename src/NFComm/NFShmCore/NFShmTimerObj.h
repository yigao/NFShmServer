// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerObj.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFShmDefine.h"
#include "NFDynamicHead.h"
#include "NFTypeDefines.h"
#include "NFShmMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

class NFShmTimerObj
{
public:
	NFShmTimerObj();
	virtual ~NFShmTimerObj();

	//非继承函数, 不要加virtual
	int CreateInit();

    //非继承函数, 不要加virtual
	int ResumeInit()
	{
		return 0;
	}

	//must be virtual
	virtual void OnTimer(int timeId, int callcount) = 0;

	//delete objid
	virtual int DeleteTimer(int timeObjId);

	////注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
	virtual int SetTimer(int hour, int minutes, int second, int microSec);

	//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
	virtual int SetCalender(int hour, int minutes, int second);

	//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
	virtual  int SetCalender(uint64_t timestamp);

	//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
	virtual int SetTimer(int interval, int callcount, int hour, int minutes, int second, int microSec);

	//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
	virtual  int SetDayTime(int callcount, int hour, int minutes, int second, int microSec);

	//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
	virtual  int SetDayCalender(int callcount, int hour, int minutes, int second);

	//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
	virtual int SetWeekTime(int callcount, int hour, int minutes, int second, int microSec);

	//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
	virtual int SetWeekCalender(int callcount, int weekDay, int hour, int minutes, int second);

	//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
	virtual int SetMonthTime(int callcount, int hour, int minutes, int second, int microSec);

	//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
	virtual int SetMonthCalender(int callcount, int day, int hour, int minutes, int second);
protected:
#ifdef NF_DEBUG_MODE
    uint32_t m_shmTimerCount;
#endif
};
