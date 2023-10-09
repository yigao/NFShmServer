#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_BOSSFRISTKILL_NUM 64

class FestivalMuban_bossfristkillDesc : public NFIDescStore
{
public:
	FestivalMuban_bossfristkillDesc();
	virtual ~FestivalMuban_bossfristkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_bossfristkill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_bossfristkill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_bossfristkill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_bossfristkill_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_bossfristkillDesc, proto_ff_s::E_FestivalMuban_bossfristkill_s, E_FestivalMuban_bossfristkill, MAX_FESTIVAL_MUBAN_BOSSFRISTKILL_NUM);
DECLARE_IDCREATE(FestivalMuban_bossfristkillDesc);
};
