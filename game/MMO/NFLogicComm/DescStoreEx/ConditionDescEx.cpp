#include "ConditionDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(ConditionDescEx, EOT_CONST_CONDITION_DESC_EX_ID, NFShmObj)

ConditionDescEx::ConditionDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConditionDescEx::~ConditionDescEx()
{
}

int ConditionDescEx::CreateInit()
{
	return 0;
}

int ConditionDescEx::ResumeInit()
{
	return 0;
}

int ConditionDescEx::Load()
{
	return 0;
}

int ConditionDescEx::PrepareReload()
{
	return 0;
}

int ConditionDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

