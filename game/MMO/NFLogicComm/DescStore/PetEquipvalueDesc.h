#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_EQUIPVALUE_NUM 1024

class PetEquipvalueDesc : public NFIDescStore
{
public:
	PetEquipvalueDesc();
	virtual ~PetEquipvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetEquipvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetEquipvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetEquipvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetEquipvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetEquipvalueDesc, proto_ff_s::E_PetEquipvalue_s, E_PetEquipvalue, MAX_PET_EQUIPVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(PetEquipvalueDesc);
};
