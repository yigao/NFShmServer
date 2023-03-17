#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM 200

class FunctionunlockFunctionunlockDesc : public NFIDescStore
{
public:
	FunctionunlockFunctionunlockDesc();
	virtual ~FunctionunlockFunctionunlockDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FunctionunlockFunctionunlockDesc, proto_ff_s::E_FunctionunlockFunctionunlock_s, E_FunctionunlockFunctionunlock, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM);
DECLARE_IDCREATE(FunctionunlockFunctionunlockDesc);
};
