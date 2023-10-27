#include "TimelineDescEx.h"

TimelineDescEx::TimelineDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TimelineDescEx::~TimelineDescEx()
{
}

int TimelineDescEx::CreateInit()
{
	return 0;
}

int TimelineDescEx::ResumeInit()
{
	return 0;
}

int TimelineDescEx::Load()
{
	return 0;
}

int TimelineDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

