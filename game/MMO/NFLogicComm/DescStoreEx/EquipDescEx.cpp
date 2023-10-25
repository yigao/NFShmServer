#include "EquipDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(EquipDescEx, EOT_CONST_EQUIP_DESC_EX_ID, NFShmObj)

EquipDescEx::EquipDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipDescEx::~EquipDescEx()
{
}

int EquipDescEx::CreateInit()
{
	return 0;
}

int EquipDescEx::ResumeInit()
{
	return 0;
}

int EquipDescEx::Load()
{
	return 0;
}

int EquipDescEx::PrepareReload()
{
	return 0;
}

int EquipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

