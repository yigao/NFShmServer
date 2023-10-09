#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_EQUIP_NUM 11000

class EquipEquipDesc : public NFIDescStore
{
public:
	EquipEquipDesc();
	virtual ~EquipEquipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipEquip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipEquip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipEquip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipEquip_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EquipEquipDesc, proto_ff_s::E_EquipEquip_s, E_EquipEquip, MAX_EQUIP_EQUIP_NUM);
DECLARE_IDCREATE(EquipEquipDesc);
};
