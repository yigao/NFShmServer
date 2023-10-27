#include "ChatDescEx.h"

ChatDescEx::ChatDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ChatDescEx::~ChatDescEx()
{
}

int ChatDescEx::CreateInit()
{
	return 0;
}

int ChatDescEx::ResumeInit()
{
	return 0;
}

int ChatDescEx::Load()
{
	return 0;
}

int ChatDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

