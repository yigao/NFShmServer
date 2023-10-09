#include "ArenaDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(ArenaDescEx, EOT_CONST_ARENA_DESC_EX_ID, NFShmObj)

ArenaDescEx::ArenaDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ArenaDescEx::~ArenaDescEx()
{
}

int ArenaDescEx::CreateInit()
{
	return 0;
}

int ArenaDescEx::ResumeInit()
{
	return 0;
}

int ArenaDescEx::Load()
{
	return 0;
}

int ArenaDescEx::PrepareReload()
{
	return 0;
}

int ArenaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

