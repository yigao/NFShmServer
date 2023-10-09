#include "AreaDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(AreaDescEx, EOT_CONST_AREA_DESC_EX_ID, NFShmObj)

AreaDescEx::AreaDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AreaDescEx::~AreaDescEx()
{
}

int AreaDescEx::CreateInit()
{
	return 0;
}

int AreaDescEx::ResumeInit()
{
	return 0;
}

int AreaDescEx::Load()
{
	return 0;
}

int AreaDescEx::PrepareReload()
{
	return 0;
}

int AreaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

