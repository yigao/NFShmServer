#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_COST_NUM 8

class JinglianCostDesc : public NFIDescTemplate<JinglianCostDesc, proto_ff_s::E_JinglianCost_s, EOT_CONST_JINGLIAN_COST_DESC_ID, MAX_JINGLIAN_COST_NUM>
{
public:
	JinglianCostDesc();
	virtual ~JinglianCostDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
