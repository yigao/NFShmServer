#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_SINGLE_NUM 8

class FestivalMuban_donate_singleDesc : public NFIDescStore
{
public:
	FestivalMuban_donate_singleDesc();
	virtual ~FestivalMuban_donate_singleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_donate_single_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_donate_single_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_donate_single_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_donate_single_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_donate_singleDesc, proto_ff_s::E_FestivalMuban_donate_single_s, E_FestivalMuban_donate_single, MAX_FESTIVAL_MUBAN_DONATE_SINGLE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_donate_singleDesc);
};
