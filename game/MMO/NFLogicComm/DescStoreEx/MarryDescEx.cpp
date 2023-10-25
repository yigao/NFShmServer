#include "MarryDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MarryDescEx, EOT_CONST_MARRY_DESC_EX_ID, NFShmObj)

MarryDescEx::MarryDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MarryDescEx::~MarryDescEx()
{
}

int MarryDescEx::CreateInit()
{
	return 0;
}

int MarryDescEx::ResumeInit()
{
	return 0;
}

int MarryDescEx::Load()
{
	return 0;
}

int MarryDescEx::PrepareReload()
{
	return 0;
}

int MarryDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

