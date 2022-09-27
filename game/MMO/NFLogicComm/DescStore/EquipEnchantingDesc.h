#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_ENCHANTING_NUM 700

class EquipEnchantingDesc : public NFIDescStore
{
public:
	EquipEnchantingDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipEnchantingDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipenchanting_s* GetDesc(int id) const;
	proto_ff_s::equipenchanting_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipenchanting_s, MAX_EQUIP_ENCHANTING_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipenchanting_s, MAX_EQUIP_ENCHANTING_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipenchanting_s, equipenchanting, MAX_EQUIP_ENCHANTING_NUM);
DECLARE_IDCREATE(EquipEnchantingDesc);
};
