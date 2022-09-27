#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_AWAKENING_NUM 700

class EquipAwakeningDesc : public NFIDescStore
{
public:
	EquipAwakeningDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipAwakeningDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipawakening_s* GetDesc(int id) const;
	proto_ff_s::equipawakening_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipawakening_s, MAX_EQUIP_AWAKENING_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipawakening_s, MAX_EQUIP_AWAKENING_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipawakening_s, equipawakening, MAX_EQUIP_AWAKENING_NUM);
DECLARE_IDCREATE(EquipAwakeningDesc);
};
