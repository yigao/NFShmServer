#include "WashpartyDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(WashpartyDescEx, EOT_CONST_WASHPARTY_DESC_EX_ID, NFShmObj)

WashpartyDescEx::WashpartyDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WashpartyDescEx::~WashpartyDescEx()
{
}

int WashpartyDescEx::CreateInit()
{
	return 0;
}

int WashpartyDescEx::ResumeInit()
{
	return 0;
}

int WashpartyDescEx::Load()
{
	return 0;
}

int WashpartyDescEx::PrepareReload()
{
	return 0;
}

int WashpartyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

