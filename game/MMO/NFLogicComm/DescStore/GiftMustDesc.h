#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_MUST_NUM 32

class GiftMustDesc : public NFIDescStore
{
public:
	GiftMustDesc();
	virtual ~GiftMustDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GiftMust_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GiftMust_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GiftMust_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GiftMust_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GiftMustDesc, proto_ff_s::E_GiftMust_s, E_GiftMust, MAX_GIFT_MUST_NUM);
DECLARE_IDCREATE(GiftMustDesc);
};
