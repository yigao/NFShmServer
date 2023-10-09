#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_BUYCHALLENGE_NUM 8

class ArenaBuychallengeDesc : public NFIDescStore
{
public:
	ArenaBuychallengeDesc();
	virtual ~ArenaBuychallengeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ArenaBuychallenge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaBuychallenge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaBuychallenge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaBuychallenge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ArenaBuychallengeDesc, proto_ff_s::E_ArenaBuychallenge_s, E_ArenaBuychallenge, MAX_ARENA_BUYCHALLENGE_NUM);
DECLARE_IDCREATE(ArenaBuychallengeDesc);
};
