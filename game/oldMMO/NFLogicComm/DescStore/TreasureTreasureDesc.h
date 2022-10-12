#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_TREASURE_NUM 500

class TreasureTreasureDesc : public NFIDescStore
{
public:
	TreasureTreasureDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureTreasureDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::treasuretreasure_s* GetDesc(int id) const;
	proto_ff_s::treasuretreasure_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasuretreasure_s, MAX_TREASURE_TREASURE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasuretreasure_s, MAX_TREASURE_TREASURE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasuretreasure_s, treasuretreasure, MAX_TREASURE_TREASURE_NUM);
DECLARE_IDCREATE(TreasureTreasureDesc);
};
