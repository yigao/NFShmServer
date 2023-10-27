#include "FindtreasureDescEx.h"

FindtreasureDescEx::FindtreasureDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FindtreasureDescEx::~FindtreasureDescEx()
{
}

int FindtreasureDescEx::CreateInit()
{
	return 0;
}

int FindtreasureDescEx::ResumeInit()
{
	return 0;
}

int FindtreasureDescEx::Load()
{
	return 0;
}

int FindtreasureDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

