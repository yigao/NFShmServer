#include "ShenequipDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(ShenequipDescEx, EOT_CONST_SHENEQUIP_DESC_EX_ID, NFShmObj)

ShenequipDescEx::ShenequipDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ShenequipDescEx::~ShenequipDescEx()
{
}

int ShenequipDescEx::CreateInit()
{
	return 0;
}

int ShenequipDescEx::ResumeInit()
{
	return 0;
}

int ShenequipDescEx::Load()
{
	return 0;
}

int ShenequipDescEx::PrepareReload()
{
	return 0;
}

int ShenequipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

