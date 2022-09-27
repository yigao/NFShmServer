#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_CIRCUSNUM_NUM 200

class ActivityCircusnumDesc : public NFIDescStore
{
public:
	ActivityCircusnumDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityCircusnumDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitycircusNum_s* GetDesc(int id) const;
	proto_ff_s::activitycircusNum_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitycircusNum_s, MAX_ACTIVITY_CIRCUSNUM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitycircusNum_s, MAX_ACTIVITY_CIRCUSNUM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitycircusNum_s, activitycircusNum, MAX_ACTIVITY_CIRCUSNUM_NUM);
DECLARE_IDCREATE(ActivityCircusnumDesc);
};
