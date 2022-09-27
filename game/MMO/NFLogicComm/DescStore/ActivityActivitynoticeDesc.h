#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_ACTIVITYNOTICE_NUM 20

class ActivityActivitynoticeDesc : public NFIDescStore
{
public:
	ActivityActivitynoticeDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityActivitynoticeDesc();
	const proto_ff_s::activityactivitynotice_s* GetDesc(int id) const;
	proto_ff_s::activityactivitynotice_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activityactivitynotice_s, MAX_ACTIVITY_ACTIVITYNOTICE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activityactivitynotice_s, MAX_ACTIVITY_ACTIVITYNOTICE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activityactivitynotice_s, activityactivitynotice, MAX_ACTIVITY_ACTIVITYNOTICE_NUM);
DECLARE_IDCREATE(ActivityActivitynoticeDesc);
};
