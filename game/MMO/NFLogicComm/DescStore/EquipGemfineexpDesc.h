#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_GEMFINEEXP_NUM 300

class EquipGemfineexpDesc : public NFIDescStore
{
public:
	EquipGemfineexpDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipGemfineexpDesc();
	const proto_ff_s::equipgemfineexp_s* GetDesc(int id) const;
	proto_ff_s::equipgemfineexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipgemfineexp_s, MAX_EQUIP_GEMFINEEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipgemfineexp_s, MAX_EQUIP_GEMFINEEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipgemfineexp_s, equipgemfineexp, MAX_EQUIP_GEMFINEEXP_NUM);
DECLARE_IDCREATE(EquipGemfineexpDesc);
};
