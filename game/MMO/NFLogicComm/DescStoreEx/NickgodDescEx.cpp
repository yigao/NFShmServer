#include "NickgodDescEx.h"

NickgodDescEx::NickgodDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NickgodDescEx::~NickgodDescEx()
{
}

int NickgodDescEx::CreateInit()
{
	return 0;
}

int NickgodDescEx::ResumeInit()
{
	return 0;
}

int NickgodDescEx::Load()
{
	return 0;
}

int NickgodDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

