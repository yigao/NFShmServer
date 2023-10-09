#include "GodvalleyDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(GodvalleyDescEx, EOT_CONST_GODVALLEY_DESC_EX_ID, NFShmObj)

GodvalleyDescEx::GodvalleyDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodvalleyDescEx::~GodvalleyDescEx()
{
}

int GodvalleyDescEx::CreateInit()
{
	return 0;
}

int GodvalleyDescEx::ResumeInit()
{
	return 0;
}

int GodvalleyDescEx::Load()
{
	return 0;
}

int GodvalleyDescEx::PrepareReload()
{
	return 0;
}

int GodvalleyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

