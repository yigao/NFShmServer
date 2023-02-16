#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_EQUIP_NUM 160

class EquipEquipDesc : public NFIDescStore
{
public:
	EquipEquipDesc();
	virtual ~EquipEquipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipEquip_s* GetDesc(int id) const;
	proto_ff_s::E_EquipEquip_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipEquip_s, E_EquipEquip, MAX_EQUIP_EQUIP_NUM);
DECLARE_IDCREATE(EquipEquipDesc);
};
