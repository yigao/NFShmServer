#include "XiuzhenworldDescEx.h"

XiuzhenworldDescEx::XiuzhenworldDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenworldDescEx::~XiuzhenworldDescEx()
{
}

int XiuzhenworldDescEx::CreateInit()
{
	return 0;
}

int XiuzhenworldDescEx::ResumeInit()
{
	return 0;
}

int XiuzhenworldDescEx::Load()
{
	return 0;
}

int XiuzhenworldDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

