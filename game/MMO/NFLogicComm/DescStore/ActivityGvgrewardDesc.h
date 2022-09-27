#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_GVGREWARD_NUM 180

class ActivityGvgrewardDesc : public NFIDescStore
{
public:
	ActivityGvgrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityGvgrewardDesc();
	const proto_ff_s::activitygvgReward_s* GetDesc(int id) const;
	proto_ff_s::activitygvgReward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitygvgReward_s, MAX_ACTIVITY_GVGREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitygvgReward_s, MAX_ACTIVITY_GVGREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitygvgReward_s, activitygvgReward, MAX_ACTIVITY_GVGREWARD_NUM);
DECLARE_IDCREATE(ActivityGvgrewardDesc);
};
