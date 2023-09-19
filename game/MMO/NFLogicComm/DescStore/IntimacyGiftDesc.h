#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/intimacy_s.h"

#define MAX_INTIMACY_GIFT_NUM 20

class IntimacyGiftDesc : public NFIDescStore
{
public:
	IntimacyGiftDesc();
	virtual ~IntimacyGiftDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_IntimacyGift_s* GetDesc(int64_t id) const;
	proto_ff_s::E_IntimacyGift_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_IntimacyGift_s* GetDescByIndex(int index) const;
	proto_ff_s::E_IntimacyGift_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(IntimacyGiftDesc, proto_ff_s::E_IntimacyGift_s, E_IntimacyGift, MAX_INTIMACY_GIFT_NUM);
DECLARE_IDCREATE(IntimacyGiftDesc);
};
