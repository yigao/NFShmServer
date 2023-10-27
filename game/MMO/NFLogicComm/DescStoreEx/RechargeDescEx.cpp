#include "RechargeDescEx.h"

RechargeDescEx::RechargeDescEx()
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

int RechargeDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

