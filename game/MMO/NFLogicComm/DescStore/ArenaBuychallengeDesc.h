#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_BUYCHALLENGE_NUM 20

class ArenaBuychallengeDesc : public NFIDescStore
{
public:
	ArenaBuychallengeDesc(NFIPluginManager* pPluginManager);
	virtual ~ArenaBuychallengeDesc();
	const proto_ff_s::arenabuychallenge_s* GetDesc(int id) const;
	proto_ff_s::arenabuychallenge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::arenabuychallenge_s, MAX_ARENA_BUYCHALLENGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::arenabuychallenge_s, MAX_ARENA_BUYCHALLENGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::arenabuychallenge_s, arenabuychallenge, MAX_ARENA_BUYCHALLENGE_NUM);
DECLARE_IDCREATE(ArenaBuychallengeDesc);
};
