#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ranking_s.h"

#define MAX_RANKING_RANKING_NUM 16

class RankingRankingDesc : public NFIDescTemplate<RankingRankingDesc, proto_ff_s::E_RankingRanking_s, EOT_CONST_RANKING_RANKING_DESC_ID, MAX_RANKING_RANKING_NUM>
{
public:
	RankingRankingDesc();
	virtual ~RankingRankingDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
