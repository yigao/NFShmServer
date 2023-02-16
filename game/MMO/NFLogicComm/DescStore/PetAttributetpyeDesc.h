#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_ATTRIBUTETPYE_NUM 40

class PetAttributetpyeDesc : public NFIDescStore
{
public:
	PetAttributetpyeDesc();
	virtual ~PetAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetAttributetpye_s* GetDesc(int id) const;
	proto_ff_s::E_PetAttributetpye_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetAttributetpye_s, E_PetAttributetpye, MAX_PET_ATTRIBUTETPYE_NUM);
DECLARE_IDCREATE(PetAttributetpyeDesc);
};
