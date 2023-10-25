#include "MailDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MailDescEx, EOT_CONST_MAIL_DESC_EX_ID, NFShmObj)

MailDescEx::MailDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MailDescEx::~MailDescEx()
{
}

int MailDescEx::CreateInit()
{
	return 0;
}

int MailDescEx::ResumeInit()
{
	return 0;
}

int MailDescEx::Load()
{
	return 0;
}

int MailDescEx::PrepareReload()
{
	return 0;
}

int MailDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

