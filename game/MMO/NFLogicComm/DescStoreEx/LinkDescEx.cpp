#include "LinkDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(LinkDescEx, EOT_CONST_LINK_DESC_EX_ID, NFShmObj)

LinkDescEx::LinkDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

LinkDescEx::~LinkDescEx()
{
}

int LinkDescEx::CreateInit()
{
	return 0;
}

int LinkDescEx::ResumeInit()
{
	return 0;
}

int LinkDescEx::Load()
{
	return 0;
}

int LinkDescEx::PrepareReload()
{
	return 0;
}

int LinkDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

