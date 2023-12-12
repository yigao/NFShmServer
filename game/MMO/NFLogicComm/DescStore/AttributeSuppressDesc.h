#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Attribute_s.h"

#define MAX_ATTRIBUTE_SUPPRESS_NUM 512

class AttributeSuppressDesc : public NFIDescTemplate<AttributeSuppressDesc, proto_ff_s::E_AttributeSuppress_s, EOT_CONST_ATTRIBUTE_SUPPRESS_DESC_ID, MAX_ATTRIBUTE_SUPPRESS_NUM>
{
public:
	AttributeSuppressDesc();
	virtual ~AttributeSuppressDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
