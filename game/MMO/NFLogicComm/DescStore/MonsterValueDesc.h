#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_VALUE_NUM 2000

class MonsterValueDesc : public NFIDescStore
{
public:
	MonsterValueDesc();
	virtual ~MonsterValueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MonsterValue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterValue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterValue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterValue_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MonsterValueDesc, proto_ff_s::E_MonsterValue_s, E_MonsterValue, MAX_MONSTER_VALUE_NUM);
DECLARE_IDCREATE(MonsterValueDesc);
};
