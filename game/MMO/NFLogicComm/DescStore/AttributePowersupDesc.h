#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Attribute_s.h"

#define MAX_ATTRIBUTE_POWERSUP_NUM 128

class AttributePowersupDesc : public NFIDescTemplate<AttributePowersupDesc, proto_ff_s::E_AttributePowersup_s, EOT_CONST_ATTRIBUTE_POWERSUP_DESC_ID, MAX_ATTRIBUTE_POWERSUP_NUM>
{
public:
	AttributePowersupDesc();
	virtual ~AttributePowersupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
