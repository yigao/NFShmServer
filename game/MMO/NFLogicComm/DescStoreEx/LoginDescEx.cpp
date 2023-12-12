#include "LoginDescEx.h"

LoginDescEx::LoginDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

LoginDescEx::~LoginDescEx()
{
}

int LoginDescEx::CreateInit()
{
	return 0;
}

int LoginDescEx::ResumeInit()
{
	return 0;
}

int LoginDescEx::Load()
{
	return 0;
}

int LoginDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

