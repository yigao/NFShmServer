#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONGTOTAL_NUM 300

class EquipStrongtotalDesc : public NFIDescStore
{
public:
	EquipStrongtotalDesc();
	virtual ~EquipStrongtotalDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStrongtotal_s* GetDesc(int id) const;
	proto_ff_s::E_EquipStrongtotal_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipStrongtotal_s, equipstrongtotal, MAX_EQUIP_STRONGTOTAL_NUM);
DECLARE_IDCREATE(EquipStrongtotalDesc);
};
