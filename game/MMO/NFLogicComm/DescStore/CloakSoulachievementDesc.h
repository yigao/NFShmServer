#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_SOULACHIEVEMENT_NUM 32

class CloakSoulachievementDesc : public NFIDescTemplate<CloakSoulachievementDesc, proto_ff_s::E_CloakSoulachievement_s, EOT_CONST_CLOAK_SOULACHIEVEMENT_DESC_ID, MAX_CLOAK_SOULACHIEVEMENT_NUM>
{
public:
	CloakSoulachievementDesc();
	virtual ~CloakSoulachievementDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
