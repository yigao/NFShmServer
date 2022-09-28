#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/worldmapboss_s.h"

#define MAX_WORLDMAPBOSS_FESTIVAL_NUM 20

class WorldmapbossFestivalDesc : public NFIDescStore
{
public:
	WorldmapbossFestivalDesc(NFIPluginManager* pPluginManager);
	virtual ~WorldmapbossFestivalDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::worldmapbossfestival_s* GetDesc(int id) const;
	proto_ff_s::worldmapbossfestival_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::worldmapbossfestival_s, MAX_WORLDMAPBOSS_FESTIVAL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::worldmapbossfestival_s, MAX_WORLDMAPBOSS_FESTIVAL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::worldmapbossfestival_s, worldmapbossfestival, MAX_WORLDMAPBOSS_FESTIVAL_NUM);
DECLARE_IDCREATE(WorldmapbossFestivalDesc);
};
