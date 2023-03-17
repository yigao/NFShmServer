#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Godvalley_s.h"

#define MAX_GODVALLEY_REWARDS_NUM 20

class GodvalleyRewardsDesc : public NFIDescStore
{
public:
	GodvalleyRewardsDesc();
	virtual ~GodvalleyRewardsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodvalleyRewards_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodvalleyRewards_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodvalleyRewards_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodvalleyRewards_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodvalleyRewardsDesc, proto_ff_s::E_GodvalleyRewards_s, E_GodvalleyRewards, MAX_GODVALLEY_REWARDS_NUM);
DECLARE_IDCREATE(GodvalleyRewardsDesc);
};
