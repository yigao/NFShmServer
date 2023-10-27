#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_DAILYREWARD_NUM 8

class Pk1v1DailyrewardDesc : public NFIDescTemplate<Pk1v1DailyrewardDesc, proto_ff_s::E_Pk1v1Dailyreward_s, EOT_CONST_PK1V1_DAILYREWARD_DESC_ID, MAX_PK1V1_DAILYREWARD_NUM>
{
public:
	Pk1v1DailyrewardDesc();
	virtual ~Pk1v1DailyrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
