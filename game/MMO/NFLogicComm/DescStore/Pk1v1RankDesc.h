#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_RANK_NUM 64

class Pk1v1RankDesc : public NFIDescStore
{
public:
	Pk1v1RankDesc();
	virtual ~Pk1v1RankDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk1v1Rank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk1v1Rank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk1v1Rank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk1v1Rank_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk1v1RankDesc, proto_ff_s::E_Pk1v1Rank_s, E_Pk1v1Rank, MAX_PK1V1_RANK_NUM);
DECLARE_IDCREATE_GLOBAL(Pk1v1RankDesc);
};
