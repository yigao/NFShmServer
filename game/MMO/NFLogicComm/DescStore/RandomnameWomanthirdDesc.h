#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_WOMANTHIRD_NUM 400

class RandomnameWomanthirdDesc : public NFIDescStore
{
public:
	RandomnameWomanthirdDesc();
	virtual ~RandomnameWomanthirdDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameWomanthird_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameWomanthird_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameWomanthird_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameWomanthird_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameWomanthirdDesc, proto_ff_s::E_RandomnameWomanthird_s, E_RandomnameWomanthird, MAX_RANDOMNAME_WOMANTHIRD_NUM);
DECLARE_IDCREATE(RandomnameWomanthirdDesc);
};
