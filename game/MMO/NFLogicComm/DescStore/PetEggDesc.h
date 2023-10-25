#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_EGG_NUM 64

class PetEggDesc : public NFIDescStore
{
public:
	PetEggDesc();
	virtual ~PetEggDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetEgg_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetEgg_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetEgg_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetEgg_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetEggDesc, proto_ff_s::E_PetEgg_s, E_PetEgg, MAX_PET_EGG_NUM);
DECLARE_IDCREATE_GLOBAL(PetEggDesc);
};
