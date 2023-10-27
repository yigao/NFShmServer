#include "TaskDescEx.h"

TaskDescEx::TaskDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskDescEx::~TaskDescEx()
{
}

int TaskDescEx::CreateInit()
{
	return 0;
}

int TaskDescEx::ResumeInit()
{
	return 0;
}

int TaskDescEx::Load()
{
	return 0;
}

int TaskDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

