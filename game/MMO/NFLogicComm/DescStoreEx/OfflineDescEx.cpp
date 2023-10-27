#include "OfflineDescEx.h"

OfflineDescEx::OfflineDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

OfflineDescEx::~OfflineDescEx()
{
}

int OfflineDescEx::CreateInit()
{
	return 0;
}

int OfflineDescEx::ResumeInit()
{
	return 0;
}

int OfflineDescEx::Load()
{
	return 0;
}

int OfflineDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

