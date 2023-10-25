#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_BEASTSTRONG_NUM 128

class EquipBeaststrongDesc : public NFIDescStore
{
public:
	EquipBeaststrongDesc();
	virtual ~EquipBeaststrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipBeaststrong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipBeaststrong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipBeaststrong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipBeaststrong_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipBeaststrongDesc, proto_ff_s::E_EquipBeaststrong_s, E_EquipBeaststrong, MAX_EQUIP_BEASTSTRONG_NUM);
DECLARE_IDCREATE_GLOBAL(EquipBeaststrongDesc);
};
