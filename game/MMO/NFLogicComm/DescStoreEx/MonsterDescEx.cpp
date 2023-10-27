#include "MonsterDescEx.h"

MonsterDescEx::MonsterDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MonsterDescEx::~MonsterDescEx()
{
}

int MonsterDescEx::CreateInit()
{
	return 0;
}

int MonsterDescEx::ResumeInit()
{
	return 0;
}

int MonsterDescEx::Load()
{
	return 0;
}

int MonsterDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

