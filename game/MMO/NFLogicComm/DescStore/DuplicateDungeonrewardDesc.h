#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_DUNGEONREWARD_NUM 300

class DuplicateDungeonrewardDesc : public NFIDescStore
{
public:
	DuplicateDungeonrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateDungeonrewardDesc();
	const proto_ff_s::duplicatedungeonReward_s* GetDesc(int id) const;
	proto_ff_s::duplicatedungeonReward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicatedungeonReward_s, MAX_DUPLICATE_DUNGEONREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicatedungeonReward_s, MAX_DUPLICATE_DUNGEONREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicatedungeonReward_s, duplicatedungeonReward, MAX_DUPLICATE_DUNGEONREWARD_NUM);
DECLARE_IDCREATE(DuplicateDungeonrewardDesc);
};
