#include "ConstantDescEx.h"

ConstantDescEx::ConstantDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConstantDescEx::~ConstantDescEx()
{
}

int ConstantDescEx::CreateInit()
{
	return 0;
}

int ConstantDescEx::ResumeInit()
{
	return 0;
}

int ConstantDescEx::Load()
{
	return 0;
}

int ConstantDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

