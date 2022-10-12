#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_WORLDTREASURECONST_NUM 20

class ActivityWorldtreasureconstDesc : public NFIDescStore
{
public:
	ActivityWorldtreasureconstDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityWorldtreasureconstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activityworldTreasureConst_s* GetDesc(int id) const;
	proto_ff_s::activityworldTreasureConst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureConst_s, MAX_ACTIVITY_WORLDTREASURECONST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activityworldTreasureConst_s, MAX_ACTIVITY_WORLDTREASURECONST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activityworldTreasureConst_s, activityworldTreasureConst, MAX_ACTIVITY_WORLDTREASURECONST_NUM);
DECLARE_IDCREATE(ActivityWorldtreasureconstDesc);
};
