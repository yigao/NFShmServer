#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANSECOND_NUM 64

class RandomnameMansecondDesc : public NFIDescStore
{
public:
	RandomnameMansecondDesc();
	virtual ~RandomnameMansecondDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RandomnameMansecond_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameMansecond_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameMansecond_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameMansecond_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RandomnameMansecondDesc, proto_ff_s::E_RandomnameMansecond_s, E_RandomnameMansecond, MAX_RANDOMNAME_MANSECOND_NUM);
DECLARE_IDCREATE(RandomnameMansecondDesc);
};
