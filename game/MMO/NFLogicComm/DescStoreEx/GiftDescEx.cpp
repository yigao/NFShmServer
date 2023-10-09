#include "GiftDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(GiftDescEx, EOT_CONST_GIFT_DESC_EX_ID, NFShmObj)

GiftDescEx::GiftDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GiftDescEx::~GiftDescEx()
{
}

int GiftDescEx::CreateInit()
{
	return 0;
}

int GiftDescEx::ResumeInit()
{
	return 0;
}

int GiftDescEx::Load()
{
	return 0;
}

int GiftDescEx::PrepareReload()
{
	return 0;
}

int GiftDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

