#include "FunctionunlockDescEx.h"

FunctionunlockDescEx::FunctionunlockDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FunctionunlockDescEx::~FunctionunlockDescEx()
{
}

int FunctionunlockDescEx::CreateInit()
{
	return 0;
}

int FunctionunlockDescEx::ResumeInit()
{
	return 0;
}

int FunctionunlockDescEx::Load()
{
	return 0;
}

int FunctionunlockDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

