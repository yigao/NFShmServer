#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_SOUL_NUM 2

class CloakSoulDesc : public NFIDescTemplate<CloakSoulDesc, proto_ff_s::E_CloakSoul_s, EOT_CONST_CLOAK_SOUL_DESC_ID, MAX_CLOAK_SOUL_NUM>
{
public:
	CloakSoulDesc();
	virtual ~CloakSoulDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
