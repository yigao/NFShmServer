#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_SMELT_NUM 64

class PetSmeltDesc : public NFIDescStore
{
public:
	PetSmeltDesc();
	virtual ~PetSmeltDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetSmelt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetSmelt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetSmelt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetSmelt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetSmeltDesc, proto_ff_s::E_PetSmelt_s, E_PetSmelt, MAX_PET_SMELT_NUM);
DECLARE_IDCREATE(PetSmeltDesc);
};
