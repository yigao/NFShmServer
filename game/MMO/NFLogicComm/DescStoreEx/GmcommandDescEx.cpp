#include "GmcommandDescEx.h"

GmcommandDescEx::GmcommandDescEx()
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

int GmcommandDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

