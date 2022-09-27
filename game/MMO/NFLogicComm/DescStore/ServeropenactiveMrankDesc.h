#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_MRANK_NUM 200

class ServeropenactiveMrankDesc : public NFIDescStore
{
public:
	ServeropenactiveMrankDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactiveMrankDesc();
	const proto_ff_s::serveropenactivemRank_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivemRank_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemRank_s, MAX_SERVEROPENACTIVE_MRANK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemRank_s, MAX_SERVEROPENACTIVE_MRANK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivemRank_s, serveropenactivemRank, MAX_SERVEROPENACTIVE_MRANK_NUM);
DECLARE_IDCREATE(ServeropenactiveMrankDesc);
};
