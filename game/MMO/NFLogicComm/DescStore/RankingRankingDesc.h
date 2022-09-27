#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ranking_s.h"

#define MAX_RANKING_RANKING_NUM 100

class RankingRankingDesc : public NFIDescStore
{
public:
	RankingRankingDesc(NFIPluginManager* pPluginManager);
	virtual ~RankingRankingDesc();
	const proto_ff_s::rankingranking_s* GetDesc(int id) const;
	proto_ff_s::rankingranking_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rankingranking_s, MAX_RANKING_RANKING_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rankingranking_s, MAX_RANKING_RANKING_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rankingranking_s, rankingranking, MAX_RANKING_RANKING_NUM);
DECLARE_IDCREATE(RankingRankingDesc);
};
