#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_DISPLAY_NUM 256

class MonsterDisplayDesc : public NFIDescStore
{
public:
	MonsterDisplayDesc();
	virtual ~MonsterDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MonsterDisplay_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterDisplay_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterDisplay_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterDisplay_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MonsterDisplayDesc, proto_ff_s::E_MonsterDisplay_s, E_MonsterDisplay, MAX_MONSTER_DISPLAY_NUM);
DECLARE_IDCREATE_GLOBAL(MonsterDisplayDesc);
};
