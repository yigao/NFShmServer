#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_ATTRIBUTE_NUM 512

class ShentiAttributeDesc : public NFIDescTemplate<ShentiAttributeDesc, proto_ff_s::E_ShentiAttribute_s, EOT_CONST_SHENTI_ATTRIBUTE_DESC_ID, MAX_SHENTI_ATTRIBUTE_NUM>
{
public:
	ShentiAttributeDesc();
	virtual ~ShentiAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
