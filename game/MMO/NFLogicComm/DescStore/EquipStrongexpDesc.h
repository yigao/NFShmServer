#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONGEXP_NUM 800

class EquipStrongexpDesc : public NFIDescStore
{
public:
	EquipStrongexpDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipStrongexpDesc();
	const proto_ff_s::equipstrongexp_s* GetDesc(int id) const;
	proto_ff_s::equipstrongexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipstrongexp_s, MAX_EQUIP_STRONGEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipstrongexp_s, MAX_EQUIP_STRONGEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipstrongexp_s, equipstrongexp, MAX_EQUIP_STRONGEXP_NUM);
DECLARE_IDCREATE(EquipStrongexpDesc);
};
