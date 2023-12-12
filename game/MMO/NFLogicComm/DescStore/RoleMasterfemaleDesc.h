#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_MASTERFEMALE_NUM 2048

class RoleMasterfemaleDesc : public NFIDescTemplate<RoleMasterfemaleDesc, proto_ff_s::E_RoleMasterfemale_s, EOT_CONST_ROLE_MASTERFEMALE_DESC_ID, MAX_ROLE_MASTERFEMALE_NUM>
{
public:
	RoleMasterfemaleDesc();
	virtual ~RoleMasterfemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
