#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_SHOP_NUM 32

class BattlepassShopDesc : public NFIDescTemplate<BattlepassShopDesc, proto_ff_s::E_BattlepassShop_s, EOT_CONST_BATTLEPASS_SHOP_DESC_ID, MAX_BATTLEPASS_SHOP_NUM>
{
public:
	BattlepassShopDesc();
	virtual ~BattlepassShopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
