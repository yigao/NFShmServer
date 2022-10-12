// -------------------------------------------------------------------------
//    @FileName         :    NFServerTime.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFServerTime.h"

NFServerTime::NFServerTime()
{
    ms_startTick = 0;
    ms_curTick = 0;
    ms_lastTick = 0;
    ms_deltaTick = 0;
    ms_unixSec = 0;
    ms_frames = 0;
    ms_secs = 0;
    ms_perSecFirstFrame = 0;
    ms_lastUnixSec = 0;
    ms_fps = 0;
}

NFServerTime::~NFServerTime()
{

}

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
    ms_curzone = (NFTime::Now().GetCurTimeZone())/3600;
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
    ms_deltaTick = (int) (ms_curTick - ms_lastTick);
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

