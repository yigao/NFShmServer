#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_GOD_NUM 8

class CloakGodDesc : public NFIDescTemplate<CloakGodDesc, proto_ff_s::E_CloakGod_s, EOT_CONST_CLOAK_GOD_DESC_ID, MAX_CLOAK_GOD_NUM>
{
public:
	CloakGodDesc();
	virtual ~CloakGodDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
