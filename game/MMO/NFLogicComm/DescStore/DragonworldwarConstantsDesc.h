#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dragonWorldWar_s.h"

#define MAX_DRAGONWORLDWAR_CONSTANTS_NUM 20

class DragonworldwarConstantsDesc : public NFIDescStore
{
public:
	DragonworldwarConstantsDesc(NFIPluginManager* pPluginManager);
	virtual ~DragonworldwarConstantsDesc();
	const proto_ff_s::dragonWorldWarconstants_s* GetDesc(int id) const;
	proto_ff_s::dragonWorldWarconstants_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWarconstants_s, MAX_DRAGONWORLDWAR_CONSTANTS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWarconstants_s, MAX_DRAGONWORLDWAR_CONSTANTS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::dragonWorldWarconstants_s, dragonWorldWarconstants, MAX_DRAGONWORLDWAR_CONSTANTS_NUM);
DECLARE_IDCREATE(DragonworldwarConstantsDesc);
};
