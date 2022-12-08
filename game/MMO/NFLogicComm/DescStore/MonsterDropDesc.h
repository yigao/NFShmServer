#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::monsterdrop_s* GetDesc(int id) const;
	proto_ff_s::monsterdrop_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::monsterdrop_s, monsterdrop, MAX_MONSTER_DROP_NUM);
DECLARE_IDCREATE(MonsterDropDesc);
};
