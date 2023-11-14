#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_REWARDS_NUM 16

class NickgodRewardsDesc : public NFIDescTemplate<NickgodRewardsDesc, proto_ff_s::E_NickgodRewards_s, EOT_CONST_NICKGOD_REWARDS_DESC_ID, MAX_NICKGOD_REWARDS_NUM>
{
public:
	NickgodRewardsDesc();
	virtual ~NickgodRewardsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
