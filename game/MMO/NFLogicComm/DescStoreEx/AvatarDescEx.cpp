#include "AvatarDescEx.h"

AvatarDescEx::AvatarDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AvatarDescEx::~AvatarDescEx()
{
}

int AvatarDescEx::CreateInit()
{
	return 0;
}

int AvatarDescEx::ResumeInit()
{
	return 0;
}

int AvatarDescEx::Load()
{
	return 0;
}

int AvatarDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

