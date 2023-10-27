#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SKILLTYPE_NUM 128

class RoleSkilltypeDesc : public NFIDescTemplate<RoleSkilltypeDesc, proto_ff_s::E_RoleSkilltype_s, EOT_CONST_ROLE_SKILLTYPE_DESC_ID, MAX_ROLE_SKILLTYPE_NUM>
{
public:
	RoleSkilltypeDesc();
	virtual ~RoleSkilltypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
