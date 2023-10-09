#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_MONSTER_NUM 2048

class MonsterMonsterDesc : public NFIDescStore
{
public:
	MonsterMonsterDesc();
	virtual ~MonsterMonsterDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MonsterMonster_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterMonster_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterMonster_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterMonster_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MonsterMonsterDesc, proto_ff_s::E_MonsterMonster_s, E_MonsterMonster, MAX_MONSTER_MONSTER_NUM);
DECLARE_IDCREATE(MonsterMonsterDesc);
};
