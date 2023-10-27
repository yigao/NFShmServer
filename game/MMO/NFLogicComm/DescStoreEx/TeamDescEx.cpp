#include "TeamDescEx.h"

TeamDescEx::TeamDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TeamDescEx::~TeamDescEx()
{
}

int TeamDescEx::CreateInit()
{
	return 0;
}

int TeamDescEx::ResumeInit()
{
	return 0;
}

int TeamDescEx::Load()
{
	return 0;
}

int TeamDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

