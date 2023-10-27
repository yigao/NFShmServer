#include "ConflateDescEx.h"

ConflateDescEx::ConflateDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConflateDescEx::~ConflateDescEx()
{
}

int ConflateDescEx::CreateInit()
{
	return 0;
}

int ConflateDescEx::ResumeInit()
{
	return 0;
}

int ConflateDescEx::Load()
{
	return 0;
}

int ConflateDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

