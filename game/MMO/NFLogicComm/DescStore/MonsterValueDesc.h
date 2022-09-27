#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_VALUE_NUM 43000

class MonsterValueDesc : public NFIDescStore
{
public:
	MonsterValueDesc(NFIPluginManager* pPluginManager);
	virtual ~MonsterValueDesc();
	const proto_ff_s::monstervalue_s* GetDesc(int id) const;
	proto_ff_s::monstervalue_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::monstervalue_s, MAX_MONSTER_VALUE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::monstervalue_s, MAX_MONSTER_VALUE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::monstervalue_s, monstervalue, MAX_MONSTER_VALUE_NUM);
DECLARE_IDCREATE(MonsterValueDesc);
};
