#include "SkillDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(SkillDescEx, EOT_CONST_SKILL_DESC_EX_ID, NFShmObj)

SkillDescEx::SkillDescEx():NFIDescStoreEx()
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

int SkillDescEx::PrepareReload()
{
	return 0;
}

int SkillDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

