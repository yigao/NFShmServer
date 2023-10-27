#include "ShentiDescEx.h"

ShentiDescEx::ShentiDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ShentiDescEx::~ShentiDescEx()
{
}

int ShentiDescEx::CreateInit()
{
	return 0;
}

int ShentiDescEx::ResumeInit()
{
	return 0;
}

int ShentiDescEx::Load()
{
	return 0;
}

int ShentiDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

