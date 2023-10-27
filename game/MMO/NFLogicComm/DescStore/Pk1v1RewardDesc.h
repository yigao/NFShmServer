#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_REWARD_NUM 32

class Pk1v1RewardDesc : public NFIDescTemplate<Pk1v1RewardDesc, proto_ff_s::E_Pk1v1Reward_s, EOT_CONST_PK1V1_REWARD_DESC_ID, MAX_PK1V1_REWARD_NUM>
{
public:
	Pk1v1RewardDesc();
	virtual ~Pk1v1RewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
