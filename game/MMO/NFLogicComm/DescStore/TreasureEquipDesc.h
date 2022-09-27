#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_EQUIP_NUM 40

class TreasureEquipDesc : public NFIDescStore
{
public:
	TreasureEquipDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureEquipDesc();
	const proto_ff_s::treasureequip_s* GetDesc(int id) const;
	proto_ff_s::treasureequip_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasureequip_s, MAX_TREASURE_EQUIP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasureequip_s, MAX_TREASURE_EQUIP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasureequip_s, treasureequip, MAX_TREASURE_EQUIP_NUM);
DECLARE_IDCREATE(TreasureEquipDesc);
};
