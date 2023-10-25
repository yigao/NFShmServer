#include "FestivalDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FestivalDescEx, EOT_CONST_FESTIVAL_DESC_EX_ID, NFShmObj)

FestivalDescEx::FestivalDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalDescEx::~FestivalDescEx()
{
}

int FestivalDescEx::CreateInit()
{
	return 0;
}

int FestivalDescEx::ResumeInit()
{
	return 0;
}

int FestivalDescEx::Load()
{
	return 0;
}

int FestivalDescEx::PrepareReload()
{
	return 0;
}

int FestivalDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

