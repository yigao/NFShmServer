#include "HeadportraitDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(HeadportraitDescEx, EOT_CONST_HEADPORTRAIT_DESC_EX_ID, NFShmObj)

HeadportraitDescEx::HeadportraitDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

HeadportraitDescEx::~HeadportraitDescEx()
{
}

int HeadportraitDescEx::CreateInit()
{
	return 0;
}

int HeadportraitDescEx::ResumeInit()
{
	return 0;
}

int HeadportraitDescEx::Load()
{
	return 0;
}

int HeadportraitDescEx::PrepareReload()
{
	return 0;
}

int HeadportraitDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

