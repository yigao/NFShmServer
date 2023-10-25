#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_MARKET_NUM 16384

class MarketMarketDesc : public NFIDescStore
{
public:
	MarketMarketDesc();
	virtual ~MarketMarketDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarketMarket_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarketMarket_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarketMarket_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarketMarket_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarketMarketDesc, proto_ff_s::E_MarketMarket_s, E_MarketMarket, MAX_MARKET_MARKET_NUM);
DECLARE_IDCREATE_GLOBAL(MarketMarketDesc);
};
