#include "SetDescEx.h"

SetDescEx::SetDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SetDescEx::~SetDescEx()
{
}

int SetDescEx::CreateInit()
{
	return 0;
}

int SetDescEx::ResumeInit()
{
	return 0;
}

int SetDescEx::Load()
{
	return 0;
}

int SetDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

