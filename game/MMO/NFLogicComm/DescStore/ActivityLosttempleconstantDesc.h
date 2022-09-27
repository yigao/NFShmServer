#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_LOSTTEMPLECONSTANT_NUM 20

class ActivityLosttempleconstantDesc : public NFIDescStore
{
public:
	ActivityLosttempleconstantDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityLosttempleconstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitylosttempleConstant_s* GetDesc(int id) const;
	proto_ff_s::activitylosttempleConstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitylosttempleConstant_s, MAX_ACTIVITY_LOSTTEMPLECONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitylosttempleConstant_s, MAX_ACTIVITY_LOSTTEMPLECONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitylosttempleConstant_s, activitylosttempleConstant, MAX_ACTIVITY_LOSTTEMPLECONSTANT_NUM);
DECLARE_IDCREATE(ActivityLosttempleconstantDesc);
};
