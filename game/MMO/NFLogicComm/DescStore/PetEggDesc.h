#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_EGG_NUM 20

class PetEggDesc : public NFIDescStore
{
public:
	PetEggDesc();
	virtual ~PetEggDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetEgg_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetEgg_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetEgg_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetEgg_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetEgg_s, E_PetEgg, MAX_PET_EGG_NUM);
DECLARE_IDCREATE(PetEggDesc);
};
