#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVEUP_NUM 32

class FindtreasureActiveupDesc : public NFIDescTemplate<FindtreasureActiveupDesc, proto_ff_s::E_FindtreasureActiveup_s, EOT_CONST_FINDTREASURE_ACTIVEUP_DESC_ID, MAX_FINDTREASURE_ACTIVEUP_NUM>
{
public:
	FindtreasureActiveupDesc();
	virtual ~FindtreasureActiveupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
