#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_SPORTS_NUM 16

class DailySportsDesc : public NFIDescTemplate<DailySportsDesc, proto_ff_s::E_DailySports_s, EOT_CONST_DAILY_SPORTS_DESC_ID, MAX_DAILY_SPORTS_NUM>
{
public:
	DailySportsDesc();
	virtual ~DailySportsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
