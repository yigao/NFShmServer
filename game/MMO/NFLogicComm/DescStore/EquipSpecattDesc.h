#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_SPECATT_NUM 128

class EquipSpecattDesc : public NFIDescStore
{
public:
	EquipSpecattDesc();
	virtual ~EquipSpecattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipSpecatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipSpecatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipSpecatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipSpecatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipSpecattDesc, proto_ff_s::E_EquipSpecatt_s, E_EquipSpecatt, MAX_EQUIP_SPECATT_NUM);
DECLARE_IDCREATE(EquipSpecattDesc);
};
