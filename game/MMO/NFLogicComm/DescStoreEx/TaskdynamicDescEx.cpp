#include "TaskdynamicDescEx.h"

TaskdynamicDescEx::TaskdynamicDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskdynamicDescEx::~TaskdynamicDescEx()
{
}

int TaskdynamicDescEx::CreateInit()
{
	return 0;
}

int TaskdynamicDescEx::ResumeInit()
{
	return 0;
}

int TaskdynamicDescEx::Load()
{
	return 0;
}

int TaskdynamicDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

