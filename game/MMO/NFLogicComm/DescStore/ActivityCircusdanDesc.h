#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_CIRCUSDAN_NUM 60

class ActivityCircusdanDesc : public NFIDescStore
{
public:
	ActivityCircusdanDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityCircusdanDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitycircusDan_s* GetDesc(int id) const;
	proto_ff_s::activitycircusDan_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitycircusDan_s, MAX_ACTIVITY_CIRCUSDAN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitycircusDan_s, MAX_ACTIVITY_CIRCUSDAN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitycircusDan_s, activitycircusDan, MAX_ACTIVITY_CIRCUSDAN_NUM);
DECLARE_IDCREATE(ActivityCircusdanDesc);
};
