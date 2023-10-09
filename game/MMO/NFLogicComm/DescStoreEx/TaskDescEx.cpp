#include "TaskDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(TaskDescEx, EOT_CONST_TASK_DESC_EX_ID, NFShmObj)

TaskDescEx::TaskDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskDescEx::~TaskDescEx()
{
}

int TaskDescEx::CreateInit()
{
	return 0;
}

int TaskDescEx::ResumeInit()
{
	return 0;
}

int TaskDescEx::Load()
{
	return 0;
}

int TaskDescEx::PrepareReload()
{
	return 0;
}

int TaskDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

