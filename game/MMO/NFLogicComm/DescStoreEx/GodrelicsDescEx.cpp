#include "GodrelicsDescEx.h"

GodrelicsDescEx::GodrelicsDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodrelicsDescEx::~GodrelicsDescEx()
{
}

int GodrelicsDescEx::CreateInit()
{
	return 0;
}

int GodrelicsDescEx::ResumeInit()
{
	return 0;
}

int GodrelicsDescEx::Load()
{
	return 0;
}

int GodrelicsDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

