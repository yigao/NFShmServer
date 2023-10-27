#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_FIRSTCHARGE_NUM 8

class WelfareFirstchargeDesc : public NFIDescTemplate<WelfareFirstchargeDesc, proto_ff_s::E_WelfareFirstcharge_s, EOT_CONST_WELFARE_FIRSTCHARGE_DESC_ID, MAX_WELFARE_FIRSTCHARGE_NUM>
{
public:
	WelfareFirstchargeDesc();
	virtual ~WelfareFirstchargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
