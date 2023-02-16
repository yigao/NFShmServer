#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_ARENAWARD_NUM 2000

class ArenaArenawardDesc : public NFIDescStore
{
public:
	ArenaArenawardDesc();
	virtual ~ArenaArenawardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ArenaArenaward_s* GetDesc(int id) const;
	proto_ff_s::E_ArenaArenaward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ArenaArenaward_s, arenaarenAward, MAX_ARENA_ARENAWARD_NUM);
DECLARE_IDCREATE(ArenaArenawardDesc);
};
