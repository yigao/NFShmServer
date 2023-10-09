#include "TaskrewardDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(TaskrewardDescEx, EOT_CONST_TASKREWARD_DESC_EX_ID, NFShmObj)

TaskrewardDescEx::TaskrewardDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskrewardDescEx::~TaskrewardDescEx()
{
}

int TaskrewardDescEx::CreateInit()
{
	return 0;
}

int TaskrewardDescEx::ResumeInit()
{
	return 0;
}

int TaskrewardDescEx::Load()
{
	return 0;
}

int TaskrewardDescEx::PrepareReload()
{
	return 0;
}

int TaskrewardDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

