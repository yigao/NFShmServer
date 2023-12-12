#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_WORLDEXP_NUM 512

class RoleWorldexpDesc : public NFIDescTemplate<RoleWorldexpDesc, proto_ff_s::E_RoleWorldexp_s, EOT_CONST_ROLE_WORLDEXP_DESC_ID, MAX_ROLE_WORLDEXP_NUM>
{
public:
	RoleWorldexpDesc();
	virtual ~RoleWorldexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
