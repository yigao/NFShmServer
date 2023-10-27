#include "LinkDescEx.h"

LinkDescEx::LinkDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

LinkDescEx::~LinkDescEx()
{
}

int LinkDescEx::CreateInit()
{
	return 0;
}

int LinkDescEx::ResumeInit()
{
	return 0;
}

int LinkDescEx::Load()
{
	return 0;
}

int LinkDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

