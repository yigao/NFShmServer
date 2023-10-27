#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ranking_s.h"

#define MAX_RANKING_DATE_NUM 32

class RankingDateDesc : public NFIDescTemplate<RankingDateDesc, proto_ff_s::E_RankingDate_s, EOT_CONST_RANKING_DATE_DESC_ID, MAX_RANKING_DATE_NUM>
{
public:
	RankingDateDesc();
	virtual ~RankingDateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
