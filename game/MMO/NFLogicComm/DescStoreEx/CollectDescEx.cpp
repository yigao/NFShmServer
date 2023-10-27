#include "CollectDescEx.h"

CollectDescEx::CollectDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CollectDescEx::~CollectDescEx()
{
}

int CollectDescEx::CreateInit()
{
	return 0;
}

int CollectDescEx::ResumeInit()
{
	return 0;
}

int CollectDescEx::Load()
{
	return 0;
}

int CollectDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

