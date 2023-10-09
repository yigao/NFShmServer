#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_PETEQUIP_NUM 32

class PetPetequipDesc : public NFIDescStore
{
public:
	PetPetequipDesc();
	virtual ~PetPetequipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetPetequip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetPetequip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetPetequip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetPetequip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetPetequipDesc, proto_ff_s::E_PetPetequip_s, E_PetPetequip, MAX_PET_PETEQUIP_NUM);
DECLARE_IDCREATE(PetPetequipDesc);
};
