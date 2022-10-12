#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/star_s.h"

#define MAX_STAR_STAR_NUM 200

class StarStarDesc : public NFIDescStore
{
public:
	StarStarDesc(NFIPluginManager* pPluginManager);
	virtual ~StarStarDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::starstar_s* GetDesc(int id) const;
	proto_ff_s::starstar_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::starstar_s, MAX_STAR_STAR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::starstar_s, MAX_STAR_STAR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::starstar_s, starstar, MAX_STAR_STAR_NUM);
DECLARE_IDCREATE(StarStarDesc);
};
