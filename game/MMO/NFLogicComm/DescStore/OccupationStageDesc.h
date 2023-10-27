#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_STAGE_NUM 32

class OccupationStageDesc : public NFIDescTemplate<OccupationStageDesc, proto_ff_s::E_OccupationStage_s, EOT_CONST_OCCUPATION_STAGE_DESC_ID, MAX_OCCUPATION_STAGE_NUM>
{
public:
	OccupationStageDesc();
	virtual ~OccupationStageDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
