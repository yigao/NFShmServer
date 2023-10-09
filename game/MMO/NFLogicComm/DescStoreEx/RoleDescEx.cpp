#include "RoleDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(RoleDescEx, EOT_CONST_ROLE_DESC_EX_ID, NFShmObj)

RoleDescEx::RoleDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RoleDescEx::~RoleDescEx()
{
}

int RoleDescEx::CreateInit()
{
	return 0;
}

int RoleDescEx::ResumeInit()
{
	return 0;
}

int RoleDescEx::Load()
{
	return 0;
}

int RoleDescEx::PrepareReload()
{
	return 0;
}

int RoleDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

