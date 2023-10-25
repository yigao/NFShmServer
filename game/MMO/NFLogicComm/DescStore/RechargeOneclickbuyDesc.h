#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Recharge_s.h"

#define MAX_RECHARGE_ONECLICKBUY_NUM 4

class RechargeOneclickbuyDesc : public NFIDescStore
{
public:
	RechargeOneclickbuyDesc();
	virtual ~RechargeOneclickbuyDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RechargeOneclickbuy_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RechargeOneclickbuy_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RechargeOneclickbuy_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RechargeOneclickbuy_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RechargeOneclickbuyDesc, proto_ff_s::E_RechargeOneclickbuy_s, E_RechargeOneclickbuy, MAX_RECHARGE_ONECLICKBUY_NUM);
DECLARE_IDCREATE_GLOBAL(RechargeOneclickbuyDesc);
};
