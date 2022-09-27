#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_MARRY_NUM 1000

class EquipMarryDesc : public NFIDescStore
{
public:
	EquipMarryDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipMarryDesc();
	const proto_ff_s::equipmarry_s* GetDesc(int id) const;
	proto_ff_s::equipmarry_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipmarry_s, MAX_EQUIP_MARRY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipmarry_s, MAX_EQUIP_MARRY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipmarry_s, equipmarry, MAX_EQUIP_MARRY_NUM);
DECLARE_IDCREATE(EquipMarryDesc);
};
