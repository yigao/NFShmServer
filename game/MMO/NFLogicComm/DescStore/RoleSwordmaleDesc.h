#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SWORDMALE_NUM 2048

class RoleSwordmaleDesc : public NFIDescTemplate<RoleSwordmaleDesc, proto_ff_s::E_RoleSwordmale_s, EOT_CONST_ROLE_SWORDMALE_DESC_ID, MAX_ROLE_SWORDMALE_NUM>
{
public:
	RoleSwordmaleDesc();
	virtual ~RoleSwordmaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
