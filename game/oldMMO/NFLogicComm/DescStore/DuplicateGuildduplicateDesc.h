#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_GUILDDUPLICATE_NUM 2000

class DuplicateGuildduplicateDesc : public NFIDescStore
{
public:
	DuplicateGuildduplicateDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateGuildduplicateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::duplicateGuildDuplicate_s* GetDesc(int id) const;
	proto_ff_s::duplicateGuildDuplicate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildDuplicate_s, MAX_DUPLICATE_GUILDDUPLICATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildDuplicate_s, MAX_DUPLICATE_GUILDDUPLICATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateGuildDuplicate_s, duplicateGuildDuplicate, MAX_DUPLICATE_GUILDDUPLICATE_NUM);
DECLARE_IDCREATE(DuplicateGuildduplicateDesc);
};
