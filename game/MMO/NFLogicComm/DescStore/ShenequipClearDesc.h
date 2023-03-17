#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_CLEAR_NUM 140

class ShenequipClearDesc : public NFIDescStore
{
public:
	ShenequipClearDesc();
	virtual ~ShenequipClearDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipClear_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipClear_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipClear_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipClear_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipClearDesc, proto_ff_s::E_ShenequipClear_s, E_ShenequipClear, MAX_SHENEQUIP_CLEAR_NUM);
DECLARE_IDCREATE(ShenequipClearDesc);
};
