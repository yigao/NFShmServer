#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_STARVALUE_NUM 256

class PetStarvalueDesc : public NFIDescStore
{
public:
	PetStarvalueDesc();
	virtual ~PetStarvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetStarvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetStarvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetStarvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetStarvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetStarvalueDesc, proto_ff_s::E_PetStarvalue_s, E_PetStarvalue, MAX_PET_STARVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(PetStarvalueDesc);
};
