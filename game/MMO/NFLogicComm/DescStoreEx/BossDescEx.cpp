#include "BossDescEx.h"

BossDescEx::BossDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BossDescEx::~BossDescEx()
{
}

int BossDescEx::CreateInit()
{
	return 0;
}

int BossDescEx::ResumeInit()
{
	return 0;
}

int BossDescEx::Load()
{
	return 0;
}

int BossDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

