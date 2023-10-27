#include "MountDescEx.h"

MountDescEx::MountDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MountDescEx::~MountDescEx()
{
}

int MountDescEx::CreateInit()
{
	return 0;
}

int MountDescEx::ResumeInit()
{
	return 0;
}

int MountDescEx::Load()
{
	return 0;
}

int MountDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

