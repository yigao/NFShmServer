#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_INTENSIFYITEM_NUM 4

class CloakIntensifyitemDesc : public NFIDescTemplate<CloakIntensifyitemDesc, proto_ff_s::E_CloakIntensifyitem_s, EOT_CONST_CLOAK_INTENSIFYITEM_DESC_ID, MAX_CLOAK_INTENSIFYITEM_NUM>
{
public:
	CloakIntensifyitemDesc();
	virtual ~CloakIntensifyitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
