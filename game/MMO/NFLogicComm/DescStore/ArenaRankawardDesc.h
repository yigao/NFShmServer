#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_RANKAWARD_NUM 20

class ArenaRankawardDesc : public NFIDescStore
{
public:
	ArenaRankawardDesc(NFIPluginManager* pPluginManager);
	virtual ~ArenaRankawardDesc();
	const proto_ff_s::arenarankaward_s* GetDesc(int id) const;
	proto_ff_s::arenarankaward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::arenarankaward_s, MAX_ARENA_RANKAWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::arenarankaward_s, MAX_ARENA_RANKAWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::arenarankaward_s, arenarankaward, MAX_ARENA_RANKAWARD_NUM);
DECLARE_IDCREATE(ArenaRankawardDesc);
};
