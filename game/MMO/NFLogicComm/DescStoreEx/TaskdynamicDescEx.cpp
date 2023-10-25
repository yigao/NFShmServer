#include "TaskdynamicDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(TaskdynamicDescEx, EOT_CONST_TASKDYNAMIC_DESC_EX_ID, NFShmObj)

TaskdynamicDescEx::TaskdynamicDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskdynamicDescEx::~TaskdynamicDescEx()
{
}

int TaskdynamicDescEx::CreateInit()
{
	return 0;
}

int TaskdynamicDescEx::ResumeInit()
{
	return 0;
}

int TaskdynamicDescEx::Load()
{
	return 0;
}

int TaskdynamicDescEx::PrepareReload()
{
	return 0;
}

int TaskdynamicDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

