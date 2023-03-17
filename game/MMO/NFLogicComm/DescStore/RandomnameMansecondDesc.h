#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_MANSECOND_NUM 60

class RandomnameMansecondDesc : public NFIDescStore
{
public:
	RandomnameMansecondDesc();
	virtual ~RandomnameMansecondDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameMansecond_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameMansecond_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameMansecond_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameMansecond_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameMansecondDesc, proto_ff_s::E_RandomnameMansecond_s, E_RandomnameMansecond, MAX_RANDOMNAME_MANSECOND_NUM);
DECLARE_IDCREATE(RandomnameMansecondDesc);
};
