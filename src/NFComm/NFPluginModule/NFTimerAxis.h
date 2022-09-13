// -------------------------------------------------------------------------
//    @FileName         :    NFTimerAxis.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once
#include <list>
#include <vector>
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFTimerObj.h"
#include "NFComm/NFCore/NFTime.h"

//时间轴检查频率 ms
#define TIMER_AXIS_CHECK_FREQUENCE 32
//时间轴刻度
#define TIME_GRID 64
//时间轴长度
#define TIME_AXIS_LENGTH			120000		// 毫秒为单位的
#define TIME_AXIS_SECLENGTH			108000		// 秒为单位的支持到30个小时
#define INVALID_TIMER				0xffffffff  // 无效定时器
#define INFINITY_CALL				0xffffffff	// 调用无限次

//时间轴
class _NFExport NFTimerAxis
{
public:
	NFTimerAxis();
	virtual ~NFTimerAxis();

	bool Init();
	bool UnInit();

	//设置定时器
	bool SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL);
	//关闭定时器
	bool KillTimer(uint32_t nTimerID, NFTimerObj* handler);
	//关闭所有定时器
	bool KillAllTimer(NFTimerObj* handler);
	//更新定时器
	void Update();

	//设置固定时间的定时器
	bool SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterSec, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL);
	bool SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL);

private:
	//设置秒定时器
	bool SetTimerSec(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL);
	//检查tick
	void CheckTick();
	//更新秒定时器
	void UpdateSec();

protected:
	static uint64_t GetTick()
	{
		return NFTime::Now().UnixMSec();
	}

	static uint64_t GetUnixSec()
	{
		return NFTime::Now().UnixSec();
	}

	struct Timer
	{
		uint32_t nTimerID; //定时器ID
		uint64_t nInterVal; //间隔
		uint32_t nCallCount; //调用次数
		uint64_t nLastTick; //最后一次tick
		NFTimerObj* pHandler;//回调指针
		uint8_t byType; //类型 0 - 毫秒定时器， 1 - 秒定时器
		uint32_t nGridIndex; //所在的时间刻度
		std::list<Timer*>::iterator pos; //在时间轴中的位置，便于快速定位
		Timer()
		{
			nTimerID = 0;
			nInterVal = 0;
			nCallCount = 0;
			nLastTick = 0;
			pHandler = nullptr;
			byType = 0;
			nGridIndex = 0;
		}
	};

	//重置定时器在时间轴上的位置
	static bool ResetTimerPos(Timer* pTimer);

	typedef std::list<Timer*> TIMER_LIST; //某个刻度中定时器列表
	typedef std::vector<TIMER_LIST*> TIMER_AXIS; //所有事件轴的定时器

	TIMER_AXIS m_TimerAxis; //毫秒事件轴
	uint64_t m_nInitTick; //毫秒时间轴初始Tick
	uint64_t m_nLastTick; //毫秒时间轴最后一次检查的tick

	TIMER_AXIS m_TimerAxisSec; //秒时间轴
	uint64_t m_nInitSec; //秒时间轴初始时间
	uint64_t m_nLastSec; //秒时间轴最后一次检查的时间
};

