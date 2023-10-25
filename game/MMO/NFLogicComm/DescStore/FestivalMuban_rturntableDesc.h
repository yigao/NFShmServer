#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_NUM 2

class FestivalMuban_rturntableDesc : public NFIDescStore
{
public:
	FestivalMuban_rturntableDesc();
	virtual ~FestivalMuban_rturntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_rturntable_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_rturntable_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_rturntable_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_rturntable_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_rturntableDesc, proto_ff_s::E_FestivalMuban_rturntable_s, E_FestivalMuban_rturntable, MAX_FESTIVAL_MUBAN_RTURNTABLE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_rturntableDesc);
};
