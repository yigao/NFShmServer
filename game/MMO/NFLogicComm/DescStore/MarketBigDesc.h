#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_BIG_NUM 16

class MarketBigDesc : public NFIDescStore
{
public:
	MarketBigDesc();
	virtual ~MarketBigDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarketBig_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarketBig_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarketBig_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarketBig_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarketBigDesc, proto_ff_s::E_MarketBig_s, E_MarketBig, MAX_MARKET_BIG_NUM);
DECLARE_IDCREATE(MarketBigDesc);
};
