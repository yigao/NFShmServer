#include "OfflineDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(OfflineDescEx, EOT_CONST_OFFLINE_DESC_EX_ID, NFShmObj)

OfflineDescEx::OfflineDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

OfflineDescEx::~OfflineDescEx()
{
}

int OfflineDescEx::CreateInit()
{
	return 0;
}

int OfflineDescEx::ResumeInit()
{
	return 0;
}

int OfflineDescEx::Load()
{
	return 0;
}

int OfflineDescEx::PrepareReload()
{
	return 0;
}

int OfflineDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

