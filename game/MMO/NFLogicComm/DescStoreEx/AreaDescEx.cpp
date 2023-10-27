#include "AreaDescEx.h"

AreaDescEx::AreaDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AreaDescEx::~AreaDescEx()
{
}

int AreaDescEx::CreateInit()
{
	return 0;
}

int AreaDescEx::ResumeInit()
{
	return 0;
}

int AreaDescEx::Load()
{
	return 0;
}

int AreaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

