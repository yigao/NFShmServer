#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Recharge_s.h"

#define MAX_RECHARGE_RECHARGE_NUM 128

class RechargeRechargeDesc : public NFIDescStore
{
public:
	RechargeRechargeDesc();
	virtual ~RechargeRechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RechargeRecharge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RechargeRecharge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RechargeRecharge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RechargeRecharge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RechargeRechargeDesc, proto_ff_s::E_RechargeRecharge_s, E_RechargeRecharge, MAX_RECHARGE_RECHARGE_NUM);
DECLARE_IDCREATE(RechargeRechargeDesc);
};
