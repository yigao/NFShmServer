#include "ConstantDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(ConstantDescEx, EOT_CONST_CONSTANT_DESC_EX_ID, NFShmObj)

ConstantDescEx::ConstantDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConstantDescEx::~ConstantDescEx()
{
}

int ConstantDescEx::CreateInit()
{
	return 0;
}

int ConstantDescEx::ResumeInit()
{
	return 0;
}

int ConstantDescEx::Load()
{
	return 0;
}

int ConstantDescEx::PrepareReload()
{
	return 0;
}

int ConstantDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

