#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_FINDTREASURE_NUM 16

class FindtreasureFindtreasureDesc : public NFIDescTemplate<FindtreasureFindtreasureDesc, proto_ff_s::E_FindtreasureFindtreasure_s, EOT_CONST_FINDTREASURE_FINDTREASURE_DESC_ID, MAX_FINDTREASURE_FINDTREASURE_NUM>
{
public:
	FindtreasureFindtreasureDesc();
	virtual ~FindtreasureFindtreasureDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
