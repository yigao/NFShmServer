#include "MoneyrewardDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MoneyrewardDescEx, EOT_CONST_MONEYREWARD_DESC_EX_ID, NFShmObj)

MoneyrewardDescEx::MoneyrewardDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MoneyrewardDescEx::~MoneyrewardDescEx()
{
}

int MoneyrewardDescEx::CreateInit()
{
	return 0;
}

int MoneyrewardDescEx::ResumeInit()
{
	return 0;
}

int MoneyrewardDescEx::Load()
{
	return 0;
}

int MoneyrewardDescEx::PrepareReload()
{
	return 0;
}

int MoneyrewardDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

