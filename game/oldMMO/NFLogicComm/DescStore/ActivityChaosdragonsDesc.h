#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_CHAOSDRAGONS_NUM 20

class ActivityChaosdragonsDesc : public NFIDescStore
{
public:
	ActivityChaosdragonsDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityChaosdragonsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitychaosDragons_s* GetDesc(int id) const;
	proto_ff_s::activitychaosDragons_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitychaosDragons_s, MAX_ACTIVITY_CHAOSDRAGONS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitychaosDragons_s, MAX_ACTIVITY_CHAOSDRAGONS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitychaosDragons_s, activitychaosDragons, MAX_ACTIVITY_CHAOSDRAGONS_NUM);
DECLARE_IDCREATE(ActivityChaosdragonsDesc);
};
