#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_SHOP_NUM 16

class TianxiafirstShopDesc : public NFIDescTemplate<TianxiafirstShopDesc, proto_ff_s::E_TianxiafirstShop_s, EOT_CONST_TIANXIAFIRST_SHOP_DESC_ID, MAX_TIANXIAFIRST_SHOP_NUM>
{
public:
	TianxiafirstShopDesc();
	virtual ~TianxiafirstShopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
