#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_ATTRIBUTE_NUM 32

class OccupationAttributeDesc : public NFIDescTemplate<OccupationAttributeDesc, proto_ff_s::E_OccupationAttribute_s, EOT_CONST_OCCUPATION_ATTRIBUTE_DESC_ID, MAX_OCCUPATION_ATTRIBUTE_NUM>
{
public:
	OccupationAttributeDesc();
	virtual ~OccupationAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
