#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_TURNTABLE_POOL_NUM 16

class FestivalMuban_turntable_poolDesc : public NFIDescStore
{
public:
	FestivalMuban_turntable_poolDesc();
	virtual ~FestivalMuban_turntable_poolDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_turntable_pool_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_turntable_pool_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_turntable_pool_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_turntable_pool_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_turntable_poolDesc, proto_ff_s::E_FestivalMuban_turntable_pool_s, E_FestivalMuban_turntable_pool, MAX_FESTIVAL_MUBAN_TURNTABLE_POOL_NUM);
DECLARE_IDCREATE(FestivalMuban_turntable_poolDesc);
};
