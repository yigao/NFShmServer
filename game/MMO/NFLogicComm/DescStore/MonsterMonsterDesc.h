#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_MONSTER_NUM 200

class MonsterMonsterDesc : public NFIDescStore
{
public:
	MonsterMonsterDesc();
	virtual ~MonsterMonsterDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MonsterMonster_s* GetDesc(int id) const;
	proto_ff_s::E_MonsterMonster_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MonsterMonster_s, E_MonsterMonster, MAX_MONSTER_MONSTER_NUM);
DECLARE_IDCREATE(MonsterMonsterDesc);
};
