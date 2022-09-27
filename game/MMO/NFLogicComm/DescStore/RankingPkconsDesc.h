#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ranking_s.h"

#define MAX_RANKING_PKCONS_NUM 20

class RankingPkconsDesc : public NFIDescStore
{
public:
	RankingPkconsDesc(NFIPluginManager* pPluginManager);
	virtual ~RankingPkconsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rankingpkcons_s* GetDesc(int id) const;
	proto_ff_s::rankingpkcons_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rankingpkcons_s, MAX_RANKING_PKCONS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rankingpkcons_s, MAX_RANKING_PKCONS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rankingpkcons_s, rankingpkcons, MAX_RANKING_PKCONS_NUM);
DECLARE_IDCREATE(RankingPkconsDesc);
};
