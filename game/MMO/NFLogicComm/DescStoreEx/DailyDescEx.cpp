#include "DailyDescEx.h"

DailyDescEx::DailyDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DailyDescEx::~DailyDescEx()
{
}

int DailyDescEx::CreateInit()
{
	return 0;
}

int DailyDescEx::ResumeInit()
{
	return 0;
}

int DailyDescEx::Load()
{
	return 0;
}

int DailyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

