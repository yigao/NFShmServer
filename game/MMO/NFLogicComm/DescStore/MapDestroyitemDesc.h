#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_DESTROYITEM_NUM 200

class MapDestroyitemDesc : public NFIDescStore
{
public:
	MapDestroyitemDesc(NFIPluginManager* pPluginManager);
	virtual ~MapDestroyitemDesc();
	const proto_ff_s::mapdestroyitem_s* GetDesc(int id) const;
	proto_ff_s::mapdestroyitem_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mapdestroyitem_s, MAX_MAP_DESTROYITEM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mapdestroyitem_s, MAX_MAP_DESTROYITEM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mapdestroyitem_s, mapdestroyitem, MAX_MAP_DESTROYITEM_NUM);
DECLARE_IDCREATE(MapDestroyitemDesc);
};
