#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_CIRCUS_NUM 40

class ActivityCircusDesc : public NFIDescStore
{
public:
	ActivityCircusDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityCircusDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitycircus_s* GetDesc(int id) const;
	proto_ff_s::activitycircus_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitycircus_s, MAX_ACTIVITY_CIRCUS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitycircus_s, MAX_ACTIVITY_CIRCUS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitycircus_s, activitycircus, MAX_ACTIVITY_CIRCUS_NUM);
DECLARE_IDCREATE(ActivityCircusDesc);
};
