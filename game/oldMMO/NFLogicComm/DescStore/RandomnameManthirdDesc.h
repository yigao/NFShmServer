#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_MANTHIRD_NUM 500

class RandomnameManthirdDesc : public NFIDescStore
{
public:
	RandomnameManthirdDesc();
	virtual ~RandomnameManthirdDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RandomnameManthird_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameManthird_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameManthird_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameManthird_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RandomnameManthirdDesc, proto_ff_s::E_RandomnameManthird_s, E_RandomnameManthird, MAX_RANDOMNAME_MANTHIRD_NUM);
DECLARE_IDCREATE(RandomnameManthirdDesc);
};
