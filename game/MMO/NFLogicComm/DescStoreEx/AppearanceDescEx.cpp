#include "AppearanceDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(AppearanceDescEx, EOT_CONST_APPEARANCE_DESC_EX_ID, NFShmObj)

AppearanceDescEx::AppearanceDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AppearanceDescEx::~AppearanceDescEx()
{
}

int AppearanceDescEx::CreateInit()
{
	return 0;
}

int AppearanceDescEx::ResumeInit()
{
	return 0;
}

int AppearanceDescEx::Load()
{
	return 0;
}

int AppearanceDescEx::PrepareReload()
{
	return 0;
}

int AppearanceDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

