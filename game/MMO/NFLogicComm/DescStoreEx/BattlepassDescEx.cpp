#include "BattlepassDescEx.h"

BattlepassDescEx::BattlepassDescEx()
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

int BattlepassDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

