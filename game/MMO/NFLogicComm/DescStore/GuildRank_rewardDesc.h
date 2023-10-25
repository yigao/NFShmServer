#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_RANK_REWARD_NUM 256

class GuildRank_rewardDesc : public NFIDescStore
{
public:
	GuildRank_rewardDesc();
	virtual ~GuildRank_rewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildRank_reward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildRank_reward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildRank_reward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildRank_reward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildRank_rewardDesc, proto_ff_s::E_GuildRank_reward_s, E_GuildRank_reward, MAX_GUILD_RANK_REWARD_NUM);
DECLARE_IDCREATE_GLOBAL(GuildRank_rewardDesc);
};
