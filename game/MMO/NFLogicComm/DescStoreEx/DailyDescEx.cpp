#include "DailyDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(DailyDescEx, EOT_CONST_DAILY_DESC_EX_ID, NFShmObj)

DailyDescEx::DailyDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DailyDescEx::~DailyDescEx()
{
}

int DailyDescEx::CreateInit()
{
	return 0;
}

int DailyDescEx::ResumeInit()
{
	return 0;
}

int DailyDescEx::Load()
{
	return 0;
}

int DailyDescEx::PrepareReload()
{
	return 0;
}

int DailyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

