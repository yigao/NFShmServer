#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_CHANGECAREER_NUM 16

class RoleChangecareerDesc : public NFIDescTemplate<RoleChangecareerDesc, proto_ff_s::E_RoleChangecareer_s, EOT_CONST_ROLE_CHANGECAREER_DESC_ID, MAX_ROLE_CHANGECAREER_NUM>
{
public:
	RoleChangecareerDesc();
	virtual ~RoleChangecareerDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
