#include "MailDescEx.h"

MailDescEx::MailDescEx()
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

int MailDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

