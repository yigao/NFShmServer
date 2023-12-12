#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_REWARD_NUM 2048

class BattlepassRewardDesc : public NFIDescTemplate<BattlepassRewardDesc, proto_ff_s::E_BattlepassReward_s, EOT_CONST_BATTLEPASS_REWARD_DESC_ID, MAX_BATTLEPASS_REWARD_NUM>
{
public:
	BattlepassRewardDesc();
	virtual ~BattlepassRewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
