#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_SUIT_NUM 120

class EquipSuitDesc : public NFIDescStore
{
public:
	EquipSuitDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipSuitDesc();
	const proto_ff_s::equipsuit_s* GetDesc(int id) const;
	proto_ff_s::equipsuit_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipsuit_s, MAX_EQUIP_SUIT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipsuit_s, MAX_EQUIP_SUIT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipsuit_s, equipsuit, MAX_EQUIP_SUIT_NUM);
DECLARE_IDCREATE(EquipSuitDesc);
};
