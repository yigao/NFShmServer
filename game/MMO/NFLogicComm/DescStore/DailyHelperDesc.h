#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_HELPER_NUM 8

class DailyHelperDesc : public NFIDescTemplate<DailyHelperDesc, proto_ff_s::E_DailyHelper_s, EOT_CONST_DAILY_HELPER_DESC_ID, MAX_DAILY_HELPER_NUM>
{
public:
	DailyHelperDesc();
	virtual ~DailyHelperDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
