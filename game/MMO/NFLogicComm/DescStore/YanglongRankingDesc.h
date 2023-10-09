#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Yanglong_s.h"

#define MAX_YANGLONG_RANKING_NUM 8

class YanglongRankingDesc : public NFIDescStore
{
public:
	YanglongRankingDesc();
	virtual ~YanglongRankingDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_YanglongRanking_s* GetDesc(int64_t id) const;
	proto_ff_s::E_YanglongRanking_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_YanglongRanking_s* GetDescByIndex(int index) const;
	proto_ff_s::E_YanglongRanking_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(YanglongRankingDesc, proto_ff_s::E_YanglongRanking_s, E_YanglongRanking, MAX_YANGLONG_RANKING_NUM);
DECLARE_IDCREATE(YanglongRankingDesc);
};
