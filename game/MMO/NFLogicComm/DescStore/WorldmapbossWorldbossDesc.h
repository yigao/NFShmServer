#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/worldmapboss_s.h"

#define MAX_WORLDMAPBOSS_WORLDBOSS_NUM 20

class WorldmapbossWorldbossDesc : public NFIDescStore
{
public:
	WorldmapbossWorldbossDesc(NFIPluginManager* pPluginManager);
	virtual ~WorldmapbossWorldbossDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::worldmapbossworldboss_s* GetDesc(int id) const;
	proto_ff_s::worldmapbossworldboss_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::worldmapbossworldboss_s, MAX_WORLDMAPBOSS_WORLDBOSS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::worldmapbossworldboss_s, MAX_WORLDMAPBOSS_WORLDBOSS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::worldmapbossworldboss_s, worldmapbossworldboss, MAX_WORLDMAPBOSS_WORLDBOSS_NUM);
DECLARE_IDCREATE(WorldmapbossWorldbossDesc);
};
