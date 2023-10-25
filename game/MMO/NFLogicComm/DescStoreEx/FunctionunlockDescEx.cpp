#include "FunctionunlockDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FunctionunlockDescEx, EOT_CONST_FUNCTIONUNLOCK_DESC_EX_ID, NFShmObj)

FunctionunlockDescEx::FunctionunlockDescEx():NFIDescStoreEx()
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

int FunctionunlockDescEx::PrepareReload()
{
	return 0;
}

int FunctionunlockDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

