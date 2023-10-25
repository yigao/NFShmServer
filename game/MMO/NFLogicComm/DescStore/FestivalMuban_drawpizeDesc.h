#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_NUM 4

class FestivalMuban_drawpizeDesc : public NFIDescStore
{
public:
	FestivalMuban_drawpizeDesc();
	virtual ~FestivalMuban_drawpizeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_drawpize_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_drawpize_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_drawpize_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_drawpize_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_drawpizeDesc, proto_ff_s::E_FestivalMuban_drawpize_s, E_FestivalMuban_drawpize, MAX_FESTIVAL_MUBAN_DRAWPIZE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_drawpizeDesc);
};
