#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_WRAITHSVALUE_NUM 256

class PetWraithsvalueDesc : public NFIDescStore
{
public:
	PetWraithsvalueDesc();
	virtual ~PetWraithsvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetWraithsvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetWraithsvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetWraithsvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetWraithsvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetWraithsvalueDesc, proto_ff_s::E_PetWraithsvalue_s, E_PetWraithsvalue, MAX_PET_WRAITHSVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(PetWraithsvalueDesc);
};
