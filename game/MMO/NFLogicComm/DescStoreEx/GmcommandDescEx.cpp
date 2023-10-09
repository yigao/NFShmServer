#include "GmcommandDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(GmcommandDescEx, EOT_CONST_GMCOMMAND_DESC_EX_ID, NFShmObj)

GmcommandDescEx::GmcommandDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GmcommandDescEx::~GmcommandDescEx()
{
}

int GmcommandDescEx::CreateInit()
{
	return 0;
}

int GmcommandDescEx::ResumeInit()
{
	return 0;
}

int GmcommandDescEx::Load()
{
	return 0;
}

int GmcommandDescEx::PrepareReload()
{
	return 0;
}

int GmcommandDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

