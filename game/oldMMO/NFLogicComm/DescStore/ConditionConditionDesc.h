#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/condition_s.h"

#define MAX_CONDITION_CONDITION_NUM 40

class ConditionConditionDesc : public NFIDescStore
{
public:
	ConditionConditionDesc();
	virtual ~ConditionConditionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ConditionCondition_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConditionCondition_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConditionCondition_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConditionCondition_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ConditionConditionDesc, proto_ff_s::E_ConditionCondition_s, E_ConditionCondition, MAX_CONDITION_CONDITION_NUM);
DECLARE_IDCREATE(ConditionConditionDesc);
};
