#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_KFLEICHONG_NUM 16

class WelfareKfleichongDesc : public NFIDescTemplate<WelfareKfleichongDesc, proto_ff_s::E_WelfareKfleichong_s, EOT_CONST_WELFARE_KFLEICHONG_DESC_ID, MAX_WELFARE_KFLEICHONG_NUM>
{
public:
	WelfareKfleichongDesc();
	virtual ~WelfareKfleichongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
