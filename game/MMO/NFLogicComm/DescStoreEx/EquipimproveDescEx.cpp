#include "EquipimproveDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(EquipimproveDescEx, EOT_CONST_EQUIPIMPROVE_DESC_EX_ID, NFShmObj)

EquipimproveDescEx::EquipimproveDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipimproveDescEx::~EquipimproveDescEx()
{
}

int EquipimproveDescEx::CreateInit()
{
	return 0;
}

int EquipimproveDescEx::ResumeInit()
{
	return 0;
}

int EquipimproveDescEx::Load()
{
	return 0;
}

int EquipimproveDescEx::PrepareReload()
{
	return 0;
}

int EquipimproveDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

