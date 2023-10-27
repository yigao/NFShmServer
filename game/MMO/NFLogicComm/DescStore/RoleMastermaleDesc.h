#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_MASTERMALE_NUM 2048

class RoleMastermaleDesc : public NFIDescTemplate<RoleMastermaleDesc, proto_ff_s::E_RoleMastermale_s, EOT_CONST_ROLE_MASTERMALE_DESC_ID, MAX_ROLE_MASTERMALE_NUM>
{
public:
	RoleMastermaleDesc();
	virtual ~RoleMastermaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
