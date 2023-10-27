#include "MarketDescEx.h"

MarketDescEx::MarketDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MarketDescEx::~MarketDescEx()
{
}

int MarketDescEx::CreateInit()
{
	return 0;
}

int MarketDescEx::ResumeInit()
{
	return 0;
}

int MarketDescEx::Load()
{
	return 0;
}

int MarketDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

