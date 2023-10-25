#include "DecorateDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(DecorateDescEx, EOT_CONST_DECORATE_DESC_EX_ID, NFShmObj)

DecorateDescEx::DecorateDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DecorateDescEx::~DecorateDescEx()
{
}

int DecorateDescEx::CreateInit()
{
	return 0;
}

int DecorateDescEx::ResumeInit()
{
	return 0;
}

int DecorateDescEx::Load()
{
	return 0;
}

int DecorateDescEx::PrepareReload()
{
	return 0;
}

int DecorateDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

