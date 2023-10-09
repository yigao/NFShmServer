#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_SPORTS_NUM 16

class DailySportsDesc : public NFIDescStore
{
public:
	DailySportsDesc();
	virtual ~DailySportsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DailySports_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailySports_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailySports_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailySports_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DailySportsDesc, proto_ff_s::E_DailySports_s, E_DailySports, MAX_DAILY_SPORTS_NUM);
DECLARE_IDCREATE(DailySportsDesc);
};
