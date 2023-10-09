#include "TitleDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(TitleDescEx, EOT_CONST_TITLE_DESC_EX_ID, NFShmObj)

TitleDescEx::TitleDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TitleDescEx::~TitleDescEx()
{
}

int TitleDescEx::CreateInit()
{
	return 0;
}

int TitleDescEx::ResumeInit()
{
	return 0;
}

int TitleDescEx::Load()
{
	return 0;
}

int TitleDescEx::PrepareReload()
{
	return 0;
}

int TitleDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

