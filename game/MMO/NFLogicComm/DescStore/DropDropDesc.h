#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/drop_s.h"

#define MAX_DROP_DROP_NUM 2000

class DropDropDesc : public NFIDescStore
{
public:
	DropDropDesc(NFIPluginManager* pPluginManager);
	virtual ~DropDropDesc();
	const proto_ff_s::dropdrop_s* GetDesc(int id) const;
	proto_ff_s::dropdrop_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::dropdrop_s, MAX_DROP_DROP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::dropdrop_s, MAX_DROP_DROP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::dropdrop_s, dropdrop, MAX_DROP_DROP_NUM);
DECLARE_IDCREATE(DropDropDesc);
};
