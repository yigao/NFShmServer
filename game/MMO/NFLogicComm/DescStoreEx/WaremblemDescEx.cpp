#include "WaremblemDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(WaremblemDescEx, EOT_CONST_WAREMBLEM_DESC_EX_ID, NFShmObj)

WaremblemDescEx::WaremblemDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WaremblemDescEx::~WaremblemDescEx()
{
}

int WaremblemDescEx::CreateInit()
{
	return 0;
}

int WaremblemDescEx::ResumeInit()
{
	return 0;
}

int WaremblemDescEx::Load()
{
	return 0;
}

int WaremblemDescEx::PrepareReload()
{
	return 0;
}

int WaremblemDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

