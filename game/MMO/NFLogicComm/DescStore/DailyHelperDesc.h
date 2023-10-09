#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_HELPER_NUM 8

class DailyHelperDesc : public NFIDescStore
{
public:
	DailyHelperDesc();
	virtual ~DailyHelperDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DailyHelper_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailyHelper_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailyHelper_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailyHelper_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DailyHelperDesc, proto_ff_s::E_DailyHelper_s, E_DailyHelper, MAX_DAILY_HELPER_NUM);
DECLARE_IDCREATE(DailyHelperDesc);
};
