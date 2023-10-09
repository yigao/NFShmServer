#include "ButtonDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(ButtonDescEx, EOT_CONST_BUTTON_DESC_EX_ID, NFShmObj)

ButtonDescEx::ButtonDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ButtonDescEx::~ButtonDescEx()
{
}

int ButtonDescEx::CreateInit()
{
	return 0;
}

int ButtonDescEx::ResumeInit()
{
	return 0;
}

int ButtonDescEx::Load()
{
	return 0;
}

int ButtonDescEx::PrepareReload()
{
	return 0;
}

int ButtonDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

