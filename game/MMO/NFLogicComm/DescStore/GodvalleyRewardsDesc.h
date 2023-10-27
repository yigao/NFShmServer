#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godvalley_s.h"

#define MAX_GODVALLEY_REWARDS_NUM 16

class GodvalleyRewardsDesc : public NFIDescTemplate<GodvalleyRewardsDesc, proto_ff_s::E_GodvalleyRewards_s, EOT_CONST_GODVALLEY_REWARDS_DESC_ID, MAX_GODVALLEY_REWARDS_NUM>
{
public:
	GodvalleyRewardsDesc();
	virtual ~GodvalleyRewardsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
