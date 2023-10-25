#include "GodevilDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(GodevilDescEx, EOT_CONST_GODEVIL_DESC_EX_ID, NFShmObj)

GodevilDescEx::GodevilDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodevilDescEx::~GodevilDescEx()
{
}

int GodevilDescEx::CreateInit()
{
	return 0;
}

int GodevilDescEx::ResumeInit()
{
	return 0;
}

int GodevilDescEx::Load()
{
	return 0;
}

int GodevilDescEx::PrepareReload()
{
	return 0;
}

int GodevilDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

