#include "WelfareDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(WelfareDescEx, EOT_CONST_WELFARE_DESC_EX_ID, NFShmObj)

WelfareDescEx::WelfareDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WelfareDescEx::~WelfareDescEx()
{
}

int WelfareDescEx::CreateInit()
{
	return 0;
}

int WelfareDescEx::ResumeInit()
{
	return 0;
}

int WelfareDescEx::Load()
{
	return 0;
}

int WelfareDescEx::PrepareReload()
{
	return 0;
}

int WelfareDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

