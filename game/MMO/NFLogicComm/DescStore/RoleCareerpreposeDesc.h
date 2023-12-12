#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_CAREERPREPOSE_NUM 8

class RoleCareerpreposeDesc : public NFIDescTemplate<RoleCareerpreposeDesc, proto_ff_s::E_RoleCareerprepose_s, EOT_CONST_ROLE_CAREERPREPOSE_DESC_ID, MAX_ROLE_CAREERPREPOSE_NUM>
{
public:
	RoleCareerpreposeDesc();
	virtual ~RoleCareerpreposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
