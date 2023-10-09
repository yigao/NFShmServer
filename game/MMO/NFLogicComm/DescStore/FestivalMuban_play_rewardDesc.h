#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_REWARD_NUM 8

class FestivalMuban_play_rewardDesc : public NFIDescStore
{
public:
	FestivalMuban_play_rewardDesc();
	virtual ~FestivalMuban_play_rewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_play_reward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_play_reward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_play_reward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_play_reward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_play_rewardDesc, proto_ff_s::E_FestivalMuban_play_reward_s, E_FestivalMuban_play_reward, MAX_FESTIVAL_MUBAN_PLAY_REWARD_NUM);
DECLARE_IDCREATE(FestivalMuban_play_rewardDesc);
};
