#include "FacadeDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FacadeDescEx, EOT_CONST_FACADE_DESC_EX_ID, NFShmObj)

FacadeDescEx::FacadeDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FacadeDescEx::~FacadeDescEx()
{
}

int FacadeDescEx::CreateInit()
{
	return 0;
}

int FacadeDescEx::ResumeInit()
{
	return 0;
}

int FacadeDescEx::Load()
{
	return 0;
}

int FacadeDescEx::PrepareReload()
{
	return 0;
}

int FacadeDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

