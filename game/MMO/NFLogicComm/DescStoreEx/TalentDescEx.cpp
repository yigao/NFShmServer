#include "TalentDescEx.h"

TalentDescEx::TalentDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TalentDescEx::~TalentDescEx()
{
}

int TalentDescEx::CreateInit()
{
	return 0;
}

int TalentDescEx::ResumeInit()
{
	return 0;
}

int TalentDescEx::Load()
{
	return 0;
}

int TalentDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

