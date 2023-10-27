#include "TeleportDescEx.h"

TeleportDescEx::TeleportDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TeleportDescEx::~TeleportDescEx()
{
}

int TeleportDescEx::CreateInit()
{
	return 0;
}

int TeleportDescEx::ResumeInit()
{
	return 0;
}

int TeleportDescEx::Load()
{
	return 0;
}

int TeleportDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

