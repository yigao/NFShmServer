#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_GEM_NUM 20

class EquipGemDesc : public NFIDescStore
{
public:
	EquipGemDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipGemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipgem_s* GetDesc(int id) const;
	proto_ff_s::equipgem_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipgem_s, MAX_EQUIP_GEM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipgem_s, MAX_EQUIP_GEM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipgem_s, equipgem, MAX_EQUIP_GEM_NUM);
DECLARE_IDCREATE(EquipGemDesc);
};
