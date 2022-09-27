#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/rechargeReturn_s.h"

#define MAX_RECHARGERETURN_TIME_NUM 20

class RechargereturnTimeDesc : public NFIDescStore
{
public:
	RechargereturnTimeDesc(NFIPluginManager* pPluginManager);
	virtual ~RechargereturnTimeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rechargeReturntime_s* GetDesc(int id) const;
	proto_ff_s::rechargeReturntime_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rechargeReturntime_s, MAX_RECHARGERETURN_TIME_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rechargeReturntime_s, MAX_RECHARGERETURN_TIME_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rechargeReturntime_s, rechargeReturntime, MAX_RECHARGERETURN_TIME_NUM);
DECLARE_IDCREATE(RechargereturnTimeDesc);
};
