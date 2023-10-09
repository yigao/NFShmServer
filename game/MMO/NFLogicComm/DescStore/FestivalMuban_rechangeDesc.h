#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RECHANGE_NUM 16

class FestivalMuban_rechangeDesc : public NFIDescStore
{
public:
	FestivalMuban_rechangeDesc();
	virtual ~FestivalMuban_rechangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_rechange_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_rechange_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_rechange_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_rechange_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_rechangeDesc, proto_ff_s::E_FestivalMuban_rechange_s, E_FestivalMuban_rechange, MAX_FESTIVAL_MUBAN_RECHANGE_NUM);
DECLARE_IDCREATE(FestivalMuban_rechangeDesc);
};
