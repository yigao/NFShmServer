#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SICKLEFEMALE_NUM 2048

class RoleSicklefemaleDesc : public NFIDescTemplate<RoleSicklefemaleDesc, proto_ff_s::E_RoleSicklefemale_s, EOT_CONST_ROLE_SICKLEFEMALE_DESC_ID, MAX_ROLE_SICKLEFEMALE_NUM>
{
public:
	RoleSicklefemaleDesc();
	virtual ~RoleSicklefemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
