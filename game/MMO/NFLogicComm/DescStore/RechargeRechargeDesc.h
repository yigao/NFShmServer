#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Recharge_s.h"

#define MAX_RECHARGE_RECHARGE_NUM 128

class RechargeRechargeDesc : public NFIDescTemplate<RechargeRechargeDesc, proto_ff_s::E_RechargeRecharge_s, EOT_CONST_RECHARGE_RECHARGE_DESC_ID, MAX_RECHARGE_RECHARGE_NUM>
{
public:
	RechargeRechargeDesc();
	virtual ~RechargeRechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
