#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_VALUE_NUM 1024

class CloakValueDesc : public NFIDescTemplate<CloakValueDesc, proto_ff_s::E_CloakValue_s, EOT_CONST_CLOAK_VALUE_DESC_ID, MAX_CLOAK_VALUE_NUM>
{
public:
	CloakValueDesc();
	virtual ~CloakValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
