#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_GEM_NUM 20

class EquipGemDesc : public NFIDescStore
{
public:
	EquipGemDesc();
	virtual ~EquipGemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipGem_s* GetDesc(int id) const;
	proto_ff_s::E_EquipGem_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipGem_s, equipgem, MAX_EQUIP_GEM_NUM);
DECLARE_IDCREATE(EquipGemDesc);
};
