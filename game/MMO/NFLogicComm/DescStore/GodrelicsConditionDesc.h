#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godRelics_s.h"

#define MAX_GODRELICS_CONDITION_NUM 20

class GodrelicsConditionDesc : public NFIDescStore
{
public:
	GodrelicsConditionDesc();
	virtual ~GodrelicsConditionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodrelicsCondition_s* GetDesc(int id) const;
	proto_ff_s::E_GodrelicsCondition_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GodrelicsCondition_s, E_GodrelicsCondition, MAX_GODRELICS_CONDITION_NUM);
DECLARE_IDCREATE(GodrelicsConditionDesc);
};
