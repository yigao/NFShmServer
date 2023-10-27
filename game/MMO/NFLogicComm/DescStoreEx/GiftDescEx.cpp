#include "GiftDescEx.h"

GiftDescEx::GiftDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GiftDescEx::~GiftDescEx()
{
}

int GiftDescEx::CreateInit()
{
	return 0;
}

int GiftDescEx::ResumeInit()
{
	return 0;
}

int GiftDescEx::Load()
{
	return 0;
}

int GiftDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

