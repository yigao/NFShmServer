#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_ADDSKILL_NUM 2

class RoleAddskillDesc : public NFIDescTemplate<RoleAddskillDesc, proto_ff_s::E_RoleAddskill_s, EOT_CONST_ROLE_ADDSKILL_DESC_ID, MAX_ROLE_ADDSKILL_NUM>
{
public:
	RoleAddskillDesc();
	virtual ~RoleAddskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
