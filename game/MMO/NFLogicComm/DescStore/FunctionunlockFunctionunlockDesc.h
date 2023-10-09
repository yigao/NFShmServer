#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM 256

class FunctionunlockFunctionunlockDesc : public NFIDescStore
{
public:
	FunctionunlockFunctionunlockDesc();
	virtual ~FunctionunlockFunctionunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FunctionunlockFunctionunlock_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FunctionunlockFunctionunlockDesc, proto_ff_s::E_FunctionunlockFunctionunlock_s, E_FunctionunlockFunctionunlock, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM);
DECLARE_IDCREATE(FunctionunlockFunctionunlockDesc);
};
