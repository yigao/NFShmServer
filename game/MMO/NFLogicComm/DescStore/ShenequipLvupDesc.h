#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_LVUP_NUM 4096

class ShenequipLvupDesc : public NFIDescStore
{
public:
	ShenequipLvupDesc();
	virtual ~ShenequipLvupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShenequipLvup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipLvup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipLvup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipLvup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShenequipLvupDesc, proto_ff_s::E_ShenequipLvup_s, E_ShenequipLvup, MAX_SHENEQUIP_LVUP_NUM);
DECLARE_IDCREATE_GLOBAL(ShenequipLvupDesc);
};
