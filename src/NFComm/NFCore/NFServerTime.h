// -------------------------------------------------------------------------
//    @FileName         :    NFServerTime.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <string>

#include "NFPlatform.h"
#include "NFTime.h"
#include "NFSingleton.hpp"

class _NFExport NFServerTime : public NFSingleton<NFServerTime>
{
public:
	NFServerTime();
	virtual ~NFServerTime();
public:
	bool Init(int fps);
	bool UnInit();
	bool Update(uint64_t tick);

public:
	uint64_t StartTick() { return ms_startTick; }
	uint32_t CurElapse() { return (uint32_t)(ms_curTick - ms_startTick); }
	uint64_t Tick() { return ms_curTick; }
	uint64_t LastTick() { return ms_lastTick; }
	int DeltaTick() { return ms_deltaTick; }
	uint64_t UnixSec() { return ms_unixSec; }
    uint64_t UnixMSec() { return ms_unixMSec; }
	uint64_t Frames() { return ms_frames; }
	uint64_t Secs() { return ms_secs; }
	int      GetFPS() { return ms_fps; }
	// 获得当日已过秒数(首日有16小时要去除)
	uint32_t CurDaySec() { return ((uint32_t)UnixSec() - 57600) % DayTotalSec(); };
	// 每日总秒数
	uint32_t DayTotalSec() { return msc_daySec; };
    // 服务器当前所在的时区
    int32_t CurTimeZone() { return ms_curzone; };

	bool CheckPerFrames(int perFrames) { return ms_frames % perFrames == 0; }
	bool CheckPerSecs(int perSecs) { return ms_secs % perSecs == 0 && ms_perSecFirstFrame; }
protected:
	uint64_t ms_startTick;
	uint64_t ms_curTick;          // 1 tick = 1 msec, cur update tick
	uint64_t ms_lastTick;         // 1 tick = 1 msec, last update tick
	int ms_deltaTick;             // 1 tick = 1 msec, ms_curTick - ms_lastTick
	uint64_t ms_unixSec;          // cur unix sec(cur frame is same)
    uint64_t ms_unixMSec;         // cur unix msec
	uint64_t ms_frames;           // frames count, from app start
	uint64_t ms_secs;             // seconds count, from app start
	bool     ms_perSecFirstFrame; // per sec the first frame is true
	int      ms_fps;              // fps
	const uint32_t msc_daySec = 86400;   // day total sec
private:
	uint64_t ms_lastUnixSec;      // last unix sec
	int32_t ms_curzone;			// current time zone

};
