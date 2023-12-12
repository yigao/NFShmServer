#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_FREE_NUM 16

class GiftFreeDesc : public NFIDescTemplate<GiftFreeDesc, proto_ff_s::E_GiftFree_s, EOT_CONST_GIFT_FREE_DESC_ID, MAX_GIFT_FREE_NUM>
{
public:
	GiftFreeDesc();
	virtual ~GiftFreeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
