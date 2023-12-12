#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_COSNTANT_NUM 2

class VipCosntantDesc : public NFIDescTemplate<VipCosntantDesc, proto_ff_s::E_VipCosntant_s, EOT_CONST_VIP_COSNTANT_DESC_ID, MAX_VIP_COSNTANT_NUM>
{
public:
	VipCosntantDesc();
	virtual ~VipCosntantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
