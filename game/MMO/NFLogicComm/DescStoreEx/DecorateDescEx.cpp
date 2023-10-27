#include "DecorateDescEx.h"

DecorateDescEx::DecorateDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DecorateDescEx::~DecorateDescEx()
{
}

int DecorateDescEx::CreateInit()
{
	return 0;
}

int DecorateDescEx::ResumeInit()
{
	return 0;
}

int DecorateDescEx::Load()
{
	return 0;
}

int DecorateDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

