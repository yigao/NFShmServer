#include "ItemDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(ItemDescEx, EOT_CONST_ITEM_DESC_EX_ID, NFShmObj)

ItemDescEx::ItemDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ItemDescEx::~ItemDescEx()
{
}

int ItemDescEx::CreateInit()
{
	return 0;
}

int ItemDescEx::ResumeInit()
{
	return 0;
}

int ItemDescEx::Load()
{
	return 0;
}

int ItemDescEx::PrepareReload()
{
	return 0;
}

int ItemDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

