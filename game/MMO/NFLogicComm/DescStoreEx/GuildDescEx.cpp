#include "GuildDescEx.h"

GuildDescEx::GuildDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GuildDescEx::~GuildDescEx()
{
}

int GuildDescEx::CreateInit()
{
	return 0;
}

int GuildDescEx::ResumeInit()
{
	return 0;
}

int GuildDescEx::Load()
{
	return 0;
}

int GuildDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

