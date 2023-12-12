#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_CONDITION_NUM 2

class GiftConditionDesc : public NFIDescTemplate<GiftConditionDesc, proto_ff_s::E_GiftCondition_s, EOT_CONST_GIFT_CONDITION_DESC_ID, MAX_GIFT_CONDITION_NUM>
{
public:
	GiftConditionDesc();
	virtual ~GiftConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
