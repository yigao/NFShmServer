#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_TURNTABLE_NUM 2

class FestivalMuban_turntableDesc : public NFIDescStore
{
public:
	FestivalMuban_turntableDesc();
	virtual ~FestivalMuban_turntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_turntable_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_turntable_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_turntable_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_turntable_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_turntableDesc, proto_ff_s::E_FestivalMuban_turntable_s, E_FestivalMuban_turntable, MAX_FESTIVAL_MUBAN_TURNTABLE_NUM);
DECLARE_IDCREATE(FestivalMuban_turntableDesc);
};
