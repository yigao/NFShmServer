#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM 300

class FunctionunlockFunctionunlockDesc : public NFIDescStore
{
public:
	FunctionunlockFunctionunlockDesc(NFIPluginManager* pPluginManager);
	virtual ~FunctionunlockFunctionunlockDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::functionunlockfunctionUnlock_s* GetDesc(int id) const;
	proto_ff_s::functionunlockfunctionUnlock_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::functionunlockfunctionUnlock_s, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::functionunlockfunctionUnlock_s, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::functionunlockfunctionUnlock_s, functionunlockfunctionUnlock, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM);
DECLARE_IDCREATE(FunctionunlockFunctionunlockDesc);
};
