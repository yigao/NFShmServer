#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_DUPLICATE_NUM 900

class DuplicateDuplicateDesc : public NFIDescStore
{
public:
	DuplicateDuplicateDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateDuplicateDesc();
	const proto_ff_s::duplicateduplicate_s* GetDesc(int id) const;
	proto_ff_s::duplicateduplicate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateduplicate_s, MAX_DUPLICATE_DUPLICATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateduplicate_s, MAX_DUPLICATE_DUPLICATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateduplicate_s, duplicateduplicate, MAX_DUPLICATE_DUPLICATE_NUM);
DECLARE_IDCREATE(DuplicateDuplicateDesc);
};
