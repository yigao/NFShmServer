#include "DupDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(DupDescEx, EOT_CONST_DUP_DESC_EX_ID, NFShmObj)

DupDescEx::DupDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DupDescEx::~DupDescEx()
{
}

int DupDescEx::CreateInit()
{
	return 0;
}

int DupDescEx::ResumeInit()
{
	return 0;
}

int DupDescEx::Load()
{
	return 0;
}

int DupDescEx::PrepareReload()
{
	return 0;
}

int DupDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

