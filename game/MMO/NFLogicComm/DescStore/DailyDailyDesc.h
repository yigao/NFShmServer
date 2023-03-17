#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_DAILY_NUM 60

class DailyDailyDesc : public NFIDescStore
{
public:
	DailyDailyDesc();
	virtual ~DailyDailyDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DailyDaily_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailyDaily_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailyDaily_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailyDaily_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DailyDailyDesc, proto_ff_s::E_DailyDaily_s, E_DailyDaily, MAX_DAILY_DAILY_NUM);
DECLARE_IDCREATE(DailyDailyDesc);
};
