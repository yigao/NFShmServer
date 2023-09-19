#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_WOMANSECOND_NUM 40

class RandomnameWomansecondDesc : public NFIDescStore
{
public:
	RandomnameWomansecondDesc();
	virtual ~RandomnameWomansecondDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameWomansecond_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameWomansecond_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameWomansecond_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameWomansecond_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameWomansecondDesc, proto_ff_s::E_RandomnameWomansecond_s, E_RandomnameWomansecond, MAX_RANDOMNAME_WOMANSECOND_NUM);
DECLARE_IDCREATE(RandomnameWomansecondDesc);
};
