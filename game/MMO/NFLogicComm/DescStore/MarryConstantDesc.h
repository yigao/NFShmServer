#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CONSTANT_NUM 4

class MarryConstantDesc : public NFIDescTemplate<MarryConstantDesc, proto_ff_s::E_MarryConstant_s, EOT_CONST_MARRY_CONSTANT_DESC_ID, MAX_MARRY_CONSTANT_NUM>
{
public:
	MarryConstantDesc();
	virtual ~MarryConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
