#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXPRESSSHOP_NUM 4

class MarryExpressshopDesc : public NFIDescTemplate<MarryExpressshopDesc, proto_ff_s::E_MarryExpressshop_s, EOT_CONST_MARRY_EXPRESSSHOP_DESC_ID, MAX_MARRY_EXPRESSSHOP_NUM>
{
public:
	MarryExpressshopDesc();
	virtual ~MarryExpressshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
