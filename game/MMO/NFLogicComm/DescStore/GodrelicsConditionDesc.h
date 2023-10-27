#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godrelics_s.h"

#define MAX_GODRELICS_CONDITION_NUM 128

class GodrelicsConditionDesc : public NFIDescTemplate<GodrelicsConditionDesc, proto_ff_s::E_GodrelicsCondition_s, EOT_CONST_GODRELICS_CONDITION_DESC_ID, MAX_GODRELICS_CONDITION_NUM>
{
public:
	GodrelicsConditionDesc();
	virtual ~GodrelicsConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
