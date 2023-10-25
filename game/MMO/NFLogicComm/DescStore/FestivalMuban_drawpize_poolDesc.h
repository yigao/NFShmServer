#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_POOL_NUM 64

class FestivalMuban_drawpize_poolDesc : public NFIDescStore
{
public:
	FestivalMuban_drawpize_poolDesc();
	virtual ~FestivalMuban_drawpize_poolDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_drawpize_pool_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_drawpize_pool_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_drawpize_pool_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_drawpize_pool_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_drawpize_poolDesc, proto_ff_s::E_FestivalMuban_drawpize_pool_s, E_FestivalMuban_drawpize_pool, MAX_FESTIVAL_MUBAN_DRAWPIZE_POOL_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_drawpize_poolDesc);
};
