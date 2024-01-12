#include "FishDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(FishDescEx, EOT_CONST_FISH_DESC_EX_ID, NFShmObj)

FishDescEx::FishDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FishDescEx::~FishDescEx()
{
}

int FishDescEx::CreateInit()
{
	return 0;
}

int FishDescEx::ResumeInit()
{
	return 0;
}

int FishDescEx::Load()
{
	return 0;
}

int FishDescEx::PrepareReload()
{
	return 0;
}

int FishDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

