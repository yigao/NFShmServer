#include "HaloDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(HaloDescEx, EOT_CONST_HALO_DESC_EX_ID, NFShmObj)

HaloDescEx::HaloDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

HaloDescEx::~HaloDescEx()
{
}

int HaloDescEx::CreateInit()
{
	return 0;
}

int HaloDescEx::ResumeInit()
{
	return 0;
}

int HaloDescEx::Load()
{
	return 0;
}

int HaloDescEx::PrepareReload()
{
	return 0;
}

int HaloDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

