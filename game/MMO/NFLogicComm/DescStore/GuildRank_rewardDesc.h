#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_RANK_REWARD_NUM 256

class GuildRank_rewardDesc : public NFIDescTemplate<GuildRank_rewardDesc, proto_ff_s::E_GuildRank_reward_s, EOT_CONST_GUILD_RANK_REWARD_DESC_ID, MAX_GUILD_RANK_REWARD_NUM>
{
public:
	GuildRank_rewardDesc();
	virtual ~GuildRank_rewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
