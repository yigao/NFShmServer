#include "TianxiafirstDescEx.h"

TianxiafirstDescEx::TianxiafirstDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TianxiafirstDescEx::~TianxiafirstDescEx()
{
}

int TianxiafirstDescEx::CreateInit()
{
	return 0;
}

int TianxiafirstDescEx::ResumeInit()
{
	return 0;
}

int TianxiafirstDescEx::Load()
{
	return 0;
}

int TianxiafirstDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

