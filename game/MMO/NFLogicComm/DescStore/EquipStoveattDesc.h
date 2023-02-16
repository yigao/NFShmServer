#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STOVEATT_NUM 2000

class EquipStoveattDesc : public NFIDescStore
{
public:
	EquipStoveattDesc();
	virtual ~EquipStoveattDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStoveatt_s* GetDesc(int id) const;
	proto_ff_s::E_EquipStoveatt_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipStoveatt_s, E_EquipStoveatt, MAX_EQUIP_STOVEATT_NUM);
DECLARE_IDCREATE(EquipStoveattDesc);
};
