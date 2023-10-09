#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_AWAKEN_NUM 20

class ShenequipAwakenDesc : public NFIDescStore
{
public:
	ShenequipAwakenDesc();
	virtual ~ShenequipAwakenDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipAwaken_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipAwaken_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipAwaken_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipAwaken_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipAwakenDesc, proto_ff_s::E_ShenequipAwaken_s, E_ShenequipAwaken, MAX_SHENEQUIP_AWAKEN_NUM);
DECLARE_IDCREATE(ShenequipAwakenDesc);
};
