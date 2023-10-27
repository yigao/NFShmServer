#include "RankingDescEx.h"

RankingDescEx::RankingDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RankingDescEx::~RankingDescEx()
{
}

int RankingDescEx::CreateInit()
{
	return 0;
}

int RankingDescEx::ResumeInit()
{
	return 0;
}

int RankingDescEx::Load()
{
	return 0;
}

int RankingDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

