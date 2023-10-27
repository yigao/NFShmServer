#include "XiuzhenDescEx.h"

XiuzhenDescEx::XiuzhenDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenDescEx::~XiuzhenDescEx()
{
}

int XiuzhenDescEx::CreateInit()
{
	return 0;
}

int XiuzhenDescEx::ResumeInit()
{
	return 0;
}

int XiuzhenDescEx::Load()
{
	return 0;
}

int XiuzhenDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

