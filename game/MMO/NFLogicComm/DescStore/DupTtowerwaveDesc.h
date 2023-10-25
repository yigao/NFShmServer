#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_TTOWERWAVE_NUM 1024

class DupTtowerwaveDesc : public NFIDescStore
{
public:
	DupTtowerwaveDesc();
	virtual ~DupTtowerwaveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupTtowerwave_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupTtowerwave_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupTtowerwave_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupTtowerwave_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupTtowerwaveDesc, proto_ff_s::E_DupTtowerwave_s, E_DupTtowerwave, MAX_DUP_TTOWERWAVE_NUM);
DECLARE_IDCREATE_GLOBAL(DupTtowerwaveDesc);
};
