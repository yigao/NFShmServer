#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_RANK_DATA_NUM 8

class FestivalMuban_love_rank_dataDesc : public NFIDescStore
{
public:
	FestivalMuban_love_rank_dataDesc();
	virtual ~FestivalMuban_love_rank_dataDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_love_rank_data_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_love_rank_data_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_love_rank_data_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_love_rank_data_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_love_rank_dataDesc, proto_ff_s::E_FestivalMuban_love_rank_data_s, E_FestivalMuban_love_rank_data, MAX_FESTIVAL_MUBAN_LOVE_RANK_DATA_NUM);
DECLARE_IDCREATE(FestivalMuban_love_rank_dataDesc);
};
