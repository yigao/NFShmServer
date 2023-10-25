#include "MarketDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MarketDescEx, EOT_CONST_MARKET_DESC_EX_ID, NFShmObj)

MarketDescEx::MarketDescEx():NFIDescStoreEx()
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

int MarketDescEx::PrepareReload()
{
	return 0;
}

int MarketDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

