#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/rechargeReturn_s.h"

#define MAX_RECHARGERETURN_CONTINUOUSRETURN_NUM 20

class RechargereturnContinuousreturnDesc : public NFIDescStore
{
public:
	RechargereturnContinuousreturnDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargereturnContinuousreturnDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rechargeReturncontinuousReturn_s* GetDesc(int id) const;
	proto_ff_s::rechargeReturncontinuousReturn_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargeReturncontinuousReturn_s, MAX_RECHARGERETURN_CONTINUOUSRETURN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargeReturncontinuousReturn_s, MAX_RECHARGERETURN_CONTINUOUSRETURN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargeReturncontinuousReturn_s, rechargeReturncontinuousReturn, MAX_RECHARGERETURN_CONTINUOUSRETURN_NUM);
DECLARE_IDCREATE(RechargereturnContinuousreturnDesc);
};
