#include "TalentDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(TalentDescEx, EOT_CONST_TALENT_DESC_EX_ID, NFShmObj)

TalentDescEx::TalentDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TalentDescEx::~TalentDescEx()
{
}

int TalentDescEx::CreateInit()
{
	return 0;
}

int TalentDescEx::ResumeInit()
{
	return 0;
}

int TalentDescEx::Load()
{
	return 0;
}

int TalentDescEx::PrepareReload()
{
	return 0;
}

int TalentDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

