#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ranking_s.h"

#define MAX_RANKING_BUTTON_NUM 8

class RankingButtonDesc : public NFIDescTemplate<RankingButtonDesc, proto_ff_s::E_RankingButton_s, EOT_CONST_RANKING_BUTTON_DESC_ID, MAX_RANKING_BUTTON_NUM>
{
public:
	RankingButtonDesc();
	virtual ~RankingButtonDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
