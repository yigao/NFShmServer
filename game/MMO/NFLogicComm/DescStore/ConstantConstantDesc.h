#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Constant_s.h"

#define MAX_CONSTANT_CONSTANT_NUM 512

class ConstantConstantDesc : public NFIDescTemplate<ConstantConstantDesc, proto_ff_s::E_ConstantConstant_s, EOT_CONST_CONSTANT_CONSTANT_DESC_ID, MAX_CONSTANT_CONSTANT_NUM>
{
public:
	ConstantConstantDesc();
	virtual ~ConstantConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
