#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_GOAL_NUM 2

class WelfareGoalDesc : public NFIDescTemplate<WelfareGoalDesc, proto_ff_s::E_WelfareGoal_s, EOT_CONST_WELFARE_GOAL_DESC_ID, MAX_WELFARE_GOAL_NUM>
{
public:
	WelfareGoalDesc();
	virtual ~WelfareGoalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
