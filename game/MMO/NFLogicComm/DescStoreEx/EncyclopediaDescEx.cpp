#include "EncyclopediaDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(EncyclopediaDescEx, EOT_CONST_ENCYCLOPEDIA_DESC_EX_ID, NFShmObj)

EncyclopediaDescEx::EncyclopediaDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EncyclopediaDescEx::~EncyclopediaDescEx()
{
}

int EncyclopediaDescEx::CreateInit()
{
	return 0;
}

int EncyclopediaDescEx::ResumeInit()
{
	return 0;
}

int EncyclopediaDescEx::Load()
{
	return 0;
}

int EncyclopediaDescEx::PrepareReload()
{
	return 0;
}

int EncyclopediaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

