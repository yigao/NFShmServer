#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVE_NUM 8

class FindtreasureActiveDesc : public NFIDescTemplate<FindtreasureActiveDesc, proto_ff_s::E_FindtreasureActive_s, EOT_CONST_FINDTREASURE_ACTIVE_DESC_ID, MAX_FINDTREASURE_ACTIVE_NUM>
{
public:
	FindtreasureActiveDesc();
	virtual ~FindtreasureActiveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
