#include "RandomnameDescEx.h"

RandomnameDescEx::RandomnameDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RandomnameDescEx::~RandomnameDescEx()
{
}

int RandomnameDescEx::CreateInit()
{
	return 0;
}

int RandomnameDescEx::ResumeInit()
{
	return 0;
}

int RandomnameDescEx::Load()
{
	return 0;
}

int RandomnameDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

