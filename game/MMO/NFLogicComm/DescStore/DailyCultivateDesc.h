#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_CULTIVATE_NUM 80

class DailyCultivateDesc : public NFIDescStore
{
public:
	DailyCultivateDesc();
	virtual ~DailyCultivateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DailyCultivate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailyCultivate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailyCultivate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailyCultivate_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DailyCultivateDesc, proto_ff_s::E_DailyCultivate_s, E_DailyCultivate, MAX_DAILY_CULTIVATE_NUM);
DECLARE_IDCREATE(DailyCultivateDesc);
};
