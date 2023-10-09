#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_WOMANFIRST_NUM 256

class RandomnameWomanfirstDesc : public NFIDescStore
{
public:
	RandomnameWomanfirstDesc();
	virtual ~RandomnameWomanfirstDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RandomnameWomanfirst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameWomanfirst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameWomanfirst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameWomanfirst_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RandomnameWomanfirstDesc, proto_ff_s::E_RandomnameWomanfirst_s, E_RandomnameWomanfirst, MAX_RANDOMNAME_WOMANFIRST_NUM);
DECLARE_IDCREATE(RandomnameWomanfirstDesc);
};
