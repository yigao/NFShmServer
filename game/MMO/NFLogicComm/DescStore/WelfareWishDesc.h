#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_WISH_NUM 2048

class WelfareWishDesc : public NFIDescTemplate<WelfareWishDesc, proto_ff_s::E_WelfareWish_s, EOT_CONST_WELFARE_WISH_DESC_ID, MAX_WELFARE_WISH_NUM>
{
public:
	WelfareWishDesc();
	virtual ~WelfareWishDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
