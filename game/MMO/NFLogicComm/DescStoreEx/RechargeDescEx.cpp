#include "RechargeDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(RechargeDescEx, EOT_CONST_RECHARGE_DESC_EX_ID, NFShmObj)

RechargeDescEx::RechargeDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RechargeDescEx::~RechargeDescEx()
{
}

int RechargeDescEx::CreateInit()
{
	return 0;
}

int RechargeDescEx::ResumeInit()
{
	return 0;
}

int RechargeDescEx::Load()
{
	return 0;
}

int RechargeDescEx::PrepareReload()
{
	return 0;
}

int RechargeDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

