#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_RATIO_NUM 64

class FestivalMuban_rturntable_recharge_ratioDesc : public NFIDescStore
{
public:
	FestivalMuban_rturntable_recharge_ratioDesc();
	virtual ~FestivalMuban_rturntable_recharge_ratioDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_rturntable_recharge_ratioDesc, proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s, E_FestivalMuban_rturntable_recharge_ratio, MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_RATIO_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_rturntable_recharge_ratioDesc);
};
