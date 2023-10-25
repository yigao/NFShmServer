#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_GEMLV_NUM 512

class EquipGemlvDesc : public NFIDescStore
{
public:
	EquipGemlvDesc();
	virtual ~EquipGemlvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipGemlv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipGemlv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipGemlv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipGemlv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipGemlvDesc, proto_ff_s::E_EquipGemlv_s, E_EquipGemlv, MAX_EQUIP_GEMLV_NUM);
DECLARE_IDCREATE_GLOBAL(EquipGemlvDesc);
};
