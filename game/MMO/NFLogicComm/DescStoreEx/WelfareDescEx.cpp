#include "WelfareDescEx.h"

WelfareDescEx::WelfareDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WelfareDescEx::~WelfareDescEx()
{
}

int WelfareDescEx::CreateInit()
{
	return 0;
}

int WelfareDescEx::ResumeInit()
{
	return 0;
}

int WelfareDescEx::Load()
{
	return 0;
}

int WelfareDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

