#include "ButtonDescEx.h"

ButtonDescEx::ButtonDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ButtonDescEx::~ButtonDescEx()
{
}

int ButtonDescEx::CreateInit()
{
	return 0;
}

int ButtonDescEx::ResumeInit()
{
	return 0;
}

int ButtonDescEx::Load()
{
	return 0;
}

int ButtonDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

