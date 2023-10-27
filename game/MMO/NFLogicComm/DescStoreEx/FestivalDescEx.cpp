#include "FestivalDescEx.h"

FestivalDescEx::FestivalDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalDescEx::~FestivalDescEx()
{
}

int FestivalDescEx::CreateInit()
{
	return 0;
}

int FestivalDescEx::ResumeInit()
{
	return 0;
}

int FestivalDescEx::Load()
{
	return 0;
}

int FestivalDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

