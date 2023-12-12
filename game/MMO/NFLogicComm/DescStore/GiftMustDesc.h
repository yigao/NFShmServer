#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_MUST_NUM 32

class GiftMustDesc : public NFIDescTemplate<GiftMustDesc, proto_ff_s::E_GiftMust_s, EOT_CONST_GIFT_MUST_DESC_ID, MAX_GIFT_MUST_NUM>
{
public:
	GiftMustDesc();
	virtual ~GiftMustDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
