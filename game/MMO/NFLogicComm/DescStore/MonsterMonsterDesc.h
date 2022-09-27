#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_MONSTER_NUM 2000

class MonsterMonsterDesc : public NFIDescStore
{
public:
	MonsterMonsterDesc(NFIPluginManager* pPluginManager);
	virtual ~MonsterMonsterDesc();
	const proto_ff_s::monstermonster_s* GetDesc(int id) const;
	proto_ff_s::monstermonster_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::monstermonster_s, MAX_MONSTER_MONSTER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::monstermonster_s, MAX_MONSTER_MONSTER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::monstermonster_s, monstermonster, MAX_MONSTER_MONSTER_NUM);
DECLARE_IDCREATE(MonsterMonsterDesc);
};
