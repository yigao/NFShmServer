#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_ARENAWARD_NUM 2048

class ArenaArenawardDesc : public NFIDescStore
{
public:
	ArenaArenawardDesc();
	virtual ~ArenaArenawardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ArenaArenaward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaArenaward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaArenaward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaArenaward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ArenaArenawardDesc, proto_ff_s::E_ArenaArenaward_s, E_ArenaArenaward, MAX_ARENA_ARENAWARD_NUM);
DECLARE_IDCREATE_GLOBAL(ArenaArenawardDesc);
};
