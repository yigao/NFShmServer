#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_RANKAWARD_NUM 20

class ArenaRankawardDesc : public NFIDescStore
{
public:
	ArenaRankawardDesc();
	virtual ~ArenaRankawardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ArenaRankaward_s* GetDesc(int id) const;
	proto_ff_s::E_ArenaRankaward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ArenaRankaward_s, arenarankaward, MAX_ARENA_RANKAWARD_NUM);
DECLARE_IDCREATE(ArenaRankawardDesc);
};
