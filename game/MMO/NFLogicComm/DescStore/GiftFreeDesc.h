#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gift_s.h"

#define MAX_GIFT_FREE_NUM 16

class GiftFreeDesc : public NFIDescStore
{
public:
	GiftFreeDesc();
	virtual ~GiftFreeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GiftFree_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GiftFree_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GiftFree_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GiftFree_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GiftFreeDesc, proto_ff_s::E_GiftFree_s, E_GiftFree, MAX_GIFT_FREE_NUM);
DECLARE_IDCREATE_GLOBAL(GiftFreeDesc);
};
