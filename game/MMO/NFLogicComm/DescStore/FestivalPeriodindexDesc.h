#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_PERIODINDEX_NUM 64

class FestivalPeriodindexDesc : public NFIDescStore
{
public:
	FestivalPeriodindexDesc();
	virtual ~FestivalPeriodindexDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalPeriodindex_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalPeriodindex_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalPeriodindex_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalPeriodindex_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalPeriodindexDesc, proto_ff_s::E_FestivalPeriodindex_s, E_FestivalPeriodindex, MAX_FESTIVAL_PERIODINDEX_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalPeriodindexDesc);
};
