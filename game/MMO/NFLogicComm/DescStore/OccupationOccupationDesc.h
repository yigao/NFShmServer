#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_OCCUPATION_NUM 16

class OccupationOccupationDesc : public NFIDescTemplate<OccupationOccupationDesc, proto_ff_s::E_OccupationOccupation_s, EOT_CONST_OCCUPATION_OCCUPATION_DESC_ID, MAX_OCCUPATION_OCCUPATION_NUM>
{
public:
	OccupationOccupationDesc();
	virtual ~OccupationOccupationDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
