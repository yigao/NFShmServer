#include "CloudpeakDescEx.h"

CloudpeakDescEx::CloudpeakDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CloudpeakDescEx::~CloudpeakDescEx()
{
}

int CloudpeakDescEx::CreateInit()
{
	return 0;
}

int CloudpeakDescEx::ResumeInit()
{
	return 0;
}

int CloudpeakDescEx::Load()
{
	return 0;
}

int CloudpeakDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

