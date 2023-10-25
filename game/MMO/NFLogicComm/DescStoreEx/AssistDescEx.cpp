#include "AssistDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(AssistDescEx, EOT_CONST_ASSIST_DESC_EX_ID, NFShmObj)

AssistDescEx::AssistDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AssistDescEx::~AssistDescEx()
{
}

int AssistDescEx::CreateInit()
{
	return 0;
}

int AssistDescEx::ResumeInit()
{
	return 0;
}

int AssistDescEx::Load()
{
	return 0;
}

int AssistDescEx::PrepareReload()
{
	return 0;
}

int AssistDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

