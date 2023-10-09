#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_GEM_NUM 16

class EquipGemDesc : public NFIDescStore
{
public:
	EquipGemDesc();
	virtual ~EquipGemDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipGem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipGem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipGem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipGem_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipGemDesc, proto_ff_s::E_EquipGem_s, E_EquipGem, MAX_EQUIP_GEM_NUM);
DECLARE_IDCREATE(EquipGemDesc);
};
