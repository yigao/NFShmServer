#include "RuneDescEx.h"

RuneDescEx::RuneDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RuneDescEx::~RuneDescEx()
{
}

int RuneDescEx::CreateInit()
{
	return 0;
}

int RuneDescEx::ResumeInit()
{
	return 0;
}

int RuneDescEx::Load()
{
	return 0;
}

int RuneDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

