#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SHOP_NUM 32

class FestivalMuban_shopDesc : public NFIDescStore
{
public:
	FestivalMuban_shopDesc();
	virtual ~FestivalMuban_shopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_shop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_shop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_shop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_shop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_shopDesc, proto_ff_s::E_FestivalMuban_shop_s, E_FestivalMuban_shop, MAX_FESTIVAL_MUBAN_SHOP_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_shopDesc);
};
