#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/solo_s.h"

#define MAX_SOLO_RANK_NUM 20

class SoloRankDesc : public NFIDescStore
{
public:
	SoloRankDesc(NFIPluginManager* pPluginManager);
	virtual ~SoloRankDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::solorank_s* GetDesc(int id) const;
	proto_ff_s::solorank_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::solorank_s, MAX_SOLO_RANK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::solorank_s, MAX_SOLO_RANK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::solorank_s, solorank, MAX_SOLO_RANK_NUM);
DECLARE_IDCREATE(SoloRankDesc);
};
