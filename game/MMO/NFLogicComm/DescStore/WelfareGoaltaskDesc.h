#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_GOALTASK_NUM 16

class WelfareGoaltaskDesc : public NFIDescTemplate<WelfareGoaltaskDesc, proto_ff_s::E_WelfareGoaltask_s, EOT_CONST_WELFARE_GOALTASK_DESC_ID, MAX_WELFARE_GOALTASK_NUM>
{
public:
	WelfareGoaltaskDesc();
	virtual ~WelfareGoaltaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
