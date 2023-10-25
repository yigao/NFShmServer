#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_SMALL_NUM 128

class MarketSmallDesc : public NFIDescStore
{
public:
	MarketSmallDesc();
	virtual ~MarketSmallDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarketSmall_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarketSmall_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarketSmall_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarketSmall_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarketSmallDesc, proto_ff_s::E_MarketSmall_s, E_MarketSmall, MAX_MARKET_SMALL_NUM);
DECLARE_IDCREATE_GLOBAL(MarketSmallDesc);
};
