#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_COST_NUM 8

class JinglianCostDesc : public NFIDescStore
{
public:
	JinglianCostDesc();
	virtual ~JinglianCostDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_JinglianCost_s* GetDesc(int64_t id) const;
	proto_ff_s::E_JinglianCost_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_JinglianCost_s* GetDescByIndex(int index) const;
	proto_ff_s::E_JinglianCost_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(JinglianCostDesc, proto_ff_s::E_JinglianCost_s, E_JinglianCost, MAX_JINGLIAN_COST_NUM);
DECLARE_IDCREATE(JinglianCostDesc);
};
