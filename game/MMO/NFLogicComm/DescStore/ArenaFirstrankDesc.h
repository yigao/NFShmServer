#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_ArenaFirstrank_s* GetDesc(int id) const;
	proto_ff_s::E_ArenaFirstrank_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ArenaFirstrank_s, E_ArenaFirstrank, MAX_ARENA_FIRSTRANK_NUM);
DECLARE_IDCREATE(ArenaFirstrankDesc);
};
