#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godvalley_s.h"

#define MAX_GODVALLEY_ATTRIBUTE_NUM 2

class GodvalleyAttributeDesc : public NFIDescTemplate<GodvalleyAttributeDesc, proto_ff_s::E_GodvalleyAttribute_s, EOT_CONST_GODVALLEY_ATTRIBUTE_DESC_ID, MAX_GODVALLEY_ATTRIBUTE_NUM>
{
public:
	GodvalleyAttributeDesc();
	virtual ~GodvalleyAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
