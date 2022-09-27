#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mall_s.h"

#define MAX_MALL_MALLTYPE_NUM 20

class MallMalltypeDesc : public NFIDescStore
{
public:
	MallMalltypeDesc(NFIPluginManager* pPluginManager);
	virtual ~MallMalltypeDesc();
	const proto_ff_s::mallmalltype_s* GetDesc(int id) const;
	proto_ff_s::mallmalltype_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mallmalltype_s, MAX_MALL_MALLTYPE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mallmalltype_s, MAX_MALL_MALLTYPE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mallmalltype_s, mallmalltype, MAX_MALL_MALLTYPE_NUM);
DECLARE_IDCREATE(MallMalltypeDesc);
};
