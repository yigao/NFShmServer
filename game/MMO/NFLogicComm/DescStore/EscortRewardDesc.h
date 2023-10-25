#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_REWARD_NUM 2048

class EscortRewardDesc : public NFIDescStore
{
public:
	EscortRewardDesc();
	virtual ~EscortRewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EscortReward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EscortReward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EscortReward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EscortReward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EscortRewardDesc, proto_ff_s::E_EscortReward_s, E_EscortReward, MAX_ESCORT_REWARD_NUM);
DECLARE_IDCREATE_GLOBAL(EscortRewardDesc);
};
