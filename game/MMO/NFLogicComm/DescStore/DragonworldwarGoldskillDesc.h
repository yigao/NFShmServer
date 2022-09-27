#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dragonWorldWar_s.h"

#define MAX_DRAGONWORLDWAR_GOLDSKILL_NUM 20

class DragonworldwarGoldskillDesc : public NFIDescStore
{
public:
	DragonworldwarGoldskillDesc(NFIPluginManager* pPluginManager);
	virtual ~DragonworldwarGoldskillDesc();
	const proto_ff_s::dragonWorldWargoldskill_s* GetDesc(int id) const;
	proto_ff_s::dragonWorldWargoldskill_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWargoldskill_s, MAX_DRAGONWORLDWAR_GOLDSKILL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWargoldskill_s, MAX_DRAGONWORLDWAR_GOLDSKILL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::dragonWorldWargoldskill_s, dragonWorldWargoldskill, MAX_DRAGONWORLDWAR_GOLDSKILL_NUM);
DECLARE_IDCREATE(DragonworldwarGoldskillDesc);
};
