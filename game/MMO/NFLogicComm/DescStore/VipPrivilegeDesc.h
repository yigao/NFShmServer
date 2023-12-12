#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_PRIVILEGE_NUM 512

class VipPrivilegeDesc : public NFIDescTemplate<VipPrivilegeDesc, proto_ff_s::E_VipPrivilege_s, EOT_CONST_VIP_PRIVILEGE_DESC_ID, MAX_VIP_PRIVILEGE_NUM>
{
public:
	VipPrivilegeDesc();
	virtual ~VipPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
