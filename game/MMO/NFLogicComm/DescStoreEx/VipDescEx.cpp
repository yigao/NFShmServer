#include "VipDescEx.h"

VipDescEx::VipDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

VipDescEx::~VipDescEx()
{
}

int VipDescEx::CreateInit()
{
	return 0;
}

int VipDescEx::ResumeInit()
{
	return 0;
}

int VipDescEx::Load()
{
	return 0;
}

int VipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

