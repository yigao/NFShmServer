#include "PeractivityDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(PeractivityDescEx, EOT_CONST_PERACTIVITY_DESC_EX_ID, NFShmObj)

PeractivityDescEx::PeractivityDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PeractivityDescEx::~PeractivityDescEx()
{
}

int PeractivityDescEx::CreateInit()
{
	return 0;
}

int PeractivityDescEx::ResumeInit()
{
	return 0;
}

int PeractivityDescEx::Load()
{
	return 0;
}

int PeractivityDescEx::PrepareReload()
{
	return 0;
}

int PeractivityDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

