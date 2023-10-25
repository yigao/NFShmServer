#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_EQUIP_NUM 64

class ShenequipEquipDesc : public NFIDescStore
{
public:
	ShenequipEquipDesc();
	virtual ~ShenequipEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShenequipEquip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipEquip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipEquip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipEquip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShenequipEquipDesc, proto_ff_s::E_ShenequipEquip_s, E_ShenequipEquip, MAX_SHENEQUIP_EQUIP_NUM);
DECLARE_IDCREATE_GLOBAL(ShenequipEquipDesc);
};
