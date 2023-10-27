#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_TOTAL_NUM 64

class FindtreasureTotalDesc : public NFIDescTemplate<FindtreasureTotalDesc, proto_ff_s::E_FindtreasureTotal_s, EOT_CONST_FINDTREASURE_TOTAL_DESC_ID, MAX_FINDTREASURE_TOTAL_NUM>
{
public:
	FindtreasureTotalDesc();
	virtual ~FindtreasureTotalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
