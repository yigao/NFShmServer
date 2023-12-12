#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_FINDPOOL_NUM 256

class FindtreasureFindpoolDesc : public NFIDescTemplate<FindtreasureFindpoolDesc, proto_ff_s::E_FindtreasureFindpool_s, EOT_CONST_FINDTREASURE_FINDPOOL_DESC_ID, MAX_FINDTREASURE_FINDPOOL_NUM>
{
public:
	FindtreasureFindpoolDesc();
	virtual ~FindtreasureFindpoolDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
