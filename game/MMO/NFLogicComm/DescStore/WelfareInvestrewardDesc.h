#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_INVESTREWARD_NUM 64

class WelfareInvestrewardDesc : public NFIDescTemplate<WelfareInvestrewardDesc, proto_ff_s::E_WelfareInvestreward_s, EOT_CONST_WELFARE_INVESTREWARD_DESC_ID, MAX_WELFARE_INVESTREWARD_NUM>
{
public:
	WelfareInvestrewardDesc();
	virtual ~WelfareInvestrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
