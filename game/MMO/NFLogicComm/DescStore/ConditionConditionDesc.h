#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Condition_s.h"

#define MAX_CONDITION_CONDITION_NUM 32

class ConditionConditionDesc : public NFIDescTemplate<ConditionConditionDesc, proto_ff_s::E_ConditionCondition_s, EOT_CONST_CONDITION_CONDITION_DESC_ID, MAX_CONDITION_CONDITION_NUM>
{
public:
	ConditionConditionDesc();
	virtual ~ConditionConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
