#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/recharge_s.h"

#define MAX_RECHARGE_RECHARGE_NUM 2000

class RechargeRechargeDesc : public NFIDescStore
{
public:
	RechargeRechargeDesc();
	virtual ~RechargeRechargeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RechargeRecharge_s* GetDesc(int id) const;
	proto_ff_s::E_RechargeRecharge_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RechargeRecharge_s, E_RechargeRecharge, MAX_RECHARGE_RECHARGE_NUM);
DECLARE_IDCREATE(RechargeRechargeDesc);
};
