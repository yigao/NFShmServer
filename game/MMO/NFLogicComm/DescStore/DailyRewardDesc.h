#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_REWARD_NUM 16

class DailyRewardDesc : public NFIDescTemplate<DailyRewardDesc, proto_ff_s::E_DailyReward_s, EOT_CONST_DAILY_REWARD_DESC_ID, MAX_DAILY_REWARD_NUM>
{
public:
	DailyRewardDesc();
	virtual ~DailyRewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
