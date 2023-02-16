#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_REWARD_NUM 2000

class EscortRewardDesc : public NFIDescStore
{
public:
	EscortRewardDesc();
	virtual ~EscortRewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EscortReward_s* GetDesc(int id) const;
	proto_ff_s::E_EscortReward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EscortReward_s, E_EscortReward, MAX_ESCORT_REWARD_NUM);
DECLARE_IDCREATE(EscortRewardDesc);
};
