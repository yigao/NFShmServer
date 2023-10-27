#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_CULTIVATE_NUM 1024

class DailyCultivateDesc : public NFIDescTemplate<DailyCultivateDesc, proto_ff_s::E_DailyCultivate_s, EOT_CONST_DAILY_CULTIVATE_DESC_ID, MAX_DAILY_CULTIVATE_NUM>
{
public:
	DailyCultivateDesc();
	virtual ~DailyCultivateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
