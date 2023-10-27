#include "TaskrewardDescEx.h"

TaskrewardDescEx::TaskrewardDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskrewardDescEx::~TaskrewardDescEx()
{
}

int TaskrewardDescEx::CreateInit()
{
	return 0;
}

int TaskrewardDescEx::ResumeInit()
{
	return 0;
}

int TaskrewardDescEx::Load()
{
	return 0;
}

int TaskrewardDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

