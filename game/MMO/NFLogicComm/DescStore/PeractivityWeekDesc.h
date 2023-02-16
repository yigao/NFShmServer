#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_PeractivityWeek_s* GetDesc(int id) const;
	proto_ff_s::E_PeractivityWeek_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PeractivityWeek_s, perActivityweek, MAX_PERACTIVITY_WEEK_NUM);
DECLARE_IDCREATE(PeractivityWeekDesc);
};
