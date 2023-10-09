#include "MofaDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(MofaDescEx, EOT_CONST_MOFA_DESC_EX_ID, NFShmObj)

MofaDescEx::MofaDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MofaDescEx::~MofaDescEx()
{
}

int MofaDescEx::CreateInit()
{
	return 0;
}

int MofaDescEx::ResumeInit()
{
	return 0;
}

int MofaDescEx::Load()
{
	return 0;
}

int MofaDescEx::PrepareReload()
{
	return 0;
}

int MofaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

