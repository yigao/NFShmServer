#include "PeakbattleDescEx.h"

PeakbattleDescEx::PeakbattleDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PeakbattleDescEx::~PeakbattleDescEx()
{
}

int PeakbattleDescEx::CreateInit()
{
	return 0;
}

int PeakbattleDescEx::ResumeInit()
{
	return 0;
}

int PeakbattleDescEx::Load()
{
	return 0;
}

int PeakbattleDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

