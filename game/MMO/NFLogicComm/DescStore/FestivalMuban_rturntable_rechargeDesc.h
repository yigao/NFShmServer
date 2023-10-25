#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_NUM 16

class FestivalMuban_rturntable_rechargeDesc : public NFIDescStore
{
public:
	FestivalMuban_rturntable_rechargeDesc();
	virtual ~FestivalMuban_rturntable_rechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_rturntable_recharge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_rturntable_recharge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_rturntable_recharge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_rturntable_recharge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_rturntable_rechargeDesc, proto_ff_s::E_FestivalMuban_rturntable_recharge_s, E_FestivalMuban_rturntable_recharge, MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_rturntable_rechargeDesc);
};
