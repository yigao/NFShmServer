#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANFIRST_NUM 64

class RandomnameManfirstDesc : public NFIDescStore
{
public:
	RandomnameManfirstDesc();
	virtual ~RandomnameManfirstDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RandomnameManfirst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameManfirst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameManfirst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameManfirst_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RandomnameManfirstDesc, proto_ff_s::E_RandomnameManfirst_s, E_RandomnameManfirst, MAX_RANDOMNAME_MANFIRST_NUM);
DECLARE_IDCREATE(RandomnameManfirstDesc);
};
