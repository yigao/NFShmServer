#include "GodevilDescEx.h"

GodevilDescEx::GodevilDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodevilDescEx::~GodevilDescEx()
{
}

int GodevilDescEx::CreateInit()
{
	return 0;
}

int GodevilDescEx::ResumeInit()
{
	return 0;
}

int GodevilDescEx::Load()
{
	return 0;
}

int GodevilDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

