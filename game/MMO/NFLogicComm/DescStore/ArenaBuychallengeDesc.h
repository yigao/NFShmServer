#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_BUYCHALLENGE_NUM 20

class ArenaBuychallengeDesc : public NFIDescStore
{
public:
	ArenaBuychallengeDesc();
	virtual ~ArenaBuychallengeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ArenaBuychallenge_s* GetDesc(int id) const;
	proto_ff_s::E_ArenaBuychallenge_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ArenaBuychallenge_s, arenabuychallenge, MAX_ARENA_BUYCHALLENGE_NUM);
DECLARE_IDCREATE(ArenaBuychallengeDesc);
};
