#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_REWARD_NUM 32

class Pk3v3RewardDesc : public NFIDescTemplate<Pk3v3RewardDesc, proto_ff_s::E_Pk3v3Reward_s, EOT_CONST_PK3V3_REWARD_DESC_ID, MAX_PK3V3_REWARD_NUM>
{
public:
	Pk3v3RewardDesc();
	virtual ~Pk3v3RewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
