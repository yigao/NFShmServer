#include "TasktrackerDescEx.h"

TasktrackerDescEx::TasktrackerDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TasktrackerDescEx::~TasktrackerDescEx()
{
}

int TasktrackerDescEx::CreateInit()
{
	return 0;
}

int TasktrackerDescEx::ResumeInit()
{
	return 0;
}

int TasktrackerDescEx::Load()
{
	return 0;
}

int TasktrackerDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

