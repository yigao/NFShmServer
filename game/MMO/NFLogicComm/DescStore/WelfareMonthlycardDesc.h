#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_MONTHLYCARD_NUM 16

class WelfareMonthlycardDesc : public NFIDescTemplate<WelfareMonthlycardDesc, proto_ff_s::E_WelfareMonthlycard_s, EOT_CONST_WELFARE_MONTHLYCARD_DESC_ID, MAX_WELFARE_MONTHLYCARD_NUM>
{
public:
	WelfareMonthlycardDesc();
	virtual ~WelfareMonthlycardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
