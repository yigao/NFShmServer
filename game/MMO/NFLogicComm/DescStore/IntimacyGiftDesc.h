#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Intimacy_s.h"

#define MAX_INTIMACY_GIFT_NUM 8

class IntimacyGiftDesc : public NFIDescTemplate<IntimacyGiftDesc, proto_ff_s::E_IntimacyGift_s, EOT_CONST_INTIMACY_GIFT_DESC_ID, MAX_INTIMACY_GIFT_NUM>
{
public:
	IntimacyGiftDesc();
	virtual ~IntimacyGiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
