#include "FashionDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FashionDescEx, EOT_CONST_FASHION_DESC_EX_ID, NFShmObj)

FashionDescEx::FashionDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FashionDescEx::~FashionDescEx()
{
}

int FashionDescEx::CreateInit()
{
	return 0;
}

int FashionDescEx::ResumeInit()
{
	return 0;
}

int FashionDescEx::Load()
{
	return 0;
}

int FashionDescEx::PrepareReload()
{
	return 0;
}

int FashionDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

