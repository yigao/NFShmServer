#include "FootprintDescEx.h"

FootprintDescEx::FootprintDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FootprintDescEx::~FootprintDescEx()
{
}

int FootprintDescEx::CreateInit()
{
	return 0;
}

int FootprintDescEx::ResumeInit()
{
	return 0;
}

int FootprintDescEx::Load()
{
	return 0;
}

int FootprintDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

