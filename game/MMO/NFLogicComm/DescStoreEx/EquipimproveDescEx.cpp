#include "EquipimproveDescEx.h"

EquipimproveDescEx::EquipimproveDescEx()
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

int EquipimproveDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

