#include "SensitivewordDescEx.h"

SensitivewordDescEx::SensitivewordDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SensitivewordDescEx::~SensitivewordDescEx()
{
}

int SensitivewordDescEx::CreateInit()
{
	return 0;
}

int SensitivewordDescEx::ResumeInit()
{
	return 0;
}

int SensitivewordDescEx::Load()
{
	return 0;
}

int SensitivewordDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

