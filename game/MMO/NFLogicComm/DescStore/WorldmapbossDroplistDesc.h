#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/worldmapboss_s.h"

#define MAX_WORLDMAPBOSS_DROPLIST_NUM 4000

class WorldmapbossDroplistDesc : public NFIDescStore
{
public:
	WorldmapbossDroplistDesc(NFIPluginManager* pPluginManager);
	virtual ~WorldmapbossDroplistDesc();
	const proto_ff_s::worldmapbossdroplist_s* GetDesc(int id) const;
	proto_ff_s::worldmapbossdroplist_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::worldmapbossdroplist_s, MAX_WORLDMAPBOSS_DROPLIST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::worldmapbossdroplist_s, MAX_WORLDMAPBOSS_DROPLIST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::worldmapbossdroplist_s, worldmapbossdroplist, MAX_WORLDMAPBOSS_DROPLIST_NUM);
DECLARE_IDCREATE(WorldmapbossDroplistDesc);
};
