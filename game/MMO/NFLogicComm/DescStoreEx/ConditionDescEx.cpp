#include "ConditionDescEx.h"

ConditionDescEx::ConditionDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConditionDescEx::~ConditionDescEx()
{
}

int ConditionDescEx::CreateInit()
{
	return 0;
}

int ConditionDescEx::ResumeInit()
{
	return 0;
}

int ConditionDescEx::Load()
{
	return 0;
}

int ConditionDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

