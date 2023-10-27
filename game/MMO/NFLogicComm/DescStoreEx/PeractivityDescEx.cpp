#include "PeractivityDescEx.h"

PeractivityDescEx::PeractivityDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PeractivityDescEx::~PeractivityDescEx()
{
}

int PeractivityDescEx::CreateInit()
{
	return 0;
}

int PeractivityDescEx::ResumeInit()
{
	return 0;
}

int PeractivityDescEx::Load()
{
	return 0;
}

int PeractivityDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

