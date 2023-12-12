#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_REFINE_NUM 128

class CloakRefineDesc : public NFIDescTemplate<CloakRefineDesc, proto_ff_s::E_CloakRefine_s, EOT_CONST_CLOAK_REFINE_DESC_ID, MAX_CLOAK_REFINE_NUM>
{
public:
	CloakRefineDesc();
	virtual ~CloakRefineDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
