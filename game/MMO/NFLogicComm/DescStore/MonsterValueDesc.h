#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_VALUE_NUM 4096

class MonsterValueDesc : public NFIDescStore
{
public:
	MonsterValueDesc();
	virtual ~MonsterValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MonsterValue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterValue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterValue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterValue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MonsterValueDesc, proto_ff_s::E_MonsterValue_s, E_MonsterValue, MAX_MONSTER_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(MonsterValueDesc);
};
