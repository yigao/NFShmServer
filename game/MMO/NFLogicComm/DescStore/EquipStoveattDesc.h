#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STOVEATT_NUM 2048

class EquipStoveattDesc : public NFIDescStore
{
public:
	EquipStoveattDesc();
	virtual ~EquipStoveattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipStoveatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStoveatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStoveatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStoveatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipStoveattDesc, proto_ff_s::E_EquipStoveatt_s, E_EquipStoveatt, MAX_EQUIP_STOVEATT_NUM);
DECLARE_IDCREATE(EquipStoveattDesc);
};
