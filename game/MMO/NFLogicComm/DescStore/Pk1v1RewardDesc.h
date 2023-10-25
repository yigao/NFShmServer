#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_REWARD_NUM 32

class Pk1v1RewardDesc : public NFIDescStore
{
public:
	Pk1v1RewardDesc();
	virtual ~Pk1v1RewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk1v1Reward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk1v1Reward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk1v1Reward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk1v1Reward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk1v1RewardDesc, proto_ff_s::E_Pk1v1Reward_s, E_Pk1v1Reward, MAX_PK1V1_REWARD_NUM);
DECLARE_IDCREATE_GLOBAL(Pk1v1RewardDesc);
};
