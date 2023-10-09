#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STARLIBRARY_NUM 64

class ShentiStarlibraryDesc : public NFIDescStore
{
public:
	ShentiStarlibraryDesc();
	virtual ~ShentiStarlibraryDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiStarlibrary_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiStarlibrary_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiStarlibrary_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiStarlibrary_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiStarlibraryDesc, proto_ff_s::E_ShentiStarlibrary_s, E_ShentiStarlibrary, MAX_SHENTI_STARLIBRARY_NUM);
DECLARE_IDCREATE(ShentiStarlibraryDesc);
};
