#include "BackDescEx.h"

BackDescEx::BackDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BackDescEx::~BackDescEx()
{
}

int BackDescEx::CreateInit()
{
	return 0;
}

int BackDescEx::ResumeInit()
{
	return 0;
}

int BackDescEx::Load()
{
	return 0;
}

int BackDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

