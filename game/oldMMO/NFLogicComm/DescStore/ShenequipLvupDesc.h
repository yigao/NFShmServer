#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_LVUP_NUM 40

class ShenequipLvupDesc : public NFIDescStore
{
public:
	ShenequipLvupDesc();
	virtual ~ShenequipLvupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipLvup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipLvup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipLvup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipLvup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipLvupDesc, proto_ff_s::E_ShenequipLvup_s, E_ShenequipLvup, MAX_SHENEQUIP_LVUP_NUM);
DECLARE_IDCREATE(ShenequipLvupDesc);
};
