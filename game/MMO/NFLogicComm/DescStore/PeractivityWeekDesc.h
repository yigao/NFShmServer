#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peractivity_s.h"

#define MAX_PERACTIVITY_WEEK_NUM 32

class PeractivityWeekDesc : public NFIDescTemplate<PeractivityWeekDesc, proto_ff_s::E_PeractivityWeek_s, EOT_CONST_PERACTIVITY_WEEK_DESC_ID, MAX_PERACTIVITY_WEEK_NUM>
{
public:
	PeractivityWeekDesc();
	virtual ~PeractivityWeekDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
