#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Daily_s.h"

#define MAX_DAILY_CULTIVATE_NUM 1024

class DailyCultivateDesc : public NFIDescStore
{
public:
	DailyCultivateDesc();
	virtual ~DailyCultivateDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DailyCultivate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailyCultivate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailyCultivate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailyCultivate_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DailyCultivateDesc, proto_ff_s::E_DailyCultivate_s, E_DailyCultivate, MAX_DAILY_CULTIVATE_NUM);
DECLARE_IDCREATE_GLOBAL(DailyCultivateDesc);
};
