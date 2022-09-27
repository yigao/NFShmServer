#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/rechargeReturn_s.h"

#define MAX_RECHARGERETURN_RECHARGERETURN_NUM 20

class RechargereturnRechargereturnDesc : public NFIDescStore
{
public:
	RechargereturnRechargereturnDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargereturnRechargereturnDesc();
	const proto_ff_s::rechargeReturnrechargeReturn_s* GetDesc(int id) const;
	proto_ff_s::rechargeReturnrechargeReturn_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnrechargeReturn_s, MAX_RECHARGERETURN_RECHARGERETURN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnrechargeReturn_s, MAX_RECHARGERETURN_RECHARGERETURN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargeReturnrechargeReturn_s, rechargeReturnrechargeReturn, MAX_RECHARGERETURN_RECHARGERETURN_NUM);
DECLARE_IDCREATE(RechargereturnRechargereturnDesc);
};
