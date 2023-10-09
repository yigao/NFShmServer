#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_DUP_NUM 2048

class DupDupDesc : public NFIDescStore
{
public:
	DupDupDesc();
	virtual ~DupDupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupDup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupDup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupDup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupDup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupDupDesc, proto_ff_s::E_DupDup_s, E_DupDup, MAX_DUP_DUP_NUM);
DECLARE_IDCREATE(DupDupDesc);
};
