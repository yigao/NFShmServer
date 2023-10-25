#include "MonsterDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MonsterDescEx, EOT_CONST_MONSTER_DESC_EX_ID, NFShmObj)

MonsterDescEx::MonsterDescEx():NFIDescStoreEx()
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

int MonsterDescEx::PrepareReload()
{
	return 0;
}

int MonsterDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

