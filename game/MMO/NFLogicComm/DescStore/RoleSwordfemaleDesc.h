#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SWORDFEMALE_NUM 2048

class RoleSwordfemaleDesc : public NFIDescTemplate<RoleSwordfemaleDesc, proto_ff_s::E_RoleSwordfemale_s, EOT_CONST_ROLE_SWORDFEMALE_DESC_ID, MAX_ROLE_SWORDFEMALE_NUM>
{
public:
	RoleSwordfemaleDesc();
	virtual ~RoleSwordfemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
