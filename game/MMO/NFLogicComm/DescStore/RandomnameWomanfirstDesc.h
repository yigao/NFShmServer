#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_WOMANFIRST_NUM 300

class RandomnameWomanfirstDesc : public NFIDescStore
{
public:
	RandomnameWomanfirstDesc();
	virtual ~RandomnameWomanfirstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameWomanfirst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameWomanfirst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameWomanfirst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameWomanfirst_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameWomanfirstDesc, proto_ff_s::E_RandomnameWomanfirst_s, E_RandomnameWomanfirst, MAX_RANDOMNAME_WOMANFIRST_NUM);
DECLARE_IDCREATE(RandomnameWomanfirstDesc);
};
