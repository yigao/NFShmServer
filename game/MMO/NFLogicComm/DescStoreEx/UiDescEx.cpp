#include "UiDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(UiDescEx, EOT_CONST_UI_DESC_EX_ID, NFShmObj)

UiDescEx::UiDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

UiDescEx::~UiDescEx()
{
}

int UiDescEx::CreateInit()
{
	return 0;
}

int UiDescEx::ResumeInit()
{
	return 0;
}

int UiDescEx::Load()
{
	return 0;
}

int UiDescEx::PrepareReload()
{
	return 0;
}

int UiDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

