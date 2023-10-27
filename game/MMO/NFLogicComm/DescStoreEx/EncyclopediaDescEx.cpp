#include "EncyclopediaDescEx.h"

EncyclopediaDescEx::EncyclopediaDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EncyclopediaDescEx::~EncyclopediaDescEx()
{
}

int EncyclopediaDescEx::CreateInit()
{
	return 0;
}

int EncyclopediaDescEx::ResumeInit()
{
	return 0;
}

int EncyclopediaDescEx::Load()
{
	return 0;
}

int EncyclopediaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

