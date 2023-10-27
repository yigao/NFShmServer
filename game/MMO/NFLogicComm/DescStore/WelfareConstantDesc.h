#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_CONSTANT_NUM 2

class WelfareConstantDesc : public NFIDescTemplate<WelfareConstantDesc, proto_ff_s::E_WelfareConstant_s, EOT_CONST_WELFARE_CONSTANT_DESC_ID, MAX_WELFARE_CONSTANT_NUM>
{
public:
	WelfareConstantDesc();
	virtual ~WelfareConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
