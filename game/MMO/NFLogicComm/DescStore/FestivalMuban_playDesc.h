#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_NUM 2

class FestivalMuban_playDesc : public NFIDescStore
{
public:
	FestivalMuban_playDesc();
	virtual ~FestivalMuban_playDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_play_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_play_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_play_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_play_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_playDesc, proto_ff_s::E_FestivalMuban_play_s, E_FestivalMuban_play, MAX_FESTIVAL_MUBAN_PLAY_NUM);
DECLARE_IDCREATE(FestivalMuban_playDesc);
};
