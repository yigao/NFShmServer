#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_SCORE_NUM 8

class FestivalMuban_play_scoreDesc : public NFIDescStore
{
public:
	FestivalMuban_play_scoreDesc();
	virtual ~FestivalMuban_play_scoreDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_play_score_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_play_score_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_play_score_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_play_score_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_play_scoreDesc, proto_ff_s::E_FestivalMuban_play_score_s, E_FestivalMuban_play_score, MAX_FESTIVAL_MUBAN_PLAY_SCORE_NUM);
DECLARE_IDCREATE(FestivalMuban_play_scoreDesc);
};
