#include "SkillDescEx.h"

SkillDescEx::SkillDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SkillDescEx::~SkillDescEx()
{
}

int SkillDescEx::CreateInit()
{
	return 0;
}

int SkillDescEx::ResumeInit()
{
	return 0;
}

int SkillDescEx::Load()
{
	return 0;
}

int SkillDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

