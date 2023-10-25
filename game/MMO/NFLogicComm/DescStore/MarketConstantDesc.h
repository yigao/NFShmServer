#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_CONSTANT_NUM 2

class MarketConstantDesc : public NFIDescStore
{
public:
	MarketConstantDesc();
	virtual ~MarketConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarketConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarketConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarketConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarketConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarketConstantDesc, proto_ff_s::E_MarketConstant_s, E_MarketConstant, MAX_MARKET_CONSTANT_NUM);
DECLARE_IDCREATE_GLOBAL(MarketConstantDesc);
};
