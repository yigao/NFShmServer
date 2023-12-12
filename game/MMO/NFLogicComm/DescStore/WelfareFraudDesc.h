#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_FRAUD_NUM 16

class WelfareFraudDesc : public NFIDescTemplate<WelfareFraudDesc, proto_ff_s::E_WelfareFraud_s, EOT_CONST_WELFARE_FRAUD_DESC_ID, MAX_WELFARE_FRAUD_NUM>
{
public:
	WelfareFraudDesc();
	virtual ~WelfareFraudDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
