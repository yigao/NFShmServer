#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_SCUFFLE_NUM 20

class ActivityScuffleDesc : public NFIDescStore
{
public:
	ActivityScuffleDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityScuffleDesc();
	const proto_ff_s::activityscuffle_s* GetDesc(int id) const;
	proto_ff_s::activityscuffle_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activityscuffle_s, MAX_ACTIVITY_SCUFFLE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activityscuffle_s, MAX_ACTIVITY_SCUFFLE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activityscuffle_s, activityscuffle, MAX_ACTIVITY_SCUFFLE_NUM);
DECLARE_IDCREATE(ActivityScuffleDesc);
};
