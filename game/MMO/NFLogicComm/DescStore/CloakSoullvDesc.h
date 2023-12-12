#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_SOULLV_NUM 128

class CloakSoullvDesc : public NFIDescTemplate<CloakSoullvDesc, proto_ff_s::E_CloakSoullv_s, EOT_CONST_CLOAK_SOULLV_DESC_ID, MAX_CLOAK_SOULLV_NUM>
{
public:
	CloakSoullvDesc();
	virtual ~CloakSoullvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
