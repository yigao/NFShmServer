#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_WISH_NUM 2048

class WelfareWishDesc : public NFIDescStore
{
public:
	WelfareWishDesc();
	virtual ~WelfareWishDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareWish_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareWish_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareWish_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareWish_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareWishDesc, proto_ff_s::E_WelfareWish_s, E_WelfareWish, MAX_WELFARE_WISH_NUM);
DECLARE_IDCREATE(WelfareWishDesc);
};
