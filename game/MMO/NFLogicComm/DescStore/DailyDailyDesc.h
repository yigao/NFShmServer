#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_DAILY_NUM 20

class DailyDailyDesc : public NFIDescStore
{
public:
	DailyDailyDesc();
	virtual ~DailyDailyDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::dailydaily_s* GetDesc(int id) const;
	proto_ff_s::dailydaily_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::dailydaily_s, dailydaily, MAX_DAILY_DAILY_NUM);
DECLARE_IDCREATE(DailyDailyDesc);
};
