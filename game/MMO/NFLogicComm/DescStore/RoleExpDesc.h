#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_EXP_NUM 2048

class RoleExpDesc : public NFIDescTemplate<RoleExpDesc, proto_ff_s::E_RoleExp_s, EOT_CONST_ROLE_EXP_DESC_ID, MAX_ROLE_EXP_NUM>
{
public:
	RoleExpDesc();
	virtual ~RoleExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
