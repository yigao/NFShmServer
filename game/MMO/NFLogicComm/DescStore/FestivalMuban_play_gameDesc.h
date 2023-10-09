#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_GAME_NUM 64

class FestivalMuban_play_gameDesc : public NFIDescStore
{
public:
	FestivalMuban_play_gameDesc();
	virtual ~FestivalMuban_play_gameDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_play_game_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_play_game_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_play_game_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_play_game_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_play_gameDesc, proto_ff_s::E_FestivalMuban_play_game_s, E_FestivalMuban_play_game, MAX_FESTIVAL_MUBAN_PLAY_GAME_NUM);
DECLARE_IDCREATE(FestivalMuban_play_gameDesc);
};
