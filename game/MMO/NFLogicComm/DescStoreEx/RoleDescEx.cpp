#include "RoleDescEx.h"

RoleDescEx::RoleDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RoleDescEx::~RoleDescEx()
{
}

int RoleDescEx::CreateInit()
{
	return 0;
}

int RoleDescEx::ResumeInit()
{
	return 0;
}

int RoleDescEx::Load()
{
	return 0;
}

int RoleDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

