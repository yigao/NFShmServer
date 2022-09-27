#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_GVGRANKREWARD_NUM 20

class ActivityGvgrankrewardDesc : public NFIDescStore
{
public:
	ActivityGvgrankrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityGvgrankrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitygvgRankReward_s* GetDesc(int id) const;
	proto_ff_s::activitygvgRankReward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitygvgRankReward_s, MAX_ACTIVITY_GVGRANKREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitygvgRankReward_s, MAX_ACTIVITY_GVGRANKREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitygvgRankReward_s, activitygvgRankReward, MAX_ACTIVITY_GVGRANKREWARD_NUM);
DECLARE_IDCREATE(ActivityGvgrankrewardDesc);
};
