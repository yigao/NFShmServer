#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_INVEST_NUM 8

class WelfareInvestDesc : public NFIDescTemplate<WelfareInvestDesc, proto_ff_s::E_WelfareInvest_s, EOT_CONST_WELFARE_INVEST_DESC_ID, MAX_WELFARE_INVEST_NUM>
{
public:
	WelfareInvestDesc();
	virtual ~WelfareInvestDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
