#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_SPORTS_NUM 20

class DailySportsDesc : public NFIDescStore
{
public:
	DailySportsDesc();
	virtual ~DailySportsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DailySports_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailySports_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailySports_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailySports_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DailySportsDesc, proto_ff_s::E_DailySports_s, E_DailySports, MAX_DAILY_SPORTS_NUM);
DECLARE_IDCREATE(DailySportsDesc);
};
