#include "GuildDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(GuildDescEx, EOT_CONST_GUILD_DESC_EX_ID, NFShmObj)

GuildDescEx::GuildDescEx():NFIDescStoreEx()
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

int GuildDescEx::PrepareReload()
{
	return 0;
}

int GuildDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

