#include "BackDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(BackDescEx, EOT_CONST_BACK_DESC_EX_ID, NFShmObj)

BackDescEx::BackDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BackDescEx::~BackDescEx()
{
}

int BackDescEx::CreateInit()
{
	return 0;
}

int BackDescEx::ResumeInit()
{
	return 0;
}

int BackDescEx::Load()
{
	return 0;
}

int BackDescEx::PrepareReload()
{
	return 0;
}

int BackDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

