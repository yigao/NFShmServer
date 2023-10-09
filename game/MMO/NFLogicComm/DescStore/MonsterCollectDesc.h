#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_COLLECT_NUM 32

class MonsterCollectDesc : public NFIDescStore
{
public:
	MonsterCollectDesc();
	virtual ~MonsterCollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MonsterCollect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterCollect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterCollect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterCollect_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MonsterCollectDesc, proto_ff_s::E_MonsterCollect_s, E_MonsterCollect, MAX_MONSTER_COLLECT_NUM);
DECLARE_IDCREATE(MonsterCollectDesc);
};
