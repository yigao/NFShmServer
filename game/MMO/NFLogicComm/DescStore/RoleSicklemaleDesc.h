#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SICKLEMALE_NUM 2048

class RoleSicklemaleDesc : public NFIDescTemplate<RoleSicklemaleDesc, proto_ff_s::E_RoleSicklemale_s, EOT_CONST_ROLE_SICKLEMALE_DESC_ID, MAX_ROLE_SICKLEMALE_NUM>
{
public:
	RoleSicklemaleDesc();
	virtual ~RoleSicklemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
