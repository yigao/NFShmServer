#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Personalshop_s.h"

#define MAX_PERSONALSHOP_SHOPS_NUM 2

class PersonalshopShopsDesc : public NFIDescTemplate<PersonalshopShopsDesc, proto_ff_s::E_PersonalshopShops_s, EOT_CONST_PERSONALSHOP_SHOPS_DESC_ID, MAX_PERSONALSHOP_SHOPS_NUM>
{
public:
	PersonalshopShopsDesc();
	virtual ~PersonalshopShopsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
