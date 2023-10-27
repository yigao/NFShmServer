#include "WaremblemDescEx.h"

WaremblemDescEx::WaremblemDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WaremblemDescEx::~WaremblemDescEx()
{
}

int WaremblemDescEx::CreateInit()
{
	return 0;
}

int WaremblemDescEx::ResumeInit()
{
	return 0;
}

int WaremblemDescEx::Load()
{
	return 0;
}

int WaremblemDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

