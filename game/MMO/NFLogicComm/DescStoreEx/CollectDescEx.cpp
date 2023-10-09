#include "CollectDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(CollectDescEx, EOT_CONST_COLLECT_DESC_EX_ID, NFShmObj)

CollectDescEx::CollectDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CollectDescEx::~CollectDescEx()
{
}

int CollectDescEx::CreateInit()
{
	return 0;
}

int CollectDescEx::ResumeInit()
{
	return 0;
}

int CollectDescEx::Load()
{
	return 0;
}

int CollectDescEx::PrepareReload()
{
	return 0;
}

int CollectDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

