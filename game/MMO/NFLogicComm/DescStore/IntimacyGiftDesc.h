#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_IntimacyGift_s* GetDesc(int id) const;
	proto_ff_s::E_IntimacyGift_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_IntimacyGift_s, intimacygift, MAX_INTIMACY_GIFT_NUM);
DECLARE_IDCREATE(IntimacyGiftDesc);
};
