#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_DAILY_NUM 64

class DailyDailyDesc : public NFIDescTemplate<DailyDailyDesc, proto_ff_s::E_DailyDaily_s, EOT_CONST_DAILY_DAILY_DESC_ID, MAX_DAILY_DAILY_NUM>
{
public:
	DailyDailyDesc();
	virtual ~DailyDailyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
