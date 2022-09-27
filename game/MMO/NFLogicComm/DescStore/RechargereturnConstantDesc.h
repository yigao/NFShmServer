#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/rechargeReturn_s.h"

#define MAX_RECHARGERETURN_CONSTANT_NUM 20

class RechargereturnConstantDesc : public NFIDescStore
{
public:
	RechargereturnConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargereturnConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rechargeReturnconstant_s* GetDesc(int id) const;
	proto_ff_s::rechargeReturnconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnconstant_s, MAX_RECHARGERETURN_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargeReturnconstant_s, MAX_RECHARGERETURN_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargeReturnconstant_s, rechargeReturnconstant, MAX_RECHARGERETURN_CONSTANT_NUM);
DECLARE_IDCREATE(RechargereturnConstantDesc);
};
