#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Personalshop_s.h"

#define MAX_PERSONALSHOP_SHOPITEMS_NUM 1024

class PersonalshopShopitemsDesc : public NFIDescTemplate<PersonalshopShopitemsDesc, proto_ff_s::E_PersonalshopShopitems_s, EOT_CONST_PERSONALSHOP_SHOPITEMS_DESC_ID, MAX_PERSONALSHOP_SHOPITEMS_NUM>
{
public:
	PersonalshopShopitemsDesc();
	virtual ~PersonalshopShopitemsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
