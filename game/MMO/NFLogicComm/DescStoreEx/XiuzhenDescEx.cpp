#include "XiuzhenDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(XiuzhenDescEx, EOT_CONST_XIUZHEN_DESC_EX_ID, NFShmObj)

XiuzhenDescEx::XiuzhenDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenDescEx::~XiuzhenDescEx()
{
}

int XiuzhenDescEx::CreateInit()
{
	return 0;
}

int XiuzhenDescEx::ResumeInit()
{
	return 0;
}

int XiuzhenDescEx::Load()
{
	return 0;
}

int XiuzhenDescEx::PrepareReload()
{
	return 0;
}

int XiuzhenDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

