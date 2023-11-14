#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_SALE_NUM 8

class NickgodSaleDesc : public NFIDescTemplate<NickgodSaleDesc, proto_ff_s::E_NickgodSale_s, EOT_CONST_NICKGOD_SALE_DESC_ID, MAX_NICKGOD_SALE_NUM>
{
public:
	NickgodSaleDesc();
	virtual ~NickgodSaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
