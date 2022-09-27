#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_ATT_NUM 200

class EquipAttDesc : public NFIDescStore
{
public:
	EquipAttDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipAttDesc();
	const proto_ff_s::equipatt_s* GetDesc(int id) const;
	proto_ff_s::equipatt_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipatt_s, MAX_EQUIP_ATT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipatt_s, MAX_EQUIP_ATT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipatt_s, equipatt, MAX_EQUIP_ATT_NUM);
DECLARE_IDCREATE(EquipAttDesc);
};
