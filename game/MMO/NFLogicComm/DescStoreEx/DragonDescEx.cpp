#include "DragonDescEx.h"

DragonDescEx::DragonDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DragonDescEx::~DragonDescEx()
{
}

int DragonDescEx::CreateInit()
{
	return 0;
}

int DragonDescEx::ResumeInit()
{
	return 0;
}

int DragonDescEx::Load()
{
	return 0;
}

int DragonDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

