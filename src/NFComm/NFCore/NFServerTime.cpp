// -------------------------------------------------------------------------
//    @FileName         :    NFServerTime.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFServerTime.h"

uint64_t NFServerTime::ms_startTick = 0;
uint64_t NFServerTime::ms_curTick = 0;
uint64_t NFServerTime::ms_lastTick = 0;
int      NFServerTime::ms_deltaTick = 0;
uint64_t NFServerTime::ms_unixSec = 0;
uint64_t NFServerTime::ms_frames = 0;
uint64_t NFServerTime::ms_secs = 0;
bool     NFServerTime::ms_perSecFirstFrame = 0;
uint64_t NFServerTime::ms_lastUnixSec = 0;
int      NFServerTime::ms_fps = 0;

NFServerTime::NFServerTime()
{}

NFServerTime::~NFServerTime()
{}

bool NFServerTime::Init(int fps)
{
	ms_fps = fps;
	ms_curTick = NFTime::Now().Tick();
	ms_startTick = ms_curTick;
	ms_lastTick = ms_curTick;
	ms_deltaTick = 0;
	ms_unixSec = NFTime::Now().UnixSec();
	ms_frames = 0;
	ms_secs = 0;
	ms_perSecFirstFrame = false;
	ms_lastUnixSec = ms_unixSec;
	return true;
}

bool NFServerTime::UnInit()
{
	return true;
}

bool NFServerTime::Update(uint64_t tick)
{
	ms_lastTick = ms_curTick;
	ms_curTick = tick;
	ms_deltaTick = (int)(ms_curTick - ms_lastTick);
	ms_unixSec = NFTime::Now().UnixSec();

	++ms_frames;

	if (ms_lastUnixSec - ms_unixSec > 0)
	{
		ms_secs += ms_unixSec - ms_lastUnixSec;
		ms_lastUnixSec = ms_unixSec;
		ms_perSecFirstFrame = true;
	}
	else
	{
		ms_perSecFirstFrame = false;
	}

	return true;
}

