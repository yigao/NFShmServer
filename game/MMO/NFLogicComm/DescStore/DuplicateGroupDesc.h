#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_GROUP_NUM 40

class DuplicateGroupDesc : public NFIDescStore
{
public:
	DuplicateGroupDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateGroupDesc();
	const proto_ff_s::duplicategroup_s* GetDesc(int id) const;
	proto_ff_s::duplicategroup_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicategroup_s, MAX_DUPLICATE_GROUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicategroup_s, MAX_DUPLICATE_GROUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicategroup_s, duplicategroup, MAX_DUPLICATE_GROUP_NUM);
DECLARE_IDCREATE(DuplicateGroupDesc);
};
