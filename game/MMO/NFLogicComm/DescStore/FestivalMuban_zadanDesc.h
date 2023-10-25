#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_ZADAN_NUM 64

class FestivalMuban_zadanDesc : public NFIDescStore
{
public:
	FestivalMuban_zadanDesc();
	virtual ~FestivalMuban_zadanDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_zadan_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_zadan_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_zadan_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_zadan_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_zadanDesc, proto_ff_s::E_FestivalMuban_zadan_s, E_FestivalMuban_zadan, MAX_FESTIVAL_MUBAN_ZADAN_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_zadanDesc);
};
