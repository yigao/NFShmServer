#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_GUILDBOSSTIME_NUM 300

class DuplicateGuildbosstimeDesc : public NFIDescStore
{
public:
	DuplicateGuildbosstimeDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateGuildbosstimeDesc();
	const proto_ff_s::duplicateGuildbosstime_s* GetDesc(int id) const;
	proto_ff_s::duplicateGuildbosstime_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildbosstime_s, MAX_DUPLICATE_GUILDBOSSTIME_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildbosstime_s, MAX_DUPLICATE_GUILDBOSSTIME_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateGuildbosstime_s, duplicateGuildbosstime, MAX_DUPLICATE_GUILDBOSSTIME_NUM);
DECLARE_IDCREATE(DuplicateGuildbosstimeDesc);
};
