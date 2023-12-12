#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_SOULACTIVE_NUM 16

class CloakSoulactiveDesc : public NFIDescTemplate<CloakSoulactiveDesc, proto_ff_s::E_CloakSoulactive_s, EOT_CONST_CLOAK_SOULACTIVE_DESC_ID, MAX_CLOAK_SOULACTIVE_NUM>
{
public:
	CloakSoulactiveDesc();
	virtual ~CloakSoulactiveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
