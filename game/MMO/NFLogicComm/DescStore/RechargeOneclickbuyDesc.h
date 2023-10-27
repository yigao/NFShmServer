#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Recharge_s.h"

#define MAX_RECHARGE_ONECLICKBUY_NUM 4

class RechargeOneclickbuyDesc : public NFIDescTemplate<RechargeOneclickbuyDesc, proto_ff_s::E_RechargeOneclickbuy_s, EOT_CONST_RECHARGE_ONECLICKBUY_DESC_ID, MAX_RECHARGE_ONECLICKBUY_NUM>
{
public:
	RechargeOneclickbuyDesc();
	virtual ~RechargeOneclickbuyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
