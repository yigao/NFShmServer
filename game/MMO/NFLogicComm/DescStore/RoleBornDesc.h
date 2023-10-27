#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_BORN_NUM 16

class RoleBornDesc : public NFIDescTemplate<RoleBornDesc, proto_ff_s::E_RoleBorn_s, EOT_CONST_ROLE_BORN_DESC_ID, MAX_ROLE_BORN_NUM>
{
public:
	RoleBornDesc();
	virtual ~RoleBornDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
