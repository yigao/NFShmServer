#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_REFINE_NUM 200

class TreasureRefineDesc : public NFIDescStore
{
public:
	TreasureRefineDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureRefineDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::treasurerefine_s* GetDesc(int id) const;
	proto_ff_s::treasurerefine_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasurerefine_s, MAX_TREASURE_REFINE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasurerefine_s, MAX_TREASURE_REFINE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasurerefine_s, treasurerefine, MAX_TREASURE_REFINE_NUM);
DECLARE_IDCREATE(TreasureRefineDesc);
};
