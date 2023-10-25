#include "FlashDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FlashDescEx, EOT_CONST_FLASH_DESC_EX_ID, NFShmObj)

FlashDescEx::FlashDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FlashDescEx::~FlashDescEx()
{
}

int FlashDescEx::CreateInit()
{
	return 0;
}

int FlashDescEx::ResumeInit()
{
	return 0;
}

int FlashDescEx::Load()
{
	return 0;
}

int FlashDescEx::PrepareReload()
{
	return 0;
}

int FlashDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

