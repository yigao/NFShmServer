#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_WORLDTREASUREMAP_NUM 20

class ActivityWorldtreasuremapDesc : public NFIDescStore
{
public:
	ActivityWorldtreasuremapDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityWorldtreasuremapDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activityworldTreasureMap_s* GetDesc(int id) const;
	proto_ff_s::activityworldTreasureMap_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureMap_s, MAX_ACTIVITY_WORLDTREASUREMAP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureMap_s, MAX_ACTIVITY_WORLDTREASUREMAP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activityworldTreasureMap_s, activityworldTreasureMap, MAX_ACTIVITY_WORLDTREASUREMAP_NUM);
DECLARE_IDCREATE(ActivityWorldtreasuremapDesc);
};
