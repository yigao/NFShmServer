#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_WEEKENDGIFT_NUM 8

class WelfareWeekendgiftDesc : public NFIDescTemplate<WelfareWeekendgiftDesc, proto_ff_s::E_WelfareWeekendgift_s, EOT_CONST_WELFARE_WEEKENDGIFT_DESC_ID, MAX_WELFARE_WEEKENDGIFT_NUM>
{
public:
	WelfareWeekendgiftDesc();
	virtual ~WelfareWeekendgiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
