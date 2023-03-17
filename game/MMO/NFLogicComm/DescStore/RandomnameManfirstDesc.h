#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_MANFIRST_NUM 100

class RandomnameManfirstDesc : public NFIDescStore
{
public:
	RandomnameManfirstDesc();
	virtual ~RandomnameManfirstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameManfirst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameManfirst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameManfirst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameManfirst_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameManfirstDesc, proto_ff_s::E_RandomnameManfirst_s, E_RandomnameManfirst, MAX_RANDOMNAME_MANFIRST_NUM);
DECLARE_IDCREATE(RandomnameManfirstDesc);
};
