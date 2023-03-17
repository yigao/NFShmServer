#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_EQUIP_NUM 20

class ShenequipEquipDesc : public NFIDescStore
{
public:
	ShenequipEquipDesc();
	virtual ~ShenequipEquipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipEquip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipEquip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipEquip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipEquip_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipEquipDesc, proto_ff_s::E_ShenequipEquip_s, E_ShenequipEquip, MAX_SHENEQUIP_EQUIP_NUM);
DECLARE_IDCREATE(ShenequipEquipDesc);
};
