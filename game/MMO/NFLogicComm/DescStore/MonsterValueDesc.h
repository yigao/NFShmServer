#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_VALUE_NUM 200

class MonsterValueDesc : public NFIDescStore
{
public:
	MonsterValueDesc();
	virtual ~MonsterValueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::monstervalue_s* GetDesc(int id) const;
	proto_ff_s::monstervalue_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::monstervalue_s, monstervalue, MAX_MONSTER_VALUE_NUM);
DECLARE_IDCREATE(MonsterValueDesc);
};
