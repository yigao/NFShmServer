#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_BIG_NUM 16

class MarketBigDesc : public NFIDescTemplate<MarketBigDesc, proto_ff_s::E_MarketBig_s, EOT_CONST_MARKET_BIG_DESC_ID, MAX_MARKET_BIG_NUM>
{
public:
	MarketBigDesc();
	virtual ~MarketBigDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
