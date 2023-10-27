#include "AchievementDescEx.h"

AchievementDescEx::AchievementDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AchievementDescEx::~AchievementDescEx()
{
}

int AchievementDescEx::CreateInit()
{
	return 0;
}

int AchievementDescEx::ResumeInit()
{
	return 0;
}

int AchievementDescEx::Load()
{
	return 0;
}

int AchievementDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

