#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_REFINEUNLOCK_NUM 64

class CloakRefineunlockDesc : public NFIDescTemplate<CloakRefineunlockDesc, proto_ff_s::E_CloakRefineunlock_s, EOT_CONST_CLOAK_REFINEUNLOCK_DESC_ID, MAX_CLOAK_REFINEUNLOCK_NUM>
{
public:
	CloakRefineunlockDesc();
	virtual ~CloakRefineunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
