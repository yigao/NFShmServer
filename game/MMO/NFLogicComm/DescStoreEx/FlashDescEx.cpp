#include "FlashDescEx.h"

FlashDescEx::FlashDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FlashDescEx::~FlashDescEx()
{
}

int FlashDescEx::CreateInit()
{
	return 0;
}

int FlashDescEx::ResumeInit()
{
	return 0;
}

int FlashDescEx::Load()
{
	return 0;
}

int FlashDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

