#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/activity_s.h"

#define MAX_ACTIVITY_DAILY_NUM 20

class ActivityDailyDesc : public NFIDescStore
{
public:
	ActivityDailyDesc(NFIPluginManager* pPluginManager);
	virtual ~ActivityDailyDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::activitydaily_s* GetDesc(int id) const;
	proto_ff_s::activitydaily_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::activitydaily_s, MAX_ACTIVITY_DAILY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::activitydaily_s, MAX_ACTIVITY_DAILY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::activitydaily_s, activitydaily, MAX_ACTIVITY_DAILY_NUM);
DECLARE_IDCREATE(ActivityDailyDesc);
};
