#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_GAME_NUM 64

class FestivalMuban_play_gameDesc : public NFIDescTemplate<FestivalMuban_play_gameDesc, proto_ff_s::E_FestivalMuban_play_game_s, EOT_CONST_FESTIVAL_MUBAN_PLAY_GAME_DESC_ID, MAX_FESTIVAL_MUBAN_PLAY_GAME_NUM>
{
public:
	FestivalMuban_play_gameDesc();
	virtual ~FestivalMuban_play_gameDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
