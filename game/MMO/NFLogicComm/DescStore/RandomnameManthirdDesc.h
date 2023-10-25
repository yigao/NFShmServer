#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANTHIRD_NUM 1024

class RandomnameManthirdDesc : public NFIDescStore
{
public:
	RandomnameManthirdDesc();
	virtual ~RandomnameManthirdDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RandomnameManthird_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RandomnameManthird_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RandomnameManthird_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RandomnameManthird_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RandomnameManthirdDesc, proto_ff_s::E_RandomnameManthird_s, E_RandomnameManthird, MAX_RANDOMNAME_MANTHIRD_NUM);
DECLARE_IDCREATE_GLOBAL(RandomnameManthirdDesc);
};
