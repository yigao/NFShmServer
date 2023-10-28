#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_MARKET_NUM 1024

class MarketMarketDesc : public NFIDescTemplate<MarketMarketDesc, proto_ff_s::E_MarketMarket_s, EOT_CONST_MARKET_MARKET_DESC_ID, MAX_MARKET_MARKET_NUM>
{
public:
	MarketMarketDesc();
	virtual ~MarketMarketDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
