#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_RANKAWARD_NUM 8

class ArenaRankawardDesc : public NFIDescStore
{
public:
	ArenaRankawardDesc();
	virtual ~ArenaRankawardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ArenaRankaward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaRankaward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaRankaward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaRankaward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ArenaRankawardDesc, proto_ff_s::E_ArenaRankaward_s, E_ArenaRankaward, MAX_ARENA_RANKAWARD_NUM);
DECLARE_IDCREATE(ArenaRankawardDesc);
};
