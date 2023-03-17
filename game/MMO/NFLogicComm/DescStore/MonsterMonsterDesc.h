#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_MONSTER_NUM 400

class MonsterMonsterDesc : public NFIDescStore
{
public:
	MonsterMonsterDesc();
	virtual ~MonsterMonsterDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MonsterMonster_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterMonster_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterMonster_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterMonster_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MonsterMonsterDesc, proto_ff_s::E_MonsterMonster_s, E_MonsterMonster, MAX_MONSTER_MONSTER_NUM);
DECLARE_IDCREATE(MonsterMonsterDesc);
};
