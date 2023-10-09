#include "AchievementDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(AchievementDescEx, EOT_CONST_ACHIEVEMENT_DESC_EX_ID, NFShmObj)

AchievementDescEx::AchievementDescEx():NFIDescStoreEx()
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

int AchievementDescEx::PrepareReload()
{
	return 0;
}

int AchievementDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

