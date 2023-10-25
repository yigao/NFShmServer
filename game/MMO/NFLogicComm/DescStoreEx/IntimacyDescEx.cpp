#include "IntimacyDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(IntimacyDescEx, EOT_CONST_INTIMACY_DESC_EX_ID, NFShmObj)

IntimacyDescEx::IntimacyDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

IntimacyDescEx::~IntimacyDescEx()
{
}

int IntimacyDescEx::CreateInit()
{
	return 0;
}

int IntimacyDescEx::ResumeInit()
{
	return 0;
}

int IntimacyDescEx::Load()
{
	return 0;
}

int IntimacyDescEx::PrepareReload()
{
	return 0;
}

int IntimacyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

