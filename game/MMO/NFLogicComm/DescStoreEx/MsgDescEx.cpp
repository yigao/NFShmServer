#include "MsgDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MsgDescEx, EOT_CONST_MSG_DESC_EX_ID, NFShmObj)

MsgDescEx::MsgDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MsgDescEx::~MsgDescEx()
{
}

int MsgDescEx::CreateInit()
{
	return 0;
}

int MsgDescEx::ResumeInit()
{
	return 0;
}

int MsgDescEx::Load()
{
	return 0;
}

int MsgDescEx::PrepareReload()
{
	return 0;
}

int MsgDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

