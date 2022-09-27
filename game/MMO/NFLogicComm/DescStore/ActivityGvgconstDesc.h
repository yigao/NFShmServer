#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_GVGCONST_NUM 160

class ActivityGvgconstDesc : public NFIDescStore
{
public:
	ActivityGvgconstDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityGvgconstDesc();
	const proto_ff_s::activitygvgConst_s* GetDesc(int id) const;
	proto_ff_s::activitygvgConst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitygvgConst_s, MAX_ACTIVITY_GVGCONST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitygvgConst_s, MAX_ACTIVITY_GVGCONST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitygvgConst_s, activitygvgConst, MAX_ACTIVITY_GVGCONST_NUM);
DECLARE_IDCREATE(ActivityGvgconstDesc);
};
