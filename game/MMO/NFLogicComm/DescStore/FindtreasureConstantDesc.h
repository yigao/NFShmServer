#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_CONSTANT_NUM 2

class FindtreasureConstantDesc : public NFIDescTemplate<FindtreasureConstantDesc, proto_ff_s::E_FindtreasureConstant_s, EOT_CONST_FINDTREASURE_CONSTANT_DESC_ID, MAX_FINDTREASURE_CONSTANT_NUM>
{
public:
	FindtreasureConstantDesc();
	virtual ~FindtreasureConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
