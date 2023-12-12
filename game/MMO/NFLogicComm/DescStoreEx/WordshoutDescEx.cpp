#include "WordshoutDescEx.h"

WordshoutDescEx::WordshoutDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WordshoutDescEx::~WordshoutDescEx()
{
}

int WordshoutDescEx::CreateInit()
{
	return 0;
}

int WordshoutDescEx::ResumeInit()
{
	return 0;
}

int WordshoutDescEx::Load()
{
	return 0;
}

int WordshoutDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

