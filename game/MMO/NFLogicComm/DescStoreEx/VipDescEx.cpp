#include "VipDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(VipDescEx, EOT_CONST_VIP_DESC_EX_ID, NFShmObj)

VipDescEx::VipDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

VipDescEx::~VipDescEx()
{
}

int VipDescEx::CreateInit()
{
	return 0;
}

int VipDescEx::ResumeInit()
{
	return 0;
}

int VipDescEx::Load()
{
	return 0;
}

int VipDescEx::PrepareReload()
{
	return 0;
}

int VipDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

