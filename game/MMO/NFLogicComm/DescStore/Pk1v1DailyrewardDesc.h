#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_DAILYREWARD_NUM 8

class Pk1v1DailyrewardDesc : public NFIDescStore
{
public:
	Pk1v1DailyrewardDesc();
	virtual ~Pk1v1DailyrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk1v1Dailyreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk1v1Dailyreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk1v1Dailyreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk1v1Dailyreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk1v1DailyrewardDesc, proto_ff_s::E_Pk1v1Dailyreward_s, E_Pk1v1Dailyreward, MAX_PK1V1_DAILYREWARD_NUM);
DECLARE_IDCREATE_GLOBAL(Pk1v1DailyrewardDesc);
};
