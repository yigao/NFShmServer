#include "TitleDescEx.h"

TitleDescEx::TitleDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TitleDescEx::~TitleDescEx()
{
}

int TitleDescEx::CreateInit()
{
	return 0;
}

int TitleDescEx::ResumeInit()
{
	return 0;
}

int TitleDescEx::Load()
{
	return 0;
}

int TitleDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

