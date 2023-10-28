#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM 512

class FunctionunlockFunctionunlockDesc : public NFIDescTemplate<FunctionunlockFunctionunlockDesc, proto_ff_s::E_FunctionunlockFunctionunlock_s, EOT_CONST_FUNCTIONUNLOCK_FUNCTIONUNLOCK_DESC_ID, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM>
{
public:
	FunctionunlockFunctionunlockDesc();
	virtual ~FunctionunlockFunctionunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
