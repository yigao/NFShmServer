#include "HaloDescEx.h"

HaloDescEx::HaloDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

HaloDescEx::~HaloDescEx()
{
}

int HaloDescEx::CreateInit()
{
	return 0;
}

int HaloDescEx::ResumeInit()
{
	return 0;
}

int HaloDescEx::Load()
{
	return 0;
}

int HaloDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

