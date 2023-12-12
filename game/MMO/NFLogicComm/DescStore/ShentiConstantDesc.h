#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_CONSTANT_NUM 2

class ShentiConstantDesc : public NFIDescTemplate<ShentiConstantDesc, proto_ff_s::E_ShentiConstant_s, EOT_CONST_SHENTI_CONSTANT_DESC_ID, MAX_SHENTI_CONSTANT_NUM>
{
public:
	ShentiConstantDesc();
	virtual ~ShentiConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
