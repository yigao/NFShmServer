#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_REWARD_NUM 8

class FestivalMuban_play_rewardDesc : public NFIDescTemplate<FestivalMuban_play_rewardDesc, proto_ff_s::E_FestivalMuban_play_reward_s, EOT_CONST_FESTIVAL_MUBAN_PLAY_REWARD_DESC_ID, MAX_FESTIVAL_MUBAN_PLAY_REWARD_NUM>
{
public:
	FestivalMuban_play_rewardDesc();
	virtual ~FestivalMuban_play_rewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
