#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONGTOTAL_NUM 200

class EquipStrongtotalDesc : public NFIDescStore
{
public:
	EquipStrongtotalDesc();
	virtual ~EquipStrongtotalDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStrongtotal_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStrongtotal_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStrongtotal_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStrongtotal_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EquipStrongtotalDesc, proto_ff_s::E_EquipStrongtotal_s, E_EquipStrongtotal, MAX_EQUIP_STRONGTOTAL_NUM);
DECLARE_IDCREATE(EquipStrongtotalDesc);
};
