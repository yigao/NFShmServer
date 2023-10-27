#include "DupDescEx.h"

DupDescEx::DupDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DupDescEx::~DupDescEx()
{
}

int DupDescEx::CreateInit()
{
	return 0;
}

int DupDescEx::ResumeInit()
{
	return 0;
}

int DupDescEx::Load()
{
	return 0;
}

int DupDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

