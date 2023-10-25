#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godrelics_s.h"

#define MAX_GODRELICS_CONDITION_NUM 128

class GodrelicsConditionDesc : public NFIDescStore
{
public:
	GodrelicsConditionDesc();
	virtual ~GodrelicsConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodrelicsCondition_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodrelicsCondition_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodrelicsCondition_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodrelicsCondition_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodrelicsConditionDesc, proto_ff_s::E_GodrelicsCondition_s, E_GodrelicsCondition, MAX_GODRELICS_CONDITION_NUM);
DECLARE_IDCREATE_GLOBAL(GodrelicsConditionDesc);
};
