#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_WORLDTREASUREMONSTER_NUM 20

class ActivityWorldtreasuremonsterDesc : public NFIDescStore
{
public:
	ActivityWorldtreasuremonsterDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityWorldtreasuremonsterDesc();
	const proto_ff_s::activityworldTreasureMonster_s* GetDesc(int id) const;
	proto_ff_s::activityworldTreasureMonster_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureMonster_s, MAX_ACTIVITY_WORLDTREASUREMONSTER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureMonster_s, MAX_ACTIVITY_WORLDTREASUREMONSTER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activityworldTreasureMonster_s, activityworldTreasureMonster, MAX_ACTIVITY_WORLDTREASUREMONSTER_NUM);
DECLARE_IDCREATE(ActivityWorldtreasuremonsterDesc);
};
