#include "XingchenDescEx.h"

XingchenDescEx::XingchenDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XingchenDescEx::~XingchenDescEx()
{
}

int XingchenDescEx::CreateInit()
{
	return 0;
}

int XingchenDescEx::ResumeInit()
{
	return 0;
}

int XingchenDescEx::Load()
{
	return 0;
}

int XingchenDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

