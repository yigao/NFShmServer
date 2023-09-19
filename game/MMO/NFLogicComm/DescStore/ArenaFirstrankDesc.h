#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_FIRSTRANK_NUM 20

class ArenaFirstrankDesc : public NFIDescStore
{
public:
	ArenaFirstrankDesc();
	virtual ~ArenaFirstrankDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ArenaFirstrank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaFirstrank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaFirstrank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaFirstrank_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ArenaFirstrankDesc, proto_ff_s::E_ArenaFirstrank_s, E_ArenaFirstrank, MAX_ARENA_FIRSTRANK_NUM);
DECLARE_IDCREATE(ArenaFirstrankDesc);
};
