#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_SHOP_NUM 32

class BattlepassShopDesc : public NFIDescStore
{
public:
	BattlepassShopDesc();
	virtual ~BattlepassShopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BattlepassShop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BattlepassShop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BattlepassShop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BattlepassShop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BattlepassShopDesc, proto_ff_s::E_BattlepassShop_s, E_BattlepassShop, MAX_BATTLEPASS_SHOP_NUM);
DECLARE_IDCREATE(BattlepassShopDesc);
};