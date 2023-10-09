#include "TasktrackerDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(TasktrackerDescEx, EOT_CONST_TASKTRACKER_DESC_EX_ID, NFShmObj)

TasktrackerDescEx::TasktrackerDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TasktrackerDescEx::~TasktrackerDescEx()
{
}

int TasktrackerDescEx::CreateInit()
{
	return 0;
}

int TasktrackerDescEx::ResumeInit()
{
	return 0;
}

int TasktrackerDescEx::Load()
{
	return 0;
}

int TasktrackerDescEx::PrepareReload()
{
	return 0;
}

int TasktrackerDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

