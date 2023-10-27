#include "MoneyrewardDescEx.h"

MoneyrewardDescEx::MoneyrewardDescEx()
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

int MoneyrewardDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

