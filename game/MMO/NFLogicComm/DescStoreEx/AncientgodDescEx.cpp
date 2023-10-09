#include "AncientgodDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(AncientgodDescEx, EOT_CONST_ANCIENTGOD_DESC_EX_ID, NFShmObj)

AncientgodDescEx::AncientgodDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AncientgodDescEx::~AncientgodDescEx()
{
}

int AncientgodDescEx::CreateInit()
{
	return 0;
}

int AncientgodDescEx::ResumeInit()
{
	return 0;
}

int AncientgodDescEx::Load()
{
	return 0;
}

int AncientgodDescEx::PrepareReload()
{
	return 0;
}

int AncientgodDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

