#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_SOULCLEAR_NUM 2

class CloakSoulclearDesc : public NFIDescTemplate<CloakSoulclearDesc, proto_ff_s::E_CloakSoulclear_s, EOT_CONST_CLOAK_SOULCLEAR_DESC_ID, MAX_CLOAK_SOULCLEAR_NUM>
{
public:
	CloakSoulclearDesc();
	virtual ~CloakSoulclearDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
