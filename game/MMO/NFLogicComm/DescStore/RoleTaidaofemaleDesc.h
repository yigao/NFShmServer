#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_TAIDAOFEMALE_NUM 2048

class RoleTaidaofemaleDesc : public NFIDescTemplate<RoleTaidaofemaleDesc, proto_ff_s::E_RoleTaidaofemale_s, EOT_CONST_ROLE_TAIDAOFEMALE_DESC_ID, MAX_ROLE_TAIDAOFEMALE_NUM>
{
public:
	RoleTaidaofemaleDesc();
	virtual ~RoleTaidaofemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
