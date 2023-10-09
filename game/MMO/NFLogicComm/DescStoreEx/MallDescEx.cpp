#include "MallDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(MallDescEx, EOT_CONST_MALL_DESC_EX_ID, NFShmObj)

MallDescEx::MallDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MallDescEx::~MallDescEx()
{
}

int MallDescEx::CreateInit()
{
	return 0;
}

int MallDescEx::ResumeInit()
{
	return 0;
}

int MallDescEx::Load()
{
	return 0;
}

int MallDescEx::PrepareReload()
{
	return 0;
}

int MallDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

