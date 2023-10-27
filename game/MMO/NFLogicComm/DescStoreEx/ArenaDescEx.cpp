#include "ArenaDescEx.h"

ArenaDescEx::ArenaDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ArenaDescEx::~ArenaDescEx()
{
}

int ArenaDescEx::CreateInit()
{
	return 0;
}

int ArenaDescEx::ResumeInit()
{
	return 0;
}

int ArenaDescEx::Load()
{
	return 0;
}

int ArenaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

