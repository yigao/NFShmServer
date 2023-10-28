#include "SoulDescEx.h"

SoulDescEx::SoulDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SoulDescEx::~SoulDescEx()
{
}

int SoulDescEx::CreateInit()
{
	return 0;
}

int SoulDescEx::ResumeInit()
{
	return 0;
}

int SoulDescEx::Load()
{
	return 0;
}

int SoulDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

