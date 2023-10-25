#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_SHOP_NUM 16

class FindtreasureShopDesc : public NFIDescStore
{
public:
	FindtreasureShopDesc();
	virtual ~FindtreasureShopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureShop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureShop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureShop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureShop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureShopDesc, proto_ff_s::E_FindtreasureShop_s, E_FindtreasureShop, MAX_FINDTREASURE_SHOP_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureShopDesc);
};
