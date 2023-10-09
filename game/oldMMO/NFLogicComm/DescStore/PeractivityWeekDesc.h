#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/perActivity_s.h"

#define MAX_PERACTIVITY_WEEK_NUM 20

class PeractivityWeekDesc : public NFIDescStore
{
public:
	PeractivityWeekDesc();
	virtual ~PeractivityWeekDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PeractivityWeek_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PeractivityWeek_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PeractivityWeek_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PeractivityWeek_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PeractivityWeekDesc, proto_ff_s::E_PeractivityWeek_s, E_PeractivityWeek, MAX_PERACTIVITY_WEEK_NUM);
DECLARE_IDCREATE(PeractivityWeekDesc);
};
