#include "ItemDescEx.h"

ItemDescEx::ItemDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ItemDescEx::~ItemDescEx()
{
}

int ItemDescEx::CreateInit()
{
	return 0;
}

int ItemDescEx::ResumeInit()
{
	return 0;
}

int ItemDescEx::Load()
{
	return 0;
}

int ItemDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

