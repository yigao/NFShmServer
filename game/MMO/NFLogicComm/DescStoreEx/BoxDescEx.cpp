#include "BoxDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(BoxDescEx, EOT_CONST_BOX_DESC_EX_ID, NFShmObj)

BoxDescEx::BoxDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BoxDescEx::~BoxDescEx()
{
}

int BoxDescEx::CreateInit()
{
	return 0;
}

int BoxDescEx::ResumeInit()
{
	return 0;
}

int BoxDescEx::Load()
{
	return 0;
}

int BoxDescEx::PrepareReload()
{
	return 0;
}

int BoxDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

