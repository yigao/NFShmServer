#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_REWARD_NUM 2048

class BattlepassRewardDesc : public NFIDescStore
{
public:
	BattlepassRewardDesc();
	virtual ~BattlepassRewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BattlepassReward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BattlepassReward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BattlepassReward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BattlepassReward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BattlepassRewardDesc, proto_ff_s::E_BattlepassReward_s, E_BattlepassReward, MAX_BATTLEPASS_REWARD_NUM);
DECLARE_IDCREATE_GLOBAL(BattlepassRewardDesc);
};
