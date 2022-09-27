#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_MAP_NUM 200

class MapMapDesc : public NFIDescStore
{
public:
	MapMapDesc(NFIPluginManager* pPluginManager);
	virtual ~MapMapDesc();
	const proto_ff_s::mapmap_s* GetDesc(int id) const;
	proto_ff_s::mapmap_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mapmap_s, MAX_MAP_MAP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mapmap_s, MAX_MAP_MAP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mapmap_s, mapmap, MAX_MAP_MAP_NUM);
DECLARE_IDCREATE(MapMapDesc);
};
