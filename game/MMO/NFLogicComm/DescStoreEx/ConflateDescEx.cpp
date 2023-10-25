#include "ConflateDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(ConflateDescEx, EOT_CONST_CONFLATE_DESC_EX_ID, NFShmObj)

ConflateDescEx::ConflateDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConflateDescEx::~ConflateDescEx()
{
}

int ConflateDescEx::CreateInit()
{
	return 0;
}

int ConflateDescEx::ResumeInit()
{
	return 0;
}

int ConflateDescEx::Load()
{
	return 0;
}

int ConflateDescEx::PrepareReload()
{
	return 0;
}

int ConflateDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

