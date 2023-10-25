#include "ShentiDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(ShentiDescEx, EOT_CONST_SHENTI_DESC_EX_ID, NFShmObj)

ShentiDescEx::ShentiDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ShentiDescEx::~ShentiDescEx()
{
}

int ShentiDescEx::CreateInit()
{
	return 0;
}

int ShentiDescEx::ResumeInit()
{
	return 0;
}

int ShentiDescEx::Load()
{
	return 0;
}

int ShentiDescEx::PrepareReload()
{
	return 0;
}

int ShentiDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

