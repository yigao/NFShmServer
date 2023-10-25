#include "XingchenDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(XingchenDescEx, EOT_CONST_XINGCHEN_DESC_EX_ID, NFShmObj)

XingchenDescEx::XingchenDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XingchenDescEx::~XingchenDescEx()
{
}

int XingchenDescEx::CreateInit()
{
	return 0;
}

int XingchenDescEx::ResumeInit()
{
	return 0;
}

int XingchenDescEx::Load()
{
	return 0;
}

int XingchenDescEx::PrepareReload()
{
	return 0;
}

int XingchenDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

