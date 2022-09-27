#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godHood_s.h"

#define MAX_GODHOOD_GODHOOD_NUM 200

class GodhoodGodhoodDesc : public NFIDescStore
{
public:
	GodhoodGodhoodDesc(NFIPluginManager* pPluginManager);
	virtual ~GodhoodGodhoodDesc();
	const proto_ff_s::godHoodgodHood_s* GetDesc(int id) const;
	proto_ff_s::godHoodgodHood_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::godHoodgodHood_s, MAX_GODHOOD_GODHOOD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::godHoodgodHood_s, MAX_GODHOOD_GODHOOD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::godHoodgodHood_s, godHoodgodHood, MAX_GODHOOD_GODHOOD_NUM);
DECLARE_IDCREATE(GodhoodGodhoodDesc);
};
