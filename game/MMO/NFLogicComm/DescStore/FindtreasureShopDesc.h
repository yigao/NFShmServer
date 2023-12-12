#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_SHOP_NUM 16

class FindtreasureShopDesc : public NFIDescTemplate<FindtreasureShopDesc, proto_ff_s::E_FindtreasureShop_s, EOT_CONST_FINDTREASURE_SHOP_DESC_ID, MAX_FINDTREASURE_SHOP_NUM>
{
public:
	FindtreasureShopDesc();
	virtual ~FindtreasureShopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
