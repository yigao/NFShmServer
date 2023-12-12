#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_ACTIVATE_NUM 8

class CloakActivateDesc : public NFIDescTemplate<CloakActivateDesc, proto_ff_s::E_CloakActivate_s, EOT_CONST_CLOAK_ACTIVATE_DESC_ID, MAX_CLOAK_ACTIVATE_NUM>
{
public:
	CloakActivateDesc();
	virtual ~CloakActivateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
