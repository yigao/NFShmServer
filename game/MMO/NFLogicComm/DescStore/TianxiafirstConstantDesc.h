#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_CONSTANT_NUM 2

class TianxiafirstConstantDesc : public NFIDescTemplate<TianxiafirstConstantDesc, proto_ff_s::E_TianxiafirstConstant_s, EOT_CONST_TIANXIAFIRST_CONSTANT_DESC_ID, MAX_TIANXIAFIRST_CONSTANT_NUM>
{
public:
	TianxiafirstConstantDesc();
	virtual ~TianxiafirstConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
