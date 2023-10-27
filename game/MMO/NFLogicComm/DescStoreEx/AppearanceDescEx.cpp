#include "AppearanceDescEx.h"

AppearanceDescEx::AppearanceDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AppearanceDescEx::~AppearanceDescEx()
{
}

int AppearanceDescEx::CreateInit()
{
	return 0;
}

int AppearanceDescEx::ResumeInit()
{
	return 0;
}

int AppearanceDescEx::Load()
{
	return 0;
}

int AppearanceDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

