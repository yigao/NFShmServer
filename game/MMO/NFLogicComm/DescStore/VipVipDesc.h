#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_VIP_NUM 16

class VipVipDesc : public NFIDescTemplate<VipVipDesc, proto_ff_s::E_VipVip_s, EOT_CONST_VIP_VIP_DESC_ID, MAX_VIP_VIP_NUM>
{
public:
	VipVipDesc();
	virtual ~VipVipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
