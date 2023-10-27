#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Attribute_s.h"

#define MAX_ATTRIBUTE_ATTRIBUTE_NUM 256

class AttributeAttributeDesc : public NFIDescTemplate<AttributeAttributeDesc, proto_ff_s::E_AttributeAttribute_s, EOT_CONST_ATTRIBUTE_ATTRIBUTE_DESC_ID, MAX_ATTRIBUTE_ATTRIBUTE_NUM>
{
public:
	AttributeAttributeDesc();
	virtual ~AttributeAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
