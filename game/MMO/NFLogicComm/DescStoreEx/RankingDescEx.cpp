#include "RankingDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(RankingDescEx, EOT_CONST_RANKING_DESC_EX_ID, NFShmObj)

RankingDescEx::RankingDescEx():NFIDescStoreEx()
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

int RankingDescEx::PrepareReload()
{
	return 0;
}

int RankingDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

