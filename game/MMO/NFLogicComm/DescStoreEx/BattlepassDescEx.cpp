#include "BattlepassDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(BattlepassDescEx, EOT_CONST_BATTLEPASS_DESC_EX_ID, NFShmObj)

BattlepassDescEx::BattlepassDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

BattlepassDescEx::~BattlepassDescEx()
{
}

int BattlepassDescEx::CreateInit()
{
	return 0;
}

int BattlepassDescEx::ResumeInit()
{
	return 0;
}

int BattlepassDescEx::Load()
{
	return 0;
}

int BattlepassDescEx::PrepareReload()
{
	return 0;
}

int BattlepassDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

