#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/star_s.h"

#define MAX_STAR_POINT_NUM 20

class StarPointDesc : public NFIDescStore
{
public:
	StarPointDesc(NFIPluginManager* pPluginManager);
	virtual ~StarPointDesc();
	const proto_ff_s::starpoint_s* GetDesc(int id) const;
	proto_ff_s::starpoint_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::starpoint_s, MAX_STAR_POINT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::starpoint_s, MAX_STAR_POINT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::starpoint_s, starpoint, MAX_STAR_POINT_NUM);
DECLARE_IDCREATE(StarPointDesc);
};
