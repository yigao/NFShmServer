#include "TeamDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(TeamDescEx, EOT_CONST_TEAM_DESC_EX_ID, NFShmObj)

TeamDescEx::TeamDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TeamDescEx::~TeamDescEx()
{
}

int TeamDescEx::CreateInit()
{
	return 0;
}

int TeamDescEx::ResumeInit()
{
	return 0;
}

int TeamDescEx::Load()
{
	return 0;
}

int TeamDescEx::PrepareReload()
{
	return 0;
}

int TeamDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

