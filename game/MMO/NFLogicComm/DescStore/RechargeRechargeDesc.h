#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/recharge_s.h"

#define MAX_RECHARGE_RECHARGE_NUM 2000

class RechargeRechargeDesc : public NFIDescStore
{
public:
	RechargeRechargeDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargeRechargeDesc();
	const proto_ff_s::rechargerecharge_s* GetDesc(int id) const;
	proto_ff_s::rechargerecharge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargerecharge_s, MAX_RECHARGE_RECHARGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargerecharge_s, MAX_RECHARGE_RECHARGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargerecharge_s, rechargerecharge, MAX_RECHARGE_RECHARGE_NUM);
DECLARE_IDCREATE(RechargeRechargeDesc);
};
