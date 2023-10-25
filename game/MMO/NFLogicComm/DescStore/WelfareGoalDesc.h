#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_GOAL_NUM 2

class WelfareGoalDesc : public NFIDescStore
{
public:
	WelfareGoalDesc();
	virtual ~WelfareGoalDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareGoal_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareGoal_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareGoal_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareGoal_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareGoalDesc, proto_ff_s::E_WelfareGoal_s, E_WelfareGoal, MAX_WELFARE_GOAL_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareGoalDesc);
};
