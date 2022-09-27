#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dragonWorldWar_s.h"

#define MAX_DRAGONWORLDWAR_GOLDSHOP_NUM 60

class DragonworldwarGoldshopDesc : public NFIDescStore
{
public:
	DragonworldwarGoldshopDesc(NFIPluginManager* pPluginManager);
	virtual ~DragonworldwarGoldshopDesc();
	const proto_ff_s::dragonWorldWargoldShop_s* GetDesc(int id) const;
	proto_ff_s::dragonWorldWargoldShop_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWargoldShop_s, MAX_DRAGONWORLDWAR_GOLDSHOP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::dragonWorldWargoldShop_s, MAX_DRAGONWORLDWAR_GOLDSHOP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::dragonWorldWargoldShop_s, dragonWorldWargoldShop, MAX_DRAGONWORLDWAR_GOLDSHOP_NUM);
DECLARE_IDCREATE(DragonworldwarGoldshopDesc);
};
