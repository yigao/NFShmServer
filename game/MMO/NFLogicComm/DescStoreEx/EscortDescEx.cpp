#include "EscortDescEx.h"

EscortDescEx::EscortDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EscortDescEx::~EscortDescEx()
{
}

int EscortDescEx::CreateInit()
{
	return 0;
}

int EscortDescEx::ResumeInit()
{
	return 0;
}

int EscortDescEx::Load()
{
	return 0;
}

int EscortDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

