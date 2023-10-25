#include "SetDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(SetDescEx, EOT_CONST_SET_DESC_EX_ID, NFShmObj)

SetDescEx::SetDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SetDescEx::~SetDescEx()
{
}

int SetDescEx::CreateInit()
{
	return 0;
}

int SetDescEx::ResumeInit()
{
	return 0;
}

int SetDescEx::Load()
{
	return 0;
}

int SetDescEx::PrepareReload()
{
	return 0;
}

int SetDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

