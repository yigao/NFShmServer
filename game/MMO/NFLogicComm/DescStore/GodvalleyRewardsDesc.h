#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godvalley_s.h"

#define MAX_GODVALLEY_REWARDS_NUM 16

class GodvalleyRewardsDesc : public NFIDescStore
{
public:
	GodvalleyRewardsDesc();
	virtual ~GodvalleyRewardsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodvalleyRewards_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodvalleyRewards_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodvalleyRewards_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodvalleyRewards_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodvalleyRewardsDesc, proto_ff_s::E_GodvalleyRewards_s, E_GodvalleyRewards, MAX_GODVALLEY_REWARDS_NUM);
DECLARE_IDCREATE_GLOBAL(GodvalleyRewardsDesc);
};
