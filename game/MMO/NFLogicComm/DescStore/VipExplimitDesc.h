#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_EXPLIMIT_NUM 2048

class VipExplimitDesc : public NFIDescTemplate<VipExplimitDesc, proto_ff_s::E_VipExplimit_s, EOT_CONST_VIP_EXPLIMIT_DESC_ID, MAX_VIP_EXPLIMIT_NUM>
{
public:
	VipExplimitDesc();
	virtual ~VipExplimitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
