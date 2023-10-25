#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_CONDITION_NUM 2

class GiftConditionDesc : public NFIDescStore
{
public:
	GiftConditionDesc();
	virtual ~GiftConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GiftCondition_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GiftCondition_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GiftCondition_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GiftCondition_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GiftConditionDesc, proto_ff_s::E_GiftCondition_s, E_GiftCondition, MAX_GIFT_CONDITION_NUM);
DECLARE_IDCREATE_GLOBAL(GiftConditionDesc);
};
