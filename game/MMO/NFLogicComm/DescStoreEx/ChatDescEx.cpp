#include "ChatDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(ChatDescEx, EOT_CONST_CHAT_DESC_EX_ID, NFShmObj)

ChatDescEx::ChatDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ChatDescEx::~ChatDescEx()
{
}

int ChatDescEx::CreateInit()
{
	return 0;
}

int ChatDescEx::ResumeInit()
{
	return 0;
}

int ChatDescEx::Load()
{
	return 0;
}

int ChatDescEx::PrepareReload()
{
	return 0;
}

int ChatDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

