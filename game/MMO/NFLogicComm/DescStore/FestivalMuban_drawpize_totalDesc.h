#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_TOTAL_NUM 64

class FestivalMuban_drawpize_totalDesc : public NFIDescStore
{
public:
	FestivalMuban_drawpize_totalDesc();
	virtual ~FestivalMuban_drawpize_totalDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_drawpize_total_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_drawpize_total_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_drawpize_total_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_drawpize_total_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_drawpize_totalDesc, proto_ff_s::E_FestivalMuban_drawpize_total_s, E_FestivalMuban_drawpize_total, MAX_FESTIVAL_MUBAN_DRAWPIZE_TOTAL_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_drawpize_totalDesc);
};
