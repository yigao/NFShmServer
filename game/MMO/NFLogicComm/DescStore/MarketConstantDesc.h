#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Market_s.h"

#define MAX_MARKET_CONSTANT_NUM 2

class MarketConstantDesc : public NFIDescTemplate<MarketConstantDesc, proto_ff_s::E_MarketConstant_s, EOT_CONST_MARKET_CONSTANT_DESC_ID, MAX_MARKET_CONSTANT_NUM>
{
public:
	MarketConstantDesc();
	virtual ~MarketConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
