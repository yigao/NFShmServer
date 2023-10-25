#include "FindtreasureDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FindtreasureDescEx, EOT_CONST_FINDTREASURE_DESC_EX_ID, NFShmObj)

FindtreasureDescEx::FindtreasureDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FindtreasureDescEx::~FindtreasureDescEx()
{
}

int FindtreasureDescEx::CreateInit()
{
	return 0;
}

int FindtreasureDescEx::ResumeInit()
{
	return 0;
}

int FindtreasureDescEx::Load()
{
	return 0;
}

int FindtreasureDescEx::PrepareReload()
{
	return 0;
}

int FindtreasureDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

