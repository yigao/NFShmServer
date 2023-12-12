#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_SMALL_NUM 128

class MarketSmallDesc : public NFIDescTemplate<MarketSmallDesc, proto_ff_s::E_MarketSmall_s, EOT_CONST_MARKET_SMALL_DESC_ID, MAX_MARKET_SMALL_NUM>
{
public:
	MarketSmallDesc();
	virtual ~MarketSmallDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
