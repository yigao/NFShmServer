#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONG_NUM 200

class EquipStrongDesc : public NFIDescStore
{
public:
	EquipStrongDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipStrongDesc();
	const proto_ff_s::equipstrong_s* GetDesc(int id) const;
	proto_ff_s::equipstrong_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipstrong_s, MAX_EQUIP_STRONG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipstrong_s, MAX_EQUIP_STRONG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipstrong_s, equipstrong, MAX_EQUIP_STRONG_NUM);
DECLARE_IDCREATE(EquipStrongDesc);
};
