#include "AncientgodDescEx.h"

AncientgodDescEx::AncientgodDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AncientgodDescEx::~AncientgodDescEx()
{
}

int AncientgodDescEx::CreateInit()
{
	return 0;
}

int AncientgodDescEx::ResumeInit()
{
	return 0;
}

int AncientgodDescEx::Load()
{
	return 0;
}

int AncientgodDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

