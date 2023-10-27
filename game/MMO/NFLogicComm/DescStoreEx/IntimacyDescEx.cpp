#include "IntimacyDescEx.h"

IntimacyDescEx::IntimacyDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

IntimacyDescEx::~IntimacyDescEx()
{
}

int IntimacyDescEx::CreateInit()
{
	return 0;
}

int IntimacyDescEx::ResumeInit()
{
	return 0;
}

int IntimacyDescEx::Load()
{
	return 0;
}

int IntimacyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

