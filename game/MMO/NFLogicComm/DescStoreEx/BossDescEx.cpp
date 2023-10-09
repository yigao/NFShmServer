#include "BossDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(BossDescEx, EOT_CONST_BOSS_DESC_EX_ID, NFShmObj)

BossDescEx::BossDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BossDescEx::~BossDescEx()
{
}

int BossDescEx::CreateInit()
{
	return 0;
}

int BossDescEx::ResumeInit()
{
	return 0;
}

int BossDescEx::Load()
{
	return 0;
}

int BossDescEx::PrepareReload()
{
	return 0;
}

int BossDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

