#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/rechargeReturn_s.h"

#define MAX_RECHARGERETURN_RECHARGETRIGGER_NUM 60

class RechargereturnRechargetriggerDesc : public NFIDescStore
{
public:
	RechargereturnRechargetriggerDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargereturnRechargetriggerDesc();
	const proto_ff_s::rechargeReturnrechargeTrigger_s* GetDesc(int id) const;
	proto_ff_s::rechargeReturnrechargeTrigger_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnrechargeTrigger_s, MAX_RECHARGERETURN_RECHARGETRIGGER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnrechargeTrigger_s, MAX_RECHARGERETURN_RECHARGETRIGGER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargeReturnrechargeTrigger_s, rechargeReturnrechargeTrigger, MAX_RECHARGERETURN_RECHARGETRIGGER_NUM);
DECLARE_IDCREATE(RechargereturnRechargetriggerDesc);
};
