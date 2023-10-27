#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenworld_s.h"

#define MAX_XIUZHENWORLD_CONSTANT_NUM 4

class XiuzhenworldConstantDesc : public NFIDescTemplate<XiuzhenworldConstantDesc, proto_ff_s::E_XiuzhenworldConstant_s, EOT_CONST_XIUZHENWORLD_CONSTANT_DESC_ID, MAX_XIUZHENWORLD_CONSTANT_NUM>
{
public:
	XiuzhenworldConstantDesc();
	virtual ~XiuzhenworldConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
