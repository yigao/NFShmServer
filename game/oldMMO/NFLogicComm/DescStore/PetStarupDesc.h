#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_STARUP_NUM 40

class PetStarupDesc : public NFIDescStore
{
public:
	PetStarupDesc();
	virtual ~PetStarupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetStarup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetStarup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetStarup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetStarup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PetStarupDesc, proto_ff_s::E_PetStarup_s, E_PetStarup, MAX_PET_STARUP_NUM);
DECLARE_IDCREATE(PetStarupDesc);
};
