#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_DROP_NUM 20

class MonsterDropDesc : public NFIDescStore
{
public:
	MonsterDropDesc();
	virtual ~MonsterDropDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MonsterDrop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterDrop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterDrop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterDrop_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MonsterDropDesc, proto_ff_s::E_MonsterDrop_s, E_MonsterDrop, MAX_MONSTER_DROP_NUM);
DECLARE_IDCREATE(MonsterDropDesc);
};
