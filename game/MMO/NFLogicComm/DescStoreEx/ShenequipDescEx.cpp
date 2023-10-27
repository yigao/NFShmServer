#include "ShenequipDescEx.h"

ShenequipDescEx::ShenequipDescEx()
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

int ShenequipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

