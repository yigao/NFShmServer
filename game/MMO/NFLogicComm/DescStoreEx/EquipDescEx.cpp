#include "EquipDescEx.h"

EquipDescEx::EquipDescEx()
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

int EquipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

