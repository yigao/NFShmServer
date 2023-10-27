#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_REWARD_NUM 2048

class EscortRewardDesc : public NFIDescTemplate<EscortRewardDesc, proto_ff_s::E_EscortReward_s, EOT_CONST_ESCORT_REWARD_DESC_ID, MAX_ESCORT_REWARD_NUM>
{
public:
	EscortRewardDesc();
	virtual ~EscortRewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
