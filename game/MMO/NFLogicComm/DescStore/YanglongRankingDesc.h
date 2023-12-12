#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Yanglong_s.h"

#define MAX_YANGLONG_RANKING_NUM 8

class YanglongRankingDesc : public NFIDescTemplate<YanglongRankingDesc, proto_ff_s::E_YanglongRanking_s, EOT_CONST_YANGLONG_RANKING_DESC_ID, MAX_YANGLONG_RANKING_NUM>
{
public:
	YanglongRankingDesc();
	virtual ~YanglongRankingDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
