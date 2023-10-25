#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_NUM 2

class FestivalMuban_donateDesc : public NFIDescStore
{
public:
	FestivalMuban_donateDesc();
	virtual ~FestivalMuban_donateDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_donate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_donate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_donate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_donate_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_donateDesc, proto_ff_s::E_FestivalMuban_donate_s, E_FestivalMuban_donate, MAX_FESTIVAL_MUBAN_DONATE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_donateDesc);
};
