#include "FashionDescEx.h"

FashionDescEx::FashionDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FashionDescEx::~FashionDescEx()
{
}

int FashionDescEx::CreateInit()
{
	return 0;
}

int FashionDescEx::ResumeInit()
{
	return 0;
}

int FashionDescEx::Load()
{
	return 0;
}

int FashionDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

