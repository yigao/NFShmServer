#include "PathDescEx.h"

PathDescEx::PathDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PathDescEx::~PathDescEx()
{
}

int PathDescEx::CreateInit()
{
	return 0;
}

int PathDescEx::ResumeInit()
{
	return 0;
}

int PathDescEx::Load()
{
	return 0;
}

int PathDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

