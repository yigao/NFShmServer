#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_RANK_NUM 2

class FestivalMuban_love_rankDesc : public NFIDescStore
{
public:
	FestivalMuban_love_rankDesc();
	virtual ~FestivalMuban_love_rankDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_love_rank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_love_rank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_love_rank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_love_rank_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_love_rankDesc, proto_ff_s::E_FestivalMuban_love_rank_s, E_FestivalMuban_love_rank, MAX_FESTIVAL_MUBAN_LOVE_RANK_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_love_rankDesc);
};
