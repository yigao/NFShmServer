#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ranking_s.h"

#define MAX_RANKING_DATE_NUM 100

class RankingDateDesc : public NFIDescStore
{
public:
	RankingDateDesc(NFIPluginManager* pPluginManager);
	virtual ~RankingDateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rankingdate_s* GetDesc(int id) const;
	proto_ff_s::rankingdate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rankingdate_s, MAX_RANKING_DATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rankingdate_s, MAX_RANKING_DATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rankingdate_s, rankingdate, MAX_RANKING_DATE_NUM);
DECLARE_IDCREATE(RankingDateDesc);
};
