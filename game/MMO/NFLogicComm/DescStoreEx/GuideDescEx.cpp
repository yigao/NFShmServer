#include "GuideDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(GuideDescEx, EOT_CONST_GUIDE_DESC_EX_ID, NFShmObj)

GuideDescEx::GuideDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GuideDescEx::~GuideDescEx()
{
}

int GuideDescEx::CreateInit()
{
	return 0;
}

int GuideDescEx::ResumeInit()
{
	return 0;
}

int GuideDescEx::Load()
{
	return 0;
}

int GuideDescEx::PrepareReload()
{
	return 0;
}

int GuideDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

